#include "DLLNode.h"
#include <iostream>
DLLNode::DLLNode(int value)
{
	this->next = nullptr;
	this->prev = nullptr;
	this->data = value;
}
void DLLNode::print()
{
	std::cout << data << " ";
	if (this->next != nullptr) this->next->print();
}

bool DLLNode::find(int value)
{
	if (this->data == value) return true;
	if (this->next != nullptr) return this->next->find(value);
	return false;
}

bool DLLNode::deleteVal(int value)
{
	if (this->data == value) 
	{
		if (this->next != nullptr) this->next->prev = this->prev;
		if (this->prev != nullptr) this->prev->next = this->next;
		delete this;
		return true;
	}
	if (this->next != nullptr) return this->next->deleteVal(value);
	return false;
}

bool DLLNode::append(int data)
{
	if (this->next == nullptr) 
	{
		DLLNode* newNode = new DLLNode(data);
		this->next = newNode;
		return true;
	}
	return this->next->append(data);
}