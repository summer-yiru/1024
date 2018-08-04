#include "MatchBrackets.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
SeqStack s;
int main(){
	int ret = 0;
	//char arr[] = "(())abc{[(])}";
	//char arr[] = "(()))abc{[]}";
	char arr[] = "(()()abc{[]}";
	//char arr[] = "(())abc{[]()}";
	//char arr[] = "(())abc{[]}";
	ret=MatchBrackets(arr);
	if (ret == 1)printf("匹配成功\n");
	else if(ret == 0)printf("匹配不成功,括号次序排列\n");
	else if(ret==-1)printf("匹配不成功,左括号多于右括号\n");
	else{ printf("匹配不成功,右括号多于左括号\n"); }
	system("pause");
	return 0;
}