#include "DLL.h"
#include <iostream>

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