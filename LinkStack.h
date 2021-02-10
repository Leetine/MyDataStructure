#pragma once
#include<iostream>
using namespace std;

typedef struct Linknode {
	int data;
	struct Linknode *next;
}*LinkStack;		

//1.初始化
bool initList(LinkStack &S) {	//引用L是为了改变L的值，而别名L指向的是链表的头结点的地址，即要改变头结点的地址
								//但是一般改链都是对头结点之后的结点进行操作，所以头结点的地址一直没变
								//故去掉&后函数依旧可以正常执行
								//之所以会加&，是以防没有链表是没有头结点的那种情况，因为可能会对第一个结点操作，那L的地址就会改变。
	S = (Linknode*)malloc(sizeof(Linknode));
	if (NULL == S)
	{
		cout << "allocate fail" << endl;	//谨防分配空间失败的情况
		return false;
	}
	else {
		S->next = NULL;
		return true;
	}
}

//2.测试链栈是否为空
bool empty(LinkStack S) {		//L指向的是链表的头结点的地址,可以用->运算符来访问结构体成员
	if (S->next == NULL) {
		return true;
	}
	else
		return false;
}

//3.求链栈长度
int Getlength(LinkStack S) {
	Linknode *p = S;
	int len = 0;
	while (p->next != NULL) {
		p = p->next;		//这里一定别忘了指针向后移动
		len++;
	}
	cout << "length:" << len << endl;
	return len;
}

//4.进栈
Linknode* Push(LinkStack &S,int e) {
	Linknode* p;
	p = (Linknode*)malloc(sizeof(Linknode));
	p->data = e;
	p->next = S->next;
	S->next = p;
	return S;
}

//5.出栈,返回栈顶元素
int Pop(LinkStack &S, int &x) {
	if (S->next == NULL) {		
		return 0;
	}
	Linknode* p = S->next;
	x = p->data;
	S->next = p->next;
	free(p);
	return x;
}

//6.打印
int PrintStack(LinkStack S) {
	if (NULL == S->next)
	{
		cout << "empty" << endl;
		return 0;
	}
	Linknode* p = S->next;
	while (p->next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << " " << endl;	//p指向尾节点时会跳过循环，这里应该输出
	return 0;
}

//7.测试程序
void TestLinkStack() {
	LinkStack S;
	if (initList(S)) {
		Push(S, 10);
		Push(S, 20);
		Push(S, 30);
		Push(S, 40);
		PrintStack(S);
		int topelem=0;
		cout << "topelem" << Pop(S, topelem) << endl;
		PrintStack(S);
		Pop(S, topelem);
		Pop(S, topelem);
		Pop(S, topelem);
		PrintStack(S);
	}
	return;
}
