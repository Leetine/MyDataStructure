#pragma once
#include<iostream>
using namespace std;

typedef struct Linknode {
	int data;
	struct Linknode *next;
}*LinkStack;		

//1.��ʼ��
bool initList(LinkStack &S) {	//����L��Ϊ�˸ı�L��ֵ��������Lָ����������ͷ���ĵ�ַ����Ҫ�ı�ͷ���ĵ�ַ
								//����һ��������Ƕ�ͷ���֮��Ľ����в���������ͷ���ĵ�ַһֱû��
								//��ȥ��&�������ɿ�������ִ��
								//֮���Ի��&�����Է�û��������û��ͷ���������������Ϊ���ܻ�Ե�һ������������L�ĵ�ַ�ͻ�ı䡣
	S = (Linknode*)malloc(sizeof(Linknode));
	if (NULL == S)
	{
		cout << "allocate fail" << endl;	//��������ռ�ʧ�ܵ����
		return false;
	}
	else {
		S->next = NULL;
		return true;
	}
}

//2.������ջ�Ƿ�Ϊ��
bool empty(LinkStack S) {		//Lָ����������ͷ���ĵ�ַ,������->����������ʽṹ���Ա
	if (S->next == NULL) {
		return true;
	}
	else
		return false;
}

//3.����ջ����
int Getlength(LinkStack S) {
	Linknode *p = S;
	int len = 0;
	while (p->next != NULL) {
		p = p->next;		//����һ��������ָ������ƶ�
		len++;
	}
	cout << "length:" << len << endl;
	return len;
}

//4.��ջ
Linknode* Push(LinkStack &S,int e) {
	Linknode* p;
	p = (Linknode*)malloc(sizeof(Linknode));
	p->data = e;
	p->next = S->next;
	S->next = p;
	return S;
}

//5.��ջ,����ջ��Ԫ��
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

//6.��ӡ
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
	cout << p->data << " " << endl;	//pָ��β�ڵ�ʱ������ѭ��������Ӧ�����
	return 0;
}

//7.���Գ���
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
