#pragma once
class DLLNode
{
public:
	DLLNode(int value);
	DLLNode* prev;
	DLLNode* next;
	int data;
	void print();
	bool find(int value);
	bool deleteVal(int value);
	bool append(int data);
};