#pragma once
#include<iostream>
using namespace std;
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode,*LinkList;		//LinkList是指针，(*LinkList)就是个LNode型的结构体了,可以用点运算符访问该结构体成员

//1.初始化
bool initList(LinkList &L) {	//引用L是为了改变L的值，而别名L指向的是链表的头结点的地址，即要改变头结点的地址
								//但是一般改链都是对头结点之后的结点进行操作，所以头结点的地址一直没变
								//故去掉&后函数依旧可以正常执行
								//之所以会加&，是以防没有链表是没有头结点的那种情况，因为可能会对第一个结点操作，那L的地址就会改变。
	L = (LNode*)malloc(sizeof(LNode));
	if (NULL == L)
	{
		cout << "allocate fail" << endl;	//谨防分配空间失败的情况
		return false;
	}
	else {
		L->next = NULL;
		return true;
	}
}

//2.测试单链表是否为空
bool empty(LinkList L) {		//L指向的是链表的头结点的地址,可以用->运算符来访问结构体成员
	if (L->next == NULL) {
		return true;
	}
	else
		return false;
}

//3.按位查找
LNode* GetbyOrder(LinkList L, int i) {
	if (i < 0)	//i从1开始
		return NULL;
	LNode *p = L;
	int j = 0;
	while(p!=NULL&&j<i) {
		p = p->next;
		j++;
	}
	return p;	//p指向第i个元素
}

//4.按值查找
LNode* GetbyValue(LinkList L, int e) {
	LNode *p = L->next;
	int j = 1;
	while (p!=NULL&&p->data != e) {	//为空的时候就没数据了，到末尾了，如果不判断NULL是取不到data的
		p = p->next;
		j++;
	}
	cout << "order:" << j << " value:" << p->data << endl;
	return p;
}

//5.指定元素p后插入元素e
bool InsertNextNode(LNode *p, int e) {		//参数列表不需要加LinkList &L吗
	if (NULL == p) {
		cout << "还不能在尾节点后插入" << endl;
		return false;
	}
	LNode* temp = (LNode*)malloc(sizeof(LNode));
	if (NULL == p)
	{
		cout << "allocate fail" << endl;	//谨防分配空间失败的情况
		return false;
	}
	temp->data = e;
	temp->next = p->next;
	p->next = temp;
	return true;
}

//6.指定位序i前插入元素e：找到第i-1个元素，在第i-1个元素后插入新元素e
bool InsertElem(LinkList &L, int i, int e) {
	LNode *p = GetbyOrder(L, i - 1);
	InsertNextNode(p, e);
	return true;
}

//7.指定元素p前插入元素e:指定元素p后插入元素p本身的数据，修改原节点数据为e
bool InsertPreNode(LNode *p, int e) {
	InsertNextNode(p, p->data);
	p->data = e;
	return true;
}

//8.指定节点p前插入节点q,将一个节点加入到一个链表中
bool InsertPreNode1(LNode *p, LNode *q) {
	if (p == NULL || q == NULL) {
		cout << "节点为空" << endl;
		return false;
	}
	q->next = p->next;
	p->next = q;
	int temp = p->data;
	p->data = q->data;
	q->data = temp;
	return true;
}//代码块注释快捷键ctrlK+ctrlC/ctrlU

//9.删除指定节点p:和后继节点交换数据，再释放掉下一个元素。吃了你的肉再把你抛弃。
bool DeleteNode(LNode *p) {
	if (p == NULL) {
		cout << "待删节点为空"<<endl;
		return false;
	}
	LNode *q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	cout << "delete..."<<endl;
	return true;
}

//10.求单链表长度
int Getlength(LinkList L) {
	LNode *p = L;
	int len = 0;
	while (p->next != NULL) {
		p = p->next;		//这里一定别忘了指针向后移动
		len++;
	}
	cout << "length:" << len << endl;
	return len;
}

//11.头插法建立单链表
LNode* HeadInsert(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;	  //初始化链表后指针置空，习惯
	int elem = 0;
	LNode* p;
	cin >> elem;
	while (elem != -1) {		
		p = (LNode*)malloc(sizeof(LNode));
		p->data = elem;
		p->next = L->next;
		L->next = p;
		cin >> elem;	//注意两次交互输入
	}
	return L;	//别忘了返回
}

//12.尾插法建立单链表，易错
LNode* TailInsert(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;	  //初始化链表后指针置空，习惯
	LNode *i = L, *j = L;
	int elem = 0;
	cin >> elem;
	while (elem != -1) {
		j = (LNode*)malloc(sizeof(LNode));
		j->data = elem;
		i->next = j;	//在i结点之后插入j节点
		i = i->next;	//保持i和j指向一致
		cin >> elem;
	}
	i->next = NULL;	//尾节点指针域置空，怎么老想写成 i = NULL;
	return L;	//别忘了返回
}

//13.单链表原地逆置
LNode* ReverseList(LinkList &L) {
	if (L == NULL || L->next == NULL) {
		return L;
	}
	LNode*p;
	LNode*q;
	p = L->next;
	L->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		q->next = L->next;
		L->next = q;
	}
	return L;
}

//14.单链表打印
void PrintList(LinkList L) {
	if (NULL==L)
	{
		return;
	}
	LNode* p = L->next;
	while (p->next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << " " << endl;	//p指向尾节点时会跳过循环，这里应该输出
	return;
}

//15.销毁链表
void DestoryList(LinkList L)
{
	if (NULL == L)
	{
		return;
	}
	LNode* pCurrent = L;
	while (pCurrent != NULL)
	{
		struct LNode* pNext = pCurrent->next;		
		free(pCurrent);	//注意，先释放空间，再把野指针指向下一个元素，和删除元素不同
		pCurrent = pNext;		
	}
	return;
}

void testLinkList() {
	LinkList L;
	if (initList(L)) {
		L = HeadInsert(L);		
		PrintList(L);		
		Getlength(L);
		InsertNextNode(GetbyValue(L, 10), 99);
		PrintList(L);
		InsertElem(L, 5, 88);
		PrintList(L);
		InsertPreNode(GetbyOrder(L, 4), 77);
		PrintList(L);
		DeleteNode(GetbyValue(L, 99));
		DeleteNode(GetbyValue(L, 88));
		DeleteNode(GetbyValue(L, 77));
		PrintList(L);
		L = ReverseList(L);
		PrintList(L);
		DestoryList(L);
	}
	return;
}