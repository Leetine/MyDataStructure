#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//初始化链表
struct LinkNode* Init_LinkList()
{
	struct LinkNode* header = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	header->data = -1;
	header->next = NULL;
	
	//尾指针
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
		//创建结点
		struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
		newNode->data = val;
		newNode->next = NULL;
		//插入到链表尾
		pRear->next = newNode;
		//更新尾指针
		pRear = newNode; 
	}
	
	return header;
}
//插入结点：在值为oldVal的位置插入新的数据newVal
void InsertByValue_LinkList(struct LinkNode* header,int oldVal,int newVal)
{
	if(NULL == header)
	{
		return;
	}
	//两个辅助指针变量
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
	//没有找到oldVal
	if(pCurrent==NULL)
	{
		
		return;
	} 
	//创建新结点
	struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode)); 
	newNode->data = newVal;
	newNode->next = NULL;
	//插入到链表中
	newNode->next = pCurrent;
	pPrev->next = newNode; 
	return;
}
//删除值为val的结点
void RemoveByValue_LinkList(struct LinkNode* header,int val)
{
	if(NULL == header)
	{
		return;
	}
	//两个辅助指针变量
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
	//没有找到val
	if(pCurrent==NULL)
	{
		
		return;
	} 
	//删除val,重新建立链表的关系
	pPrev->next = pCurrent->next;
	// 释放空间
	free(pCurrent);
	pCurrent = NULL; 
	return;
}
 //遍历链表
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
//清空链表
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
//销毁链表
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
