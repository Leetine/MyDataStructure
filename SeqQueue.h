#pragma once
#include<iostream>
using namespace std;
#define Maxsize 10	//最大容量是10，但其实只能有9个元素

typedef struct {
	int data[Maxsize];
	int front;
	int rear;
}SeqQueue;

//写一个循环顺序队列
//1.初始化，队头队尾指向0
bool InitSeqQueue(SeqQueue &Q){	//这里要加&
	Q.front = 0;
	Q.rear = 0;
	return true;
}

//2.判断队列是否为空
bool Empty(SeqQueue Q) {
	if (Q.front == Q.rear == NULL) {
		return true;
	}
	else
		return false;
}

//3.计算队列长度
int GetLength(SeqQueue Q) {
	return (Q.rear + Maxsize - Q.front) % Maxsize;
}

//4.入队，rear后移
bool EnSeqQueue(SeqQueue &Q, int e) {
	if ((Q.rear + 1) % Maxsize == Q.front) {		//队满，可理解为Rear后移一个刚好到front?
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

//5.出队，front后移，队首元素带给x变量
bool DeSeqQueue(SeqQueue &Q, int &x) {
	if (Q.front == Q.rear) {		//队空
		cout << "Queue is empty." << endl;
		return false;
	}
	else {
		x = Q.data[Q.front];
		Q.front= (Q.front + 1) % Maxsize;		//指针的移动都需要取模
		cout << "DeSeqQueue " << x << " successful" << endl;
		return true;
	}
}


//6.按队首到队尾打印
void Print(SeqQueue &Q) {
	for (int i = Q.front; i < Q.rear; i++) {	//注意起止由下标控制，不是0-maxsize
		cout << Q.data[i] << " ";
	}
	cout << endl;
	return;
}

//7.测试程序
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