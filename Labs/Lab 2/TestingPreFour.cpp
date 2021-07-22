#include "AnyList.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::cout << "TEST: preFour...\n\n";

	std::vector< std::vector<int>> vParameter = {
		{ 1, 2, 4, 1 },
		{ 1, 4, 4 },
		{ 1, 4, 4, 2 },
		{ 1, 3, 4, 2, 4 },
		{ 4, 4 },
		{ 3, 3, 4 },
		{ 1, 2, 1, 4 },
		{ 3, 4, 3, 4, 3, 4, 4 },
		{ 2, 1, 4, 2 },
		{ 2, 1, 2, 1, 4, 2 },
		{ 3, 8, 2, 5, 7, 9, 1, 4, 6},
	};

	std::vector< std::vector<int>> vCalling = {
	{ 2, 1 },
	{ 1 },
	{ 1 },
	{ 3, 1 },
	{  },
	{ 3, 3 },
	{ 1, 2, 1 },
	{ 3 },
	{ 1, 2 },
	{ 1, 2, 1, 2 },
	{ 1, 9, 7, 5, 2, 8, 3 },
	};

	int sizeV1 = static_cast<int>(vParameter.size());

	for (int i = 0; i < sizeV1; ++i)
	{
		// Create a new list and insert elements
		AnyList paramList;
		int sizeInnerV1 = static_cast<int>(vParameter[i].size());
		for (int j = sizeInnerV1 - 1; j >= 0; --j)
			paramList.insertFront(vParameter[i].at(j));

		// Print out
		std::cout << "Elements inserted: ";
		for (auto elem : vParameter[i])
			std::cout << elem << " ";
		std::cout << "\n     Your list is: ";
		paramList.print();

		// Call function preFour
		AnyList callingList;
		callingList.preFour(paramList);

		// Print out
		std::cout << "\nGet results...";
		std::cout << "\nExpected calling object: ";
		for (auto elem : vCalling[i])
			std::cout << elem << " ";
		std::cout << "\n    Your calling object: ";
		callingList.print();
		std::cout << "\nExpected parameter object: ";
		for (auto elem : vParameter[i])
			std::cout << elem << " ";
		std::cout << "\n    Your parameter object: ";
		paramList.print();

		std::cout << "\n\n----------------------------------------\n";
	}

	std::cout << std::endl;
	return 0;
}
