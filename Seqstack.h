#pragma once
#define Maxsize 10
#include<iostream>
using namespace std;

typedef struct{
	int data[Maxsize];		//��̬������ջ��Ԫ��
	int top;				//ջ��ָ��
	int length;
}Seqstack;

//��ʼ��ջ
void InitStack(Seqstack &S) {
	S.top = -1;		//�����ø�����Ԫ�ظ�ֵ��
	//����д���ǳ�ʼ��ָ��ջ��Ԫ�ض�����ջ�׵ĺ�һ��Ԫ��
	S.length = 0;	
}

//�ж�ջ��
bool Empty(Seqstack S) {
	if (-1 == S.top) {
		return true;
	}
	else
		return false;
}

//��ջ��ջ�����ķ���ֵ����bool���ͣ���Int���Ͳ��
//��ջ
bool Push(Seqstack &S,int e) {
	if (Maxsize - 1 == S.top) {	//����top�ﲻ��maxsize!
		return false;
	}
	else {
		S.top++;
		S.data[S.top] = e;
		S.length++;
		return true;
	}
}

//��ջ,��ջ��Ԫ�ظ�ֵ���ڴ��еı���x
bool Pop(Seqstack &S, int &x) {
	if (-1 == S.top) {
		return false;
	}
	else {
		x = S.data[S.top];
		S.top--;
		S.length--;		//���ݻ��������ڴ��У�ֻ���߼���ɾ����
		return true;
	}
}

//��ջ�׵�ջ����ӡ
void Print(Seqstack &S) {
	for (int i = 0; i < S.length; i++) {
		cout << S.data[i] << " ";
	}
	return;
}

//���Գ���
void TestSeqStack() {
	Seqstack S;		//ϵͳ�����ڴ�
	InitStack(S);
	Push(S, 10);
	Push(S, 20);
	Push(S, 30);
	Print(S);
	int topelem;
	Pop(S, topelem);
	cout << "topelem" << topelem << endl;
	Print(S);	//�������н������Զ������ڴ�
}

