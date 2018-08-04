#include "MatchBrackets.h"
#include "stack.h"
#include <string.h>
SeqStack S;
int MatchBrackets(char *p){
	if (p == NULL)
		return -1;
	StackInit(&S);
	size_t i = 0;
	for ( i = 0; i<strlen(p); i++)
	{
		
			switch (p[i])
			{
			case '(':
			case '{':
			case '[':
				StackPush(&S, p[i]);//若是左括号，则进行入栈操作
				break;
				//若是右括号，则进行出栈操作，若出栈元素不是与输入相对应的左括号，则字符串括号中不匹配
			case ')':
			case '}':
			case ']':
				if (!StackEmpty(&S))
               {
					char ret = StackTop(&S);
					if ((ret == '(' && (p[i]) == ')') || (ret == '{' && (p[i]) == '}') || (ret == '[' && (p[i]) == ']'))
						StackPop(&S);
					else
						return 0;
				}
				else
					return -2;
				break;
			default:
				break;
			}
		
			
	}
	
	if (StackEmpty(&S)){ return 1; }//匹配成功
	else { return -1; }//左括号大于右括号
}