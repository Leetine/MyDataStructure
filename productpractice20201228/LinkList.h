
//结点数据类型
struct LinkNode
{
	int data;
	struct LinkNode* next;	
}; 
//基本操作
//初始化链表
struct LinkNode* Init_LinkList();
//插入结点：在值为oldVal的位置插入新的数据newVal
void InsertByValue_LinkList(struct LinkNode* header,int oldVal,int newVal);
//删除值为val的结点
void RemoveByValue_LinkList(struct LinkNode* header,int val);
 //遍历链表
void Foreach_LinkList(struct LinkNode* header);
//清空链表
void clear_LinkList(struct LinkNode* header);
//销毁链表
void Destory_LinkList(struct LinkNode* header);

