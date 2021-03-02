#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _c_linkedlist
{
	LinkedListNode header;//ͷ���
	int length;//����ĳ��� 
}TLinkedList;

//�������� 
LinkedList* create_LinkedList()
{
	TLinkedList* tList = NULL;
	LinkedList* list = NULL;
	tList = (TLinkedList*)malloc(sizeof(TLinkedList));
	if(tList!=NULL)
	{
		memset(tList,0,sizeof(TLinkedList));
		tList->header.next = NULL;
		tList->length = 0;
		
		list = (LinkedList*)tList;
	}
	return list;
}
//���� 
int insert_LinkedList(LinkedList* list,LinkedListNode *node,int pos)
{
	if(NULL == list || NULL== node)
	{
		return -2;
	}
	if(pos<0)
	{
		return -1;
	}
	TLinkedList *tList = (TLinkedList *)list;
	if(pos>=tList->length)
	{
		//��������β	
	 	LinkedListNode *current = &(tList->header);
	 	for(int i=0;i<tList->length;i++)
	 	{
	 		current = current->next;
		}
	 	current->next = node;
	 	tList->length++;
	 	return 0;
	}
	//0<pos<length
	LinkedListNode *current = &(tList->header);
	for(int i=0;i<pos;i++)
	{
	 	current = current->next;
	} 
	node->next = current->next;
	current->next = node;
	tList->length++;
	return 0;
}
//����
void destory_LinkedList(LinkedList* list)
{
	if(NULL == list)
	{
		return;
	}
	free(list);
	return;
}
//���
void clear_LinkedList(LinkedList* list)
{
	if(NULL == list)
	{
		return;
	}
	TLinkedList *tList = (TLinkedList *)list;
	tList->length = 0;
	tList->header.next = NULL;
	return;
}
//����ĳ���
int length_LinkedList(LinkedList* list)
{
	if(NULL == list)
	{
		return -1;
	}
	TLinkedList *tList = (TLinkedList *)list;
	return tList->length;
}
LinkedListNode * getNode_LinkedList(LinkedList* list,int pos)
{
	if(NULL==list)
	{
		return NULL;
	}
	TLinkedList *tList = (TLinkedList *)list;
	if(pos<0 || pos>=tList->length)
	{
		return NULL;
	}
	LinkedListNode *current = tList->header.next;
	for(int i=0;i<pos;i++)
	{
		current = current->next;
	}
	return current;
}
//ɾ�� 
LinkedListNode * deleteNode_LinkedList(LinkedList* list,int pos)
{
	if(NULL==list)
	{
		return NULL;
	}
	TLinkedList *tList = (TLinkedList *)list;
	if(pos<0 || pos>=tList->length)
	{
		return NULL;
	}
	LinkedListNode *current = NULL;
	current = &(tList->header);
	for(int i=0;i<pos && current->next!=NULL;i++)
	{
		current = current->next;
	}
	LinkedListNode *result = NULL;
	result = current->next;
	//ɾ��
	current->next = result->next;
	tList->length--;
	return result; 
}









