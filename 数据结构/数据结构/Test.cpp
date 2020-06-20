#include <iostream>
#include <string>
#define MAXSIZE 20		//存储空间初始化分配量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

using namespace std;

typedef string ElemType;		//ElemType类型根据实际情况而定，这里假设为int类型

typedef struct  
{
	ElemType data[MAXSIZE];		//数组存储数据元素，最大值为MAXSIZE
	int length;
}SqList;

typedef int Status;		//Status是函数的类型，其值是函数结果状态代码，如OK等。

//----------------------------------------------------------------
//-------------------------顺序表部分-----------------------------
//----------------------------------------------------------------
//获取元素操作

//初始条件：顺序线性表L已经存在，1 <= i <= ListLength(L)
//操作结果：用e返回L中第i个数据元素的值
Status ListEmpty(const SqList &L)		//判断线性表是否为空，空则返回true，否则返回FALSE
{
	if (L.length == 0)
	{
		return TRUE;
	}

	return FALSE;
}

Status GetElem(const SqList &L, int i, ElemType &e)		//使用const引用，直接传入元数据，并限制修改，使用传统的传值会导致复制而浪费内存
{
	if (L.length == 0 || i<1 || i>L.length)
	{
		return ERROR;
	}

	e = L.data[i - 1];

	return OK;
}

int LocateElem(const SqList &L, const ElemType &e)
{
	for (int i = 0; i < L.length; ++i)
	{
		if (L.data[i] == e)
		{
			return i+1;
		}
	}

	return 0;
}

int ListLength(const SqList &L)
{
	return L.length;
}

Status ListInsert(SqList &L, int i, const ElemType &e)		//插入操作
{
	int k;

	if (L.length == MAXSIZE || i<1 || i>L.length + 1)
	{
		return ERROR;
	}
	
	if (i <= L.length)
	{
		for (k = L.length - 1; k >= i - 1; --k)
		{
			L.data[k + 1] = L.data[k];
		}
	}

	L.data[i - 1] = e;
	++L.length;
	
	return OK;
}

Status ListDelete(SqList &L, int i,ElemType &e)
{
	int k;

	if (L.length == 0)		//线性表为空
	{
		return ERROR;
	}

	if (i < 1 || i > L.length)
	{
		return ERROR;
	}

	e = L.data[i - 1];

	if (i < L.length)		//如果删除不是最后位置
	{
		for (k = i; k < L.length; ++k)		//将删除位置后继元素前移
		{
			L.data[k - 1] = L.data[k];
		}
	}

	--L.length;

	return OK;
}

void main()
{
	
}