#include <iostream>

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

int main()
{
	DLL dbl = DLL();
	dbl.append(5);
	dbl.append(7);
	dbl.push(1);
	dbl.push(0);
	dbl.append(10);
	dbl.printList();
	std::cout << std::endl;
	std::cout << dbl.deleteVal(5) << std::endl;
	dbl.printList();
	std::cout << std::endl;
	std::cout << dbl.find(5) << std::endl;
	std::cout << dbl.find(7) << std::endl;
}