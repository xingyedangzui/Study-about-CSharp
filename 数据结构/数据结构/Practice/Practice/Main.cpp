#include <iostream>
using namespace std;

#define InitSize 100
typedef int ElemType;

typedef struct  
{
	ElemType *data;
	int MaxSize, length;
}SeqList;

int ListInsert(SeqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1)
	{
		return -1;
	}
	if (L.length >= L.MaxSize)
	{
		return 0;
	}
	for (int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}

	L.data[i - 1] = e;
	L.length++;
	return 1;
}

void main()
{
	ElemType a[10] = { 1 };

	SeqList *b = new SeqList();
	b->data = a;
	b->length = 1;

	bool c  = ListInsert( *b, 5, 29);

	if (c)
	{
		cout << "成功" << endl;
	}
	else if (c == -1)
	{
		cout << "位置错误" << endl;
	}
	else
	{
		cout << "剩余空间不足" << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << b->data[i] << endl;
	}
}