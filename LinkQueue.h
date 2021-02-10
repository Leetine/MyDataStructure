#pragma once
#include<iostream>
using namespace std;

typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct{
	LinkNode *front, *rear;
}LinkQueue;	//���Ϊɶ���治д����

//1.��ʼ������ͷ������ʽ����
void InitLinkQueue(LinkQueue &Q){		//�����Ƕ��У���������������ǽڵ㡣��
	Q.front = NULL;		//��������ֵ��ʱ��bool��ʱ��void?
	Q.rear = NULL;
}

//2.�ж��Ƿ��
bool Empty(LinkQueue Q) {
	if (Q.front == Q.rear == NULL) {
		return true;
	}
	else
		return false;
}

//3.��ӣ�frontָ����Ԫ�أ�ÿ���һ�Σ�rear�������һ��
void EnQueue(LinkQueue &Q, int e) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));	//�����������Ǻż�����
	s->next = NULL;
	s->data = e;
	if (NULL == Q.front) {	//�ն��е�������⴦��
		cout << "enqueue the first node" << endl;
		Q.front = s;
		Q.rear = s;
		cout << e << " EnQueue successfelly" << endl;
	}
	else {
		Q.rear->next = s;		//�½�����Rear֮��
		Q.rear = s;				//ָ����ƣ�������ߵ�����
		cout << e << " EnQueue successfelly" << endl;
	}
}

//4.����
void DeQueue(LinkQueue &Q, int &x) {
	if (NULL == Q.front) {
		return;
	}
	LinkNode *p = Q.front;
	x = p->data;
	Q.front = p->next;
	if (Q.rear == p) {		//��������һ���ڵ����
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);
	cout << x << " DeQueue successfelly" << endl;
}

//5.��ӡ
void Print(LinkQueue Q) {
	if (Q.front != NULL) {
		LinkNode *p = Q.front;		//����ʱ��Front��rear
		while (p->next != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data << " ";		//���һ��ҲҪ���
		cout << endl;
	}
}

//6.���Գ���
void testLinkQueue() {
	LinkQueue Q;
	InitLinkQueue(Q);
	int i;
	for (i = 0; i < 6; i++)
	{
		EnQueue(Q, i);
	}
	Print(Q);
	int x;
	DeQueue(Q, x);
	DeQueue(Q, x);
	Print(Q);
	return;
}