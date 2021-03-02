#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkList.h"
#include "LinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void test01()
{
	struct LinkNode* header = Init_LinkList();//100 200 300 400
	Foreach_LinkList(header);
	InsertByValue_LinkList(header,200,150);
	Foreach_LinkList(header);
	RemoveByValue_LinkList(header,150);
	Foreach_LinkList(header);
	Destory_LinkList(header);
}
typedef struct Person
{
	LinkedListNode node;
	int age;
	char name[64];
}Person;
void test02()
{
	Person p1 = {NULL,22,"lucy"};
	Person p2 = {NULL,23,"lily"};
	Person p3 = {NULL,24,"tom"};
	Person p4 = {NULL,25,"jerry"};
	Person p5 = {NULL,26,"Ð¡°×"};
	
	LinkedList *list = create_LinkedList();
	insert_LinkedList(list,&p1.node,0);
	insert_LinkedList(list,(LinkedListNode*)&p2,0);
	insert_LinkedList(list,&p3.node,0);
	insert_LinkedList(list,&p4.node,0);
	insert_LinkedList(list,&p5.node,0);
	
	int length = length_LinkedList(list);
	for(int i=0;i<length;i++)
	{
		LinkedListNode *node = getNode_LinkedList(list,i);
		Person *p = (Person *)node;
		printf("%s %d\n",p->name,p->age);
	}
	
}
int main(int argc, char** argv) {
	test02();
	return 0;
}
