   #include "Http_Server.h"
   #include<stdio.h>
   #include<unistd.h>
   #include<string.h>
   #include<sys/socket.h>
   #include<arpa/inet.h>
   #include<errno.h>
   #include<netinet/in.h>
   #include<pthread.h>
   #include<sys/stat.h>
   #include<sys/types.h>
   #include<sys/sendfile.h>
   #include<fcntl.h>
   typedef struct sockaddr sockaddr;
   typedef struct sockaddr_in sockaddr_in;
   
     //a>从socket中读取出首行;
     //一次从socket中读取一行数据,
     //把数据放到buf缓冲区之中,如果读取失败,返回值就是-1
     //  \n \r\n \r
int ReadLine(int sock,char buf[],ssize_t size)
{
      //1>从socket中一次读取一个字符
	  char c='\0';
	  ssize_t i=0;//当前读的字符个数
	  //结束条件
	  //a>读到长度太长,达到了缓冲区长度的上限
	  //b>读到了\n(此处我们要兼容\r\n \r的情况,遇到了想办法转化成\n)
	  while(i<size-1&&c!='\n'){
	    ssize_t read_size = recv(sock,&c,1,0);//从内核中读数据,读完字符会被删掉
		if(read_size<=0){
		  return -1;
		}
		if(c=='\r'){
		 recv(sock,&c,1,MSG_PEEK);//MSG_PEEK从内核中读数据,读完字符不会被删掉,下一次去读,
		 //还是该字符
		 if(c=='\n'){
		    recv(sock,&c,1,0);
		    }
		 else{
		 c = '\n';
		 }
		}
		buf[i++]=c;
      }
	 buf[i] = '\0';
	 return i;//缓冲区中字符的个数
}


int Split(char input[],const char *split_char,char *output[],int output_size)
{
  char * pch;
  char *temp = NULL;//保存上一次切分的结果
  int i=0;
  pch = strtok_r(input,split_char,&temp);//线程安全版本
  while (pch != NULL)
  {
   if(i>=output_size){
     return i;
   }
   output[i++] = pch;
   pch = strtok_r(NULL,split_char,&temp);
  }
  return i;
}
  

  //b>解析首行,从首行中解析出url和method
int ParseFirstLine(char first_line[],char **url,char **method){
   //把首行按照空格进行字符串切分
   char *tok[10];
   //Split该函数的功能是按照空格进行字符串切分,
   //切分得到的每一部分,就放到tok数组中去
   //返回值,就是tok数组中元素的个数
   //最后一个参数10表示tok数组中最多能放的元素的个数.
  // printf("%s\n",first_line);
   int tok_size = Split(first_line," ",tok,10);
   if(tok_size!=3){
    printf("Split failed! tok_size = %d\n",tok_size);
    return -1;
   }
   *method = tok[0];
   *url = tok[1];
   printf("%s,%s\n",*method,*url);
   return 0;
}   
  
  
  
  //c>解析url,从url中解析url_path,query_string
int ParseQueryString(char *url,char **p_url_path,char **p_url_string)
{
  *p_url_path = url;
  char *p = url;
  for(;*p!='\0';++p){
    if(*p=='?'){
	 *p='\0';
	 *p_url_string = p+1;
	 return 0;
	}
  }
  *p_url_string = NULL;
  return 0;
}
   
   
   //d>处理header部分
int ParseHeader(int sock,int *content_length){
   //1>循环读取一行,看看是不是conten-length
   //2>如果是读取value不是直接丢弃
   //3>读到空行,循环结束
   char buf[SIZE] = {0};
   while(1){
    ssize_t read_size = ReadLine(sock,buf,sizeof(buf));
	if(read_size<=0){
	  return -1;
	}
	//当buf等于\n时,说明读到了空行,
    if(strcmp(buf,"\n")==0){
	  return 0;
	}
	const char *content_length_str = "content_length: ";
	if(content_length !=NULL && strncmp(buf,content_length_str,strlen(content_length_str))==0)
	{
	  *content_length = atoi(buf+strlen(content_length_str));
	}
   }
  
   return 0;
}
   
   
   
   //错误处理:直接返回404的HTTP响应
void Handler404(int sock){
  //构造一个完整的HTTp响应,状态码是404,body部分是一个404相关的错误页面
  const char *first_line = "HTTP/1.1 404 Not Found\n";
  const char *type_line = "Content-Type: text/html;charset=utf-8\n";
  const char *blank_line = "\n";
  const char *html = "<head><meta http-equiv=\"content-type\" content=\"text/html;charset=utf-8\"></head>"
                     "<h1>你的页面没找到哈!!!!</h1>";
  send (sock,first_line,strlen(first_line),0);
  send (sock,type_line,strlen(type_line),0);
  send (sock,blank_line,strlen(blank_line),0);
  send (sock,html,strlen(html),0);
  return ;
}  


void PrintfRequest(Request *req){
    printf("method:%s\n",req->method);
	printf("url_path:%s\n",req->url_path);
	printf("query_string:%s\n",req->query_string);
	printf("content_length:%s\n",req->Content_length);
    return ;
}


int IsDir(const char *file_path)
{
	
	struct stat st;
	int ret = stat(file_path,&st);//打开文件
	printf("%d\n",ret);
	if(ret<0){
		return 0;
	}
	if(S_ISDIR(st.st_mode)){
		return 1;
	}
}



ssize_t GetFileSize(const char *file_path){
	struct stat st;
	int ret = stat(file_path,&st);
	if(ret<0){
		//打开文件失败,文件不存在
		return 0;
	}
	return st.st_size;
}


int WriteStaticFile(int sock,const char *file_path){
	//打开文件
	//printf("4   %s\n",file_path);
    int fd = open(file_path,O_RDONLY);//文件描述符不够用或者文件不存在时就会打开失败
	//printf("%d\n",fd);
	if(fd<0){
		perror("open");
		return 404;
	}
	//把构造出来的HTTP响应写到socket中
	  //a>写入首行
	  const char *first_line = "HTTP/1.1 200 ok\n";
	  send(sock,first_line,strlen(first_line),0);
	  //b>写入header
	  const char *type_line = "Content-Type: text/html;charset=utf-8\n";
	  send(sock,type_line,strlen(type_line),0);
	  //c>写入空行
	  const char *blank_line = "\n";
	  send(sock,blank_line,strlen(blank_line),0);
	  //d>写入body(文件内容)
	    //ssize_t sendfile(int out_fd,int in_fd,off_t *offset,size_t count)
	    //int out_fd,输出参数----sock
		//int in_fd,输入参数----fd
		//off_t *offset,指向一个变量,保存的是相对于in_fd的偏移位置
		//size_t count拷贝的字节数,也就是文件的大小
	  sendfile(sock,fd,NULL,GetFileSize(file_path));
	//关闭文件
	 close(fd);
	 return 200;
}


void HandlerFilePath(const char*url_path,char file_path[])
{
	//a>给url_path加上前缀(HTTP服务器的根目录),防止用户输入/,我们就需要追加上文件
	//url_path ===> /demo.html
	//file_path ====>./wwwroot/旋转木马轮播图/demo.html
	//printf("1   %s\n",url_path);
	sprintf(file_path,"./wwwroot%s",url_path);
	if(file_path[strlen(file_path)-1]=='/'){
		strcat(file_path,"demo.html");
	}
	
	
	/*if(IsDir(file_path)){
	   strcat(file_path,"/demo.html");
	}
	*/
}
   
   
   //处理静态文件返回静态页面
int HanderStaticFile(int sock,Request *req)
{
   //1,根据url_path获取到文件在服务器上的真实路径
   //这里注意:HTTP服务器访问的根目录:用户可以任意指定存在的一个目录
   //url_path中访问的文件,都是以HTTP服务器的根目录为基准的,取相对路径
   char file_path[SIZE] = {0};
   HandlerFilePath(req->url_path,file_path);
   //printf("3   %s\n",file_path);
   //2,读取文件,把文件的内容直接写到socket之中
   int err_code = WriteStaticFile(sock,file_path);
   return err_code;
}


int HandlerCGIFather(int new_sock,int father_read,int father_write,Request *req,int child_pid)
{
  if(strcasecmp(req->method,"POST")==0){
	  int i=0;
	  char c='\0';
	  for(;i< req->Content_length;i++){
		  read(new_sock,&c,1);
		  write(father_write,&c,1);
	  }
  }
  //构造HTTP响应
  const char *first_line = "HTTP/1.1 200 OK\n";
  send(new_sock,first_line,strlen(first_line),0);
  const char *type_line = "Content-Type: text/html;charset=utf-8\n";
  send(new_sock,type_line,strlen(type_line),0);
  const char * blank_line = "\n";
  send(new_sock,blank_line,strlen(blank_line),0);
  //循环的从管道中读取数据写到socket
  char c='\0';
  while(read(father_read,&c,1)>0){
	  send(new_sock,&c,1,0);
	}
	//回收子进程资源
  wait(child_pid,NULL,0);
  return 200;	
}


int HandlerCGIChild(int child_read,int child_write,Request* req){
	//设置环境变量
	  //a>METHOD
	char method_env[SIZE] = {0};
	sprintf(method_env,"REQUEST_METHOD=%s",req->method);
	putenv(method_env);
	  //b>QUERY_STRING
	if(strcasecmp(req->method,"GET")==0){
		char query_string_env[SIZE] = {0};
		sprintf(query_string_env,"QUERY_STRING=%s",req->query_string);
		putenv(query_string_env);
	
	}else{
	  //c>CONTENT_LENGTH
	   char Content_length_env[SIZE] = {0};
	   sprintf(Content_length_env,"CONTENT_LENGTH=%d",req->Content_length);
	   putenv(Content_length_env);
	  
	}
	//把标准输入输出重定向到管道中
	dup2(child_read,0);
	dup2(child_write,1);
	//对子进程进行程序替换
	char file_path[SIZE] = {0};
	HandlerFilePath(req->url_path,file_path);
	execl(file_path,file_path,NULL);
	exit(1);
  return 200;
}


int HandlerCGI(int new_sock,Request *req)
{
	int err_code = 200;
    //1>创建一对匿名管道
	int fd1[2],fd2[2];
	int ret = pipe(fd1);
	if(ret<0){
		return 404;
	}
	ret = pipe(fd2);
	if(ret<0){
		close(fd1[0]);
		close(fd1[1]);
		return 404;
	}
	int father_read  = fd1[0];
	int child_write  = fd1[1];
	int child_read   = fd2[0];
	int father_write = fd2[1];
	//2>创建子进程
	pid_t temp = fork();
	//3>父子进程各自执行不同的逻辑
	if(temp>0){
		//父进程;
		close(child_read);
		close(child_write);
		err_code = HandlerCGIFather(new_sock,father_read,father_write,req,temp);
	}
	else if(temp==0){
		//子进程;
		close(father_read);
		close(father_write);
		err_code = HandlerCGIChild(child_read,child_write,req);
	}
	else{
		perror("fork");
		err_code = 404;
		goto END;
	}
	//4>收尾工作和错误处理
	END:
	   close(fd1[0]);
	   close(fd1[1]);
	   close(fd2[0]);
	   close(fd2[1]);
	   return err_code;
}

   
   
   //负责处理客户端的请求
HandlerRequest(int64_t new_sock)
{
   int err_code = 200;
   
   //1>读取并解析请求(反序列化)
   Request req;
   //结构体初始化全0;
   memset(&req,0,sizeof(req));
      //a>从socket中读取出首行;
	if(ReadLine(new_sock,req.first_line,sizeof(req.first_line))<0)
	  {
	    //处理失败
		err_code = 404;
		goto END;
	  }
	  //b>解析首行,从首行中解析出url和method
	if(ParseFirstLine(req.first_line,&req.url,&req.method))
	{
	  //处理失败
	    err_code = 404;
		goto END;
	
	}
	  //c>解析url,从url中解析url_path,query_string
	if(ParseQueryString(req.url,&req.url_path,&req.query_string))
	{
	  //处理失败
	  err_code = 404;
	  goto END;
	}
	  //d>处理header部分
	if(ParseHeader(new_sock,&req.Content_length))
	{
	 //失败返回
	 err_code = 404;
	 goto END;
	}
	
	//2>静态/动态方式生成页面 ,把生成结果写回到客户端.
     if(strcasecmp(req.method,"GET")==0&&req.query_string==NULL)
	 {
	   //a>如果请求是GET请求,并且没有Query_string,那么就返回静态页面
	  err_code =  HanderStaticFile(new_sock,&req);
	 }else if(strcasecmp(req.method,"GET")==0&&req.query_string!=NULL)
	 {
	   //b>如果请求时GET请求,并且有Query_string,那么就返回动态页面
	  err_code =   HandlerCGI(new_sock,&req);
	 
	 }else if(strcasecmp(req.method,"POST")==0)
	 {
	    //c>如果请求是POST请求(没有Query_stinrg所以一定是带参数的,
		//参数通过body来传递给服务器),那么也返回动态页面
	   err_code =   HandlerCGI(new_sock,&req);	 
	}else
	{
	 //错误处理
	 err_code = 404;
	 goto END;
	}
	 //错误处理:直接返回404的HTTP响应
	END:
	 if(err_code!=200)
	 {
	   Handler404(new_sock);
	 }
	 close(new_sock);
	 return;
}
   
   
   
   //线程入口函数,
void * ThreadEntry(void*arg)
{
    int64_t new_sock = (int64_t)arg; 
	//负责处理客户端的请求,此处使用HandlerRequest(),函数完成具体的处理请求过程,这个过程
	//单独出来是为---解耦合--一旦需要把服务器改成多进程或者多路复用等形式,就比较方便
	HandlerRequest(new_sock);
	return NULL;
}
   
   
   //服务器启动
void HttpServerStart(const char *ip,short port)
{
    int listen_sock = socket(AF_INET,SOCK_STREAM,0);
	if(listen_sock<0){
	  perror("sock");
	  return;
	}   
    sockaddr_in server;
	server.sin_family  = AF_INET;
	server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);
    //绑定服务器
    int ret = bind(listen_sock,(sockaddr*)&server,sizeof(server));
    if(ret<0){
	 perror("bind");
	 return ;
	}
	ret = listen(listen_sock,5);
	if(ret<0)
	{
	  perror("listen");
	  return;
	}
	printf("srevrInit ok!\n");
	while(1){
		//对端的ip和端口号
	  sockaddr_in client;
	  socklen_t len = sizeof(client);
      int64_t new_sock = accept(listen_sock,(sockaddr*)&client,&len);
	  if(new_sock<0){
	   perror("accept");
	   continue;
	   }
	  //对new_sock进行读写,使用多线程方式实现多连接TCP服务器
	  pthread_t tid;
	  //创建线程
	  pthread_create(&tid,NULL,ThreadEntry,(void*)new_sock);
	  //线程回收
	  pthread_detach(tid);
	}
}
   
   
   
int main(int argc,char *argv[])
{
    if(argc!=3)
	  {
	  printf("Usage ./http_server [ip] [port]\n");
	  return 1;
	  }
    HttpServerStart(argv[1],atoi(argv[2]));
    return 0;
}