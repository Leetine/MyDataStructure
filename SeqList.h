#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define InitSize 10
#define Elemtype int

//˳�����
typedef struct SeqList {
	Elemtype *data = NULL;
	int MaxSize; //�����Ͳ���Elemtype����
	int Length;
};

//˳���L����n��Ԫ�صĿռ䣬nС��InitSizeʱĬ�Ͽ���InitSize��Ԫ�صĴ�С
//�����ʼ��Ԫ��ֵ�����Ӧ����һ��
void InitSeqList(SeqList &L, int n) {
	if (n <= InitSize) {
		L.MaxSize = InitSize;
		L.data = (Elemtype*)malloc(sizeof(Elemtype)*L.MaxSize);
		L.Length = n;
	}
	else {
		L.MaxSize = n;
		L.Length = n;
		L.data = (Elemtype*)malloc(sizeof(Elemtype)*L.MaxSize);
	}
	srand(Elemtype(time(NULL)));
	for (int i = 0; i < L.Length; i++) {//ʣ�µĲ��ܣ����ֵ����
		L.data[i] = rand();
	}
	return;
}

//���ܴ�ӡ���麯����int[] double[] struct Door[] 
typedef void(*print_type)(void*);

void PrintAllSeqList(SeqList &L, int len, int singleelemsize, print_type print)
{
	printf("MaxSize:%d\n", L.MaxSize);//����û��&����
	printf("Length:%d\n", L.Length);
	char *start = (char*)L.data;
	for (int i = 0; i < L.Length; i++)
	{
		char *end = start + i * singleelemsize;
		print(end);
	}
	printf("\n---------\n");
	return;
}

//��ӡint
void printInt(void *data)
{
	int *temp = (int *)data;
	printf("%d ", *temp);
}
//��ӡdouble 
void printDouble(void *data)
{
	double *temp = (double *)data;
	printf("%lf ", *temp);
}


//��˳�����չָ����С�ռ�
void IncreaseSize(SeqList &L, int addsize) {
	Elemtype *p = L.data;

	L.data = (Elemtype*)malloc(sizeof(Elemtype)*(L.MaxSize + addsize));//����ռ��Ǹ�size,length����
	for (int i = 0; i < L.Length; i++) {
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + addsize;
	free(p);
	printf("addsize:%d\n", addsize);


}

//��λ��i�������e
void InsertSeqList(SeqList &L, int i, Elemtype e) {
	if (i<0 || i>L.Length) {
		printf("i<0 || i>L.Length\n");
		return;
	}
	if (L.Length == L.MaxSize) {		//�����жϷ��ź͸�ֵһ����Ҫ�����
		printf("��Ҫ����\n");
		IncreaseSize(L, 10);
	}
	int j = 0;
	for (j = L.Length + 1; j > i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[j] = e;
	L.Length++;
	return;
}

//ɾ��λ��i��Ԫ��
void DeleteSeqList(SeqList &L, int i) {
	if (i<0 || i>L.Length) {
		printf("i<0 || i>L.Length\n");
		return;
	}
	for (int j = i; j < L.Length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.Length--;
	return;
}

//ȡλ��i��Ԫ��ֵ
Elemtype GetElemVal(SeqList L, int i) {
	Elemtype e = L.data[i - 1];
	return e;
}

//ȡֵΪe��Ԫ�ص�λ��
Elemtype GetElemNum(SeqList L, Elemtype e) {
	for (int i = 0; i < L.Length; i++) {
		if (e == L.data[i]) {
			return i + 1;
		}
	}
	printf("û���ҵ�");
	return 0;
}

//���Ժ���
void TestSeqList() {
	SeqList seqlist;
	InitSeqList(seqlist, 8);
	PrintAllSeqList(seqlist, seqlist.Length, sizeof(seqlist.data[0]), printInt);
	IncreaseSize(seqlist, 3);
	PrintAllSeqList(seqlist, seqlist.Length, sizeof(seqlist.data[0]), printInt);
	InsertSeqList(seqlist, 3, 0);
	PrintAllSeqList(seqlist, seqlist.Length, sizeof(seqlist.data[0]), printInt);
	InsertSeqList(seqlist, 6, 1);
	PrintAllSeqList(seqlist, seqlist.Length, sizeof(seqlist.data[0]), printInt);
	InsertSeqList(seqlist, 10, 2);
	PrintAllSeqList(seqlist, seqlist.Length, sizeof(seqlist.data[0]), printInt);
	InsertSeqList(seqlist, 11, 3);
	PrintAllSeqList(seqlist, seqlist.Length, sizeof(seqlist.data[0]), printInt);
	IncreaseSize(seqlist, 3);		//�����ף�ֻ������һ�Σ������˾Ͳ���
	DeleteSeqList(seqlist, 10);
	PrintAllSeqList(seqlist, seqlist.Length, sizeof(seqlist.data[0]), printInt);
	printf("������Ԫ�أ�%d\n", GetElemVal(seqlist, 3));
	printf("�����ǣ�%d\n", GetElemNum(seqlist, 2));
}