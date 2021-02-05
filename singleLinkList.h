#pragma once
#include<iostream>
using namespace std;
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode,*LinkList;		//LinkList��ָ�룬(*LinkList)���Ǹ�LNode�͵Ľṹ����,�����õ���������ʸýṹ���Ա

//1.��ʼ��
bool initList(LinkList &L) {	//����L��Ϊ�˸ı�L��ֵ��������Lָ����������ͷ���ĵ�ַ����Ҫ�ı�ͷ���ĵ�ַ
								//����һ��������Ƕ�ͷ���֮��Ľ����в���������ͷ���ĵ�ַһֱû��
								//��ȥ��&�������ɿ�������ִ��
								//֮���Ի��&�����Է�û��������û��ͷ���������������Ϊ���ܻ�Ե�һ������������L�ĵ�ַ�ͻ�ı䡣
	L = (LNode*)malloc(sizeof(LNode));
	if (NULL == L)
	{
		cout << "allocate fail" << endl;	//��������ռ�ʧ�ܵ����
		return false;
	}
	else {
		L->next = NULL;
		return true;
	}
}

//2.���Ե������Ƿ�Ϊ��
bool empty(LinkList L) {		//Lָ����������ͷ���ĵ�ַ,������->����������ʽṹ���Ա
	if (L->next == NULL) {
		return true;
	}
	else
		return false;
}

//3.��λ����
LNode* GetbyOrder(LinkList L, int i) {
	if (i < 0)	//i��1��ʼ
		return NULL;
	LNode *p = L;
	int j = 0;
	while(p!=NULL&&j<i) {
		p = p->next;
		j++;
	}
	return p;	//pָ���i��Ԫ��
}

//4.��ֵ����
LNode* GetbyValue(LinkList L, int e) {
	LNode *p = L->next;
	int j = 1;
	while (p!=NULL&&p->data != e) {	//Ϊ�յ�ʱ���û�����ˣ���ĩβ�ˣ�������ж�NULL��ȡ����data��
		p = p->next;
		j++;
	}
	cout << "order:" << j << " value:" << p->data << endl;
	return p;
}

//5.ָ��Ԫ��p�����Ԫ��e
bool InsertNextNode(LNode *p, int e) {		//�����б���Ҫ��LinkList &L��
	if (NULL == p) {
		cout << "��������β�ڵ�����" << endl;
		return false;
	}
	LNode* temp = (LNode*)malloc(sizeof(LNode));
	if (NULL == p)
	{
		cout << "allocate fail" << endl;	//��������ռ�ʧ�ܵ����
		return false;
	}
	temp->data = e;
	temp->next = p->next;
	p->next = temp;
	return true;
}

//6.ָ��λ��iǰ����Ԫ��e���ҵ���i-1��Ԫ�أ��ڵ�i-1��Ԫ�غ������Ԫ��e
bool InsertElem(LinkList &L, int i, int e) {
	LNode *p = GetbyOrder(L, i - 1);
	InsertNextNode(p, e);
	return true;
}

//7.ָ��Ԫ��pǰ����Ԫ��e:ָ��Ԫ��p�����Ԫ��p��������ݣ��޸�ԭ�ڵ�����Ϊe
bool InsertPreNode(LNode *p, int e) {
	InsertNextNode(p, p->data);
	p->data = e;
	return true;
}

//8.ָ���ڵ�pǰ����ڵ�q,��һ���ڵ���뵽һ��������
bool InsertPreNode1(LNode *p, LNode *q) {
	if (p == NULL || q == NULL) {
		cout << "�ڵ�Ϊ��" << endl;
		return false;
	}
	q->next = p->next;
	p->next = q;
	int temp = p->data;
	p->data = q->data;
	q->data = temp;
	return true;
}//�����ע�Ϳ�ݼ�ctrlK+ctrlC/ctrlU

//9.ɾ��ָ���ڵ�p:�ͺ�̽ڵ㽻�����ݣ����ͷŵ���һ��Ԫ�ء�����������ٰ���������
bool DeleteNode(LNode *p) {
	if (p == NULL) {
		cout << "��ɾ�ڵ�Ϊ��"<<endl;
		return false;
	}
	LNode *q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	cout << "delete..."<<endl;
	return true;
}

//10.��������
int Getlength(LinkList L) {
	LNode *p = L;
	int len = 0;
	while (p->next != NULL) {
		p = p->next;		//����һ��������ָ������ƶ�
		len++;
	}
	cout << "length:" << len << endl;
	return len;
}

//11.ͷ�巨����������
LNode* HeadInsert(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;	  //��ʼ�������ָ���ÿգ�ϰ��
	int elem = 0;
	LNode* p;
	cin >> elem;
	while (elem != -1) {		
		p = (LNode*)malloc(sizeof(LNode));
		p->data = elem;
		p->next = L->next;
		L->next = p;
		cin >> elem;	//ע�����ν�������
	}
	return L;	//�����˷���
}

//12.β�巨�����������״�
LNode* TailInsert(LinkList &L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;	  //��ʼ�������ָ���ÿգ�ϰ��
	LNode *i = L, *j = L;
	int elem = 0;
	cin >> elem;
	while (elem != -1) {
		j = (LNode*)malloc(sizeof(LNode));
		j->data = elem;
		i->next = j;	//��i���֮�����j�ڵ�
		i = i->next;	//����i��jָ��һ��
		cin >> elem;
	}
	i->next = NULL;	//β�ڵ�ָ�����ÿգ���ô����д�� i = NULL;
	return L;	//�����˷���
}

//13.������ԭ������
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

//14.�������ӡ
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
	cout << p->data << " " << endl;	//pָ��β�ڵ�ʱ������ѭ��������Ӧ�����
	return;
}

//15.��������
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
		free(pCurrent);	//ע�⣬���ͷſռ䣬�ٰ�Ұָ��ָ����һ��Ԫ�أ���ɾ��Ԫ�ز�ͬ
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