#include "DLL.h"
#include <iostream>
DLL::DLL() 
{

}

bool DLL::push(int value) 
{
	DLLNode* newNode = new DLLNode(value);
	if (this->front == nullptr) 
	{
		this->front = newNode;
		return true;
	}
	newNode->next = this->front;
	this->front->prev = newNode;
	this->front = newNode;
	return true;
}

bool DLL::append(int value) 
{
	if (this->front == nullptr)
	{
		DLLNode* newNode = new DLLNode(value);
		this->front = newNode;
		return true;
	}
	this->front->append(value);
	return true;
}

void DLL::printList() 
{
	this->front->print();
	std::cout << std::endl;
}

int DLL::find(int value) 
{
	return this->front->find(value);
}

bool DLL::deleteVal(int value) 
{
	if (this->front == nullptr) return false;
	if (this->front->data == value) 
	{
		if (this->front->next == nullptr) 
		{
			delete this->front;
			this->front = nullptr;
			return true;
		}
		DLLNode* newHook = this->front->next;
		delete this->front;
		this->front = newHook;
	}
	return this->front->deleteVal(value);
}
