#include "RPN.h"
#include "stack.h"
#include <stdlib.h>
#include<stdio.h>
SeqStack s;
int RPN(char *p){
	if (p == NULL)
		return 0;
	StackInit(&s);
	char str[20];
	int i = 0;
	int c = 0;
	int a = 0; 
	int b = 0;
	while (*p)//"12 3 4 + * 6 - 8 2 / +"
	{
		if ((*p) != '+' && (*p) != '-' && (*p) != '*' && (*p) != '/' && (*p) != ' ')
		{
			while ((*p) != ' ')
			{
				str[i++] = *p;
				p++;
			}
			str[i] = '\0';
			c = atoi(str);
			StackPush(&s,c);
			str[0] = '\0';
			i = 0;
		}
		else if ((*p)!=' ')
		{
			if (!StackEmpty(&s))
			{
				b = StackTop(&s);
				StackPop(&s);
				a = StackTop(&s);
				StackPop(&s);
				
            }
			switch (*p)
			{
			case '+':
				StackPush(&s, a + b);
				break;
			case '-':
				StackPush(&s, a - b);
				break;
			case '*':
				StackPush(&s, a * b);
				break;
			case '/':
				if (b!=0)
					StackPush(&s, (a / b));
				else
				{
					printf("perror\n");
					return -1;
				}
				break;
			default:
				break;
			}
			
		}
		p++;

	}
	b = StackTop(&s);
	printf("结果为:%d\n", b);
	return 0;

}