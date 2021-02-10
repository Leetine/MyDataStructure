#pragma once
#include<iostream>
using namespace std;

typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct{
	LinkNode *front, *rear;
}LinkQueue;	//这个为啥上面不写名字

//1.初始化不带头结点的链式队列
void InitLinkQueue(LinkQueue &Q){		//参数是队列，单链表这里参数是节点。。
	Q.front = NULL;		//函数返回值何时用bool何时用void?
	Q.rear = NULL;
}

//2.判断是否空
bool Empty(LinkQueue Q) {
	if (Q.front == Q.rear == NULL) {
		return true;
	}
	else
		return false;
}

//3.入队，front指向首元素，每入队一次，rear就向后移一个
void EnQueue(LinkQueue &Q, int e) {
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));	//看好了这俩星号加在哪
	s->next = NULL;
	s->data = e;
	if (NULL == Q.front) {	//空队列的情况特殊处理
		cout << "enqueue the first node" << endl;
		Q.front = s;
		Q.rear = s;
		cout << e << " EnQueue successfelly" << endl;
	}
	else {
		Q.rear->next = s;		//新结点插入Rear之后
		Q.rear = s;				//指针后移，体会两者的区别
		cout << e << " EnQueue successfelly" << endl;
	}
}

//4.出队
void DeQueue(LinkQueue &Q, int &x) {
	if (NULL == Q.front) {
		return;
	}
	LinkNode *p = Q.front;
	x = p->data;
	Q.front = p->next;
	if (Q.rear == p) {		//如果是最后一个节点出队
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p);
	cout << x << " DeQueue successfelly" << endl;
}

//5.打印
void Print(LinkQueue Q) {
	if (Q.front != NULL) {
		LinkNode *p = Q.front;		//遍历时别动Front、rear
		while (p->next != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data << " ";		//最后一个也要输出
		cout << endl;
	}
}

//6.测试程序
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