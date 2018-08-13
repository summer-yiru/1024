#pragma once
#define SIZE 10240
//保存HTTP协议请求对象
typedef struct Request{
  char first_line[SIZE]; 
  char *method;
  char *url;
  //还得把url区分开
  //https://www.baidu.com/index.html?query=鲜花
  char *url_path;//index.html
  char *query_string;//query=鲜花
  //接下来是header部分,如果要完整的解析下来,此处需要使用二叉搜索树或者hash表
  //这里我们保留一个Conten-Length
  int Content_length;
}Request;