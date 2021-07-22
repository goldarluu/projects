#include "AnyList.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::cout << "TEST: haveThree...\n\n";

	std::vector< std::vector<int>> v1 = {
		{ 3, 1, 3, 1, 3, 4, 3, 1, 3, 2 },
		{ 3, 1, 3, 3 },
		{ 3, 4, 3, 3, 4 },
		{ 1, 3, 1, 3, 1, 2 },
		{ 1, 3, 1, 3, 1, 3 },
		{ 1, 3, 3, 1, 3 },
		{ 1, 3, 1, 3, 1, 3, 4, 3 },
		{ 3, 4, 3, 4, 3, 4, 4 },
		{ 3, 3, 3 },
		{ 1, 3 },
		{ 3 },
		{ 1 },
	};

	std::vector<std::string> vResults = { "False", "False", "False", "False",
		"True", "False", "False", "True", "False", "False", "False", "False" };

	int sizeV1 = static_cast<int>(v1.size());

	for (int i = 0; i < sizeV1; ++i)
	{
		// Create a new list and insert elements
		AnyList list1;
		int sizeInnerV1 = static_cast<int>(v1[i].size());
		for (int j = sizeInnerV1 - 1; j >= 0; --j)
			list1.insertFront(v1[i].at(j));

		// Print out
		std::cout << "Elements inserted: ";
		for (auto elem : v1[i])
			std::cout << elem << " ";
		std::cout << "\n     Your list is: ";
		list1.print();

		// Get results
		std::cout << "\nGet results...";
		std::cout << "\n   Expected: "
			<< vResults[i];
		std::cout << "\nYour output: "
			<< ((list1.haveThree()) ? "True" : "False");

		std::cout << "\n\n----------------------------------------\n";
	}

	std::cout << std::endl;
	return 0;
}
