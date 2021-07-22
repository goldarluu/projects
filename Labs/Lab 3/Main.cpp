#include "DoublyList.h"

#include <iostream>

int main()
{
	DoublyList intList;

	intList.insertInOrder(8);
	intList.insertInOrder(5);
	intList.insertInOrder(37);
	intList.insertInOrder(53);
	intList.insertInOrder(21);
	intList.insertInOrder(18);
	intList.insertInOrder(73);
	intList.insertInOrder(49);

	std::cout << "TESTING: insertInOrder...\n"
		<< "\nElements inserted (in this order): "
		<< "8 5 37 53 21 18 73 49\n";
		
	std::cout << "\nForward..."
		<< "\nEXPECTED OUTPUT: 5 8 18 21 37 49 53 73"
		<< "\n    YOUR OUTPUT: ";
	intList.printForward();

	std::cout << "\nReverse..."
		<< "\nEXPECTED OUTPUT: 73 53 49 37 21 18 8 5"
		<< "\n    YOUR OUTPUT: ";
	intList.printReverse();

	std::cout << "\n\nCheck first and last nodes...\n";

	std::cout << "\nFirst..."
		<< "\nEXPECTED OUTPUT: 5"
		<< "\n    YOUR OUTPUT: "
		<< intList.front();

	std::cout << "\nBack..."
		<< "\nEXPECTED OUTPUT: 73"
		<< "\n    YOUR OUTPUT: "
		<< intList.back();

	std::cout << intList.check(); 
	std::cout << std::endl ;
	return 0;
}
