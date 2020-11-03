#pragma once
#include "DLLNode.h"
class DLL
{
public:
	DLLNode* front;
	DLL();
	bool push(int value);
	bool append(int value);
	void printList();
	int find(int value);
	bool deleteVal(int value);
};

