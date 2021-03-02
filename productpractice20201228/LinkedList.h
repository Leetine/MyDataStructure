#pragma once

typedef void LinkedList;
typedef struct _tag_LinkedListNode
{
	struct _tag_LinkedListNode *next;
}LinkedListNode;

//�������� 
LinkedList* create_LinkedList();
//���� 
int insert_LinkedList(LinkedList* list,LinkedListNode *node,int pos);
//����
void destory_LinkedList(LinkedList* list);
//���
void clear_LinkedList(LinkedList* list);
//����ĳ���
int length_LinkedList(LinkedList* list);
LinkedListNode * getNode_LinkedList(LinkedList* list,int pos);
//ɾ�� 
LinkedListNode * deleteNode_LinkedList(LinkedList* list,int pos);

