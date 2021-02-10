#pragma once
#define Maxsize 10
#include<iostream>
using namespace std;

typedef struct{
	int data[Maxsize];		//静态数组存放栈中元素
	int top;				//栈顶指针
	int length;
}Seqstack;

//初始化栈
void InitStack(Seqstack &S) {
	S.top = -1;		//（不用给数组元素赋值）
	//这种写法是初始化指向栈底元素而不是栈底的后一个元素
	S.length = 0;	
}

//判断栈空
bool Empty(Seqstack S) {
	if (-1 == S.top) {
		return true;
	}
	else
		return false;
}

//入栈出栈操作的返回值都是bool类型，和Int类型差不多
//入栈
bool Push(Seqstack &S,int e) {
	if (Maxsize - 1 == S.top) {	//这里top达不到maxsize!
		return false;
	}
	else {
		S.top++;
		S.data[S.top] = e;
		S.length++;
		return true;
	}
}

//出栈,把栈顶元素赋值给内存中的变量x
bool Pop(Seqstack &S, int &x) {
	if (-1 == S.top) {
		return false;
	}
	else {
		x = S.data[S.top];
		S.top--;
		S.length--;		//数据还残留在内存中，只是逻辑上删除了
		return true;
	}
}

//按栈底到栈顶打印
void Print(Seqstack &S) {
	for (int i = 0; i < S.length; i++) {
		cout << S.data[i] << " ";
	}
	return;
}

//测试程序
void TestSeqStack() {
	Seqstack S;		//系统分配内存
	InitStack(S);
	Push(S, 10);
	Push(S, 20);
	Push(S, 30);
	Print(S);
	int topelem;
	Pop(S, topelem);
	cout << "topelem" << topelem << endl;
	Print(S);	//函数运行结束后自动回收内存
}

