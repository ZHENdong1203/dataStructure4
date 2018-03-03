#include<stdio.h>  
#include<stdlib.h>     
#define  OK    1  
#define  ERROR 0  
#define  OVERFLOW   -2  
#define  STACK_INIT_SIZE  100  
#define  STACKINCREMENT    10  
typedef  int  SElemType;
typedef  int  Status;
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!S.base)
	{
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}//构造空栈
Status GetTop(SqStack S, SElemType &e)
{
	if (S.top == S.base)
	{
		return ERROR;
	}
	e = *(S.top - 1);
	return e;
}//获得栈顶元素
Status Push(SqStack &S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)
		{
			exit(OVERFLOW);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}//插入栈顶元素
Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base)
	{
		return ERROR;
	}
	e = *--S.top;
	return e;
}//删除栈顶元素
Status StackTraverse(SqStack S)
{
	if (S.base == NULL)
		return ERROR;
	if (S.top == S.base)
		printf("栈中没有元素\n");
	SElemType *p;
	p = S.top;
	while (p > S.base)
	{
		p--;
		printf("%d ", *p);
	}
	printf("\n");
	return OK;
}//遍历栈
int main()
{
	SqStack S;
	int i,e;
	InitStack(S);
	printf("在栈中插入1-5五个数\n");
	for (i = 1; i <= 5; i++)
	{
		Push(S, i);
	}
	printf("此时栈中元素为:\n");
	StackTraverse(S);
	printf("栈顶元素为:");
	printf("%d\n", GetTop(S, e));
	printf("删除栈顶元素\n");
	printf("删除的元素为:");
	printf("%d\n",Pop(S, e));
	printf("删除后栈中元素为:\n");
	StackTraverse(S);
	system("pause");
	return 0;
}