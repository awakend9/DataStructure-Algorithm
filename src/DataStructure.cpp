#include "head.h"

//���Ա�
//���Ա���
class LinearList {
protected:
	typedef struct {
		float data[Length];
		int length_true; //������Ա�ĳ���
	}SqList;
};


//˳���
class SequentialList :public LinearList
{
public:
	void CreateList(SqList*& L, float a[], int n) {	//�������Ա�
		int i = 0, k = 0;
		L = (SqList*)malloc(sizeof(SqList)); //���������Ա�Ŀռ�
		while (i < n)
		{
			L->data[k] = a[i];
			k++; i++;
		}
		L->length_true = k;
	}
};


//ջ��һ��ֻ����һ�˽��в����ɾ�����������Ա�
class Stack :public LinearList
{
protected:
	typedef struct {
		float data[Length];
		int top; //ջ��ָ�룬���ջ��Ԫ����data�����е��±�
	}SqStack;
public:
	void InitStack(SqStack*& s)
	{
		s = (SqStack*)malloc(sizeof(SqStack));
		s->top = -1;   //ջ��ָ����Ϊ-1
	}
	void DestroyStack(SqStack*& s)
	{
		free(s);
	}
	bool StackEmpty(SqStack* s) //�ж�ջ�Ƿ�Ϊ��
	{
		return (s->top == -1);
	}
	bool Push(SqStack*& s, float e) //��ջ
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
