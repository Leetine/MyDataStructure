#pragma once

typedef void LinkedList;
typedef struct _tag_LinkedListNode
{
	struct _tag_LinkedListNode *next;
}LinkedListNode;

//创建链表 
LinkedList* create_LinkedList();
//插入 
int insert_LinkedList(LinkedList* list,LinkedListNode *node,int pos);
//销毁
void destory_LinkedList(LinkedList* list);
//清空
void clear_LinkedList(LinkedList* list);
//链表的长度
int length_LinkedList(LinkedList* list);
LinkedListNode * getNode_LinkedList(LinkedList* list,int pos);
//删除 
LinkedListNode * deleteNode_LinkedList(LinkedList* list,int pos);

