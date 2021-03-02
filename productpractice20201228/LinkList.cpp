#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//��ʼ������
struct LinkNode* Init_LinkList()
{
	struct LinkNode* header = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	header->data = -1;
	header->next = NULL;
	
	//βָ��
	struct LinkNode* pRear = header;
	int val = -1;
	while(true)
	{
		printf("input data: ");
		scanf("%d",&val);
		if(val==-1)
		{
			break;
		}
		//�������
		struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
		newNode->data = val;
		newNode->next = NULL;
		//���뵽����β
		pRear->next = newNode;
		//����βָ��
		pRear = newNode; 
	}
	
	return header;
}
//�����㣺��ֵΪoldVal��λ�ò����µ�����newVal
void InsertByValue_LinkList(struct LinkNode* header,int oldVal,int newVal)
{
	if(NULL == header)
	{
		return;
	}
	//��������ָ�����
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent =  pPrev->next;
	while(pCurrent!=NULL)
	{
		if(pCurrent->data == oldVal)
		{
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	//û���ҵ�oldVal
	if(pCurrent==NULL)
	{
		
		return;
	} 
	//�����½��
	struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode)); 
	newNode->data = newVal;
	newNode->next = NULL;
	//���뵽������
	newNode->next = pCurrent;
	pPrev->next = newNode; 
	return;
}
//ɾ��ֵΪval�Ľ��
void RemoveByValue_LinkList(struct LinkNode* header,int val)
{
	if(NULL == header)
	{
		return;
	}
	//��������ָ�����
	struct LinkNode* pPrev = header;
	struct LinkNode* pCurrent =  pPrev->next;
	while(pCurrent!=NULL)
	{
		if(pCurrent->data == val)
		{
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	//û���ҵ�val
	if(pCurrent==NULL)
	{
		
		return;
	} 
	//ɾ��val,���½�������Ĺ�ϵ
	pPrev->next = pCurrent->next;
	// �ͷſռ�
	free(pCurrent);
	pCurrent = NULL; 
	return;
}
 //��������
void Foreach_LinkList(struct LinkNode* header)
{
	if(NULL == header)
	{
		return;
	}
	struct LinkNode* pCurrent = header->next;
	while(pCurrent!=NULL)
	{
		printf("%d  ",pCurrent->data);
		pCurrent = pCurrent->next;
	}
	printf("\n");
	return;
}
//�������
void clear_LinkList(struct LinkNode* header)
{
	if(NULL == header)
	{
		return;
	}
	struct LinkNode* pCurrent = header->next;
	while(pCurrent!=NULL)
	{
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;	 
	}
	header->next = NULL;
	return;
}
//��������
void Destory_LinkList(struct LinkNode* header)
{
	if(NULL == header)
	{
		return;
	}
	struct LinkNode* pCurrent = header;
	while(pCurrent!=NULL)
	{
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;	 
	}
	return;
}
