#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define InitSize 10
#define Elemtype int

//顺序表定义
typedef struct SeqList {
	Elemtype *data = NULL;
	int MaxSize; //是整型不是Elemtype类型
	int Length;
};

//顺序表L开辟n个元素的空间，n小于InitSize时默认开辟InitSize个元素的大小
//随机初始化元素值，与对应类型一致
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
	for (int i = 0; i < L.Length; i++) {//剩下的不管，随机值即可
		L.data[i] = rand();
	}
	return;
}

//万能打印数组函数：int[] double[] struct Door[] 
typedef void(*print_type)(void*);

void PrintAllSeqList(SeqList &L, int len, int singleelemsize, print_type print)
{
	printf("MaxSize:%d\n", L.MaxSize);//这里没有&符号
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

//打印int
void printInt(void *data)
{
	int *temp = (int *)data;
	printf("%d ", *temp);
}
//打印double 
void printDouble(void *data)
{
	double *temp = (double *)data;
	printf("%lf ", *temp);
}


//对顺序表扩展指定大小空间
void IncreaseSize(SeqList &L, int addsize) {
	Elemtype *p = L.data;

	L.data = (Elemtype*)malloc(sizeof(Elemtype)*(L.MaxSize + addsize));//分配空间是给size,length不变
	for (int i = 0; i < L.Length; i++) {
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + addsize;
	free(p);
	printf("addsize:%d\n", addsize);


}

//在位序i后面插入e
void InsertSeqList(SeqList &L, int i, Elemtype e) {
	if (i<0 || i>L.Length) {
		printf("i<0 || i>L.Length\n");
		return;
	}
	if (L.Length == L.MaxSize) {		//这里判断符号和赋值一定不要搞混了
		printf("需要扩容\n");
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

//删除位序i的元素
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

//取位序i的元素值
Elemtype GetElemVal(SeqList L, int i) {
	Elemtype e = L.data[i - 1];
	return e;
}

//取值为e的元素的位序
Elemtype GetElemNum(SeqList L, Elemtype e) {
	for (int i = 0; i < L.Length; i++) {
		if (e == L.data[i]) {
			return i + 1;
		}
	}
	printf("没有找到");
	return 0;
}

//测试函数
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
	IncreaseSize(seqlist, 3);		//就离谱，只能扩容一次，再满了就不行
	DeleteSeqList(seqlist, 10);
	PrintAllSeqList(seqlist, seqlist.Length, sizeof(seqlist.data[0]), printInt);
	printf("第三个元素：%d\n", GetElemVal(seqlist, 3));
	printf("次序是：%d\n", GetElemNum(seqlist, 2));
}