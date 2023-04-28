#include "head.h"

//线性表
//线性表父类
class LinearList {
protected:
	typedef struct {
		float data[Length];
		int length_true; //存放线性表的长度
	}SqList;
};


//顺序表
class SequentialList :public LinearList
{
public:
	void CreateList(SqList*& L, float a[], int n) {	//建立线性表
		int i = 0, k = 0;
		L = (SqList*)malloc(sizeof(SqList)); //分配存放线性表的空间
		while (i < n)
		{
			L->data[k] = a[i];
			k++; i++;
		}
		L->length_true = k;
	}
};


//栈，一种只能在一端进行插入或删除操作的线性表
class Stack :public LinearList
{
protected:
	typedef struct {
		float data[Length];
		int top; //栈顶指针，存放栈顶元素在data数组中的下标
	}SqStack;
public:
	void InitStack(SqStack*& s)
	{
		s = (SqStack*)malloc(sizeof(SqStack));
		s->top = -1;   //栈顶指针置为-1
	}
	void DestroyStack(SqStack*& s)
	{
		free(s);
	}
	bool StackEmpty(SqStack* s) //判断栈是否为空
	{
		return (s->top == -1);
	}
	bool Push(SqStack*& s, float e) //入栈
	{
		if (s->top == Length - 1) {
			return false;
		}
		else {
			s->top = s->top + 1;
			s->data[s->top] = e;
			return true;
		}
	}

};
