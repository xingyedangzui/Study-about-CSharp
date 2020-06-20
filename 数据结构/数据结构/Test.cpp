#include <iostream>
#include <string>
#define MAXSIZE 20		//�洢�ռ��ʼ��������
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

using namespace std;

typedef string ElemType;		//ElemType���͸���ʵ������������������Ϊint����

typedef struct  
{
	ElemType data[MAXSIZE];		//����洢����Ԫ�أ����ֵΪMAXSIZE
	int length;
}SqList;

typedef int Status;		//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK�ȡ�

//----------------------------------------------------------------
//-------------------------˳�����-----------------------------
//----------------------------------------------------------------
//��ȡԪ�ز���

//��ʼ������˳�����Ա�L�Ѿ����ڣ�1 <= i <= ListLength(L)
//�����������e����L�е�i������Ԫ�ص�ֵ
Status ListEmpty(const SqList &L)		//�ж����Ա��Ƿ�Ϊ�գ����򷵻�true�����򷵻�FALSE
{
	if (L.length == 0)
	{
		return TRUE;
	}

	return FALSE;
}

Status GetElem(const SqList &L, int i, ElemType &e)		//ʹ��const���ã�ֱ�Ӵ���Ԫ���ݣ��������޸ģ�ʹ�ô�ͳ�Ĵ�ֵ�ᵼ�¸��ƶ��˷��ڴ�
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

Status ListInsert(SqList &L, int i, const ElemType &e)		//�������
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

	if (L.length == 0)		//���Ա�Ϊ��
	{
		return ERROR;
	}

	if (i < 1 || i > L.length)
	{
		return ERROR;
	}

	e = L.data[i - 1];

	if (i < L.length)		//���ɾ���������λ��
	{
		for (k = i; k < L.length; ++k)		//��ɾ��λ�ú��Ԫ��ǰ��
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