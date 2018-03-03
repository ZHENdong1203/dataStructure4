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
}//�����ջ
Status GetTop(SqStack S, SElemType &e)
{
	if (S.top == S.base)
	{
		return ERROR;
	}
	e = *(S.top - 1);
	return e;
}//���ջ��Ԫ��
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
}//����ջ��Ԫ��
Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base)
	{
		return ERROR;
	}
	e = *--S.top;
	return e;
}//ɾ��ջ��Ԫ��
Status StackTraverse(SqStack S)
{
	if (S.base == NULL)
		return ERROR;
	if (S.top == S.base)
		printf("ջ��û��Ԫ��\n");
	SElemType *p;
	p = S.top;
	while (p > S.base)
	{
		p--;
		printf("%d ", *p);
	}
	printf("\n");
	return OK;
}//����ջ
int main()
{
	SqStack S;
	int i,e;
	InitStack(S);
	printf("��ջ�в���1-5�����\n");
	for (i = 1; i <= 5; i++)
	{
		Push(S, i);
	}
	printf("��ʱջ��Ԫ��Ϊ:\n");
	StackTraverse(S);
	printf("ջ��Ԫ��Ϊ:");
	printf("%d\n", GetTop(S, e));
	printf("ɾ��ջ��Ԫ��\n");
	printf("ɾ����Ԫ��Ϊ:");
	printf("%d\n",Pop(S, e));
	printf("ɾ����ջ��Ԫ��Ϊ:\n");
	StackTraverse(S);
	system("pause");
	return 0;
}