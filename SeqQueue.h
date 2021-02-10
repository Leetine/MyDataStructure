#pragma once
#include<iostream>
using namespace std;
#define Maxsize 10	//���������10������ʵֻ����9��Ԫ��

typedef struct {
	int data[Maxsize];
	int front;
	int rear;
}SeqQueue;

//дһ��ѭ��˳�����
//1.��ʼ������ͷ��βָ��0
bool InitSeqQueue(SeqQueue &Q){	//����Ҫ��&
	Q.front = 0;
	Q.rear = 0;
	return true;
}

//2.�ж϶����Ƿ�Ϊ��
bool Empty(SeqQueue Q) {
	if (Q.front == Q.rear == NULL) {
		return true;
	}
	else
		return false;
}

//3.������г���
int GetLength(SeqQueue Q) {
	return (Q.rear + Maxsize - Q.front) % Maxsize;
}

//4.��ӣ�rear����
bool EnSeqQueue(SeqQueue &Q, int e) {
	if ((Q.rear + 1) % Maxsize == Q.front) {		//�����������ΪRear����һ���պõ�front?
		cout << "length: " << GetLength(Q) << endl;
		cout << "Queue is full." << endl;
		return false;
	}
	else {
		Q.data[Q.rear] = e;
		Q.rear = (Q.rear + 1) % Maxsize;
		cout << "EnSeqQueue " << e << " successful"<< endl;
		return true;
	}
}

//5.���ӣ�front���ƣ�����Ԫ�ش���x����
bool DeSeqQueue(SeqQueue &Q, int &x) {
	if (Q.front == Q.rear) {		//�ӿ�
		cout << "Queue is empty." << endl;
		return false;
	}
	else {
		x = Q.data[Q.front];
		Q.front= (Q.front + 1) % Maxsize;		//ָ����ƶ�����Ҫȡģ
		cout << "DeSeqQueue " << x << " successful" << endl;
		return true;
	}
}


//6.�����׵���β��ӡ
void Print(SeqQueue &Q) {
	for (int i = Q.front; i < Q.rear; i++) {	//ע����ֹ���±���ƣ�����0-maxsize
		cout << Q.data[i] << " ";
	}
	cout << endl;
	return;
}

//7.���Գ���
void testSeqQueue() {
	SeqQueue q;
	if (InitSeqQueue(q)) {
		for (int i = 1; i < 12; i++) {
			EnSeqQueue(q, i);
		}
		Print(q);
		int x;
		DeSeqQueue(q, x);
		DeSeqQueue(q, x);		
		Print(q);
		for (int i = 1; i < 11; i++) {
			DeSeqQueue(q, x);
		}
	}
	return;
}