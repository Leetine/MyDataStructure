
//�����������
struct LinkNode
{
	int data;
	struct LinkNode* next;	
}; 
//��������
//��ʼ������
struct LinkNode* Init_LinkList();
//�����㣺��ֵΪoldVal��λ�ò����µ�����newVal
void InsertByValue_LinkList(struct LinkNode* header,int oldVal,int newVal);
//ɾ��ֵΪval�Ľ��
void RemoveByValue_LinkList(struct LinkNode* header,int val);
 //��������
void Foreach_LinkList(struct LinkNode* header);
//�������
void clear_LinkList(struct LinkNode* header);
//��������
void Destory_LinkList(struct LinkNode* header);

