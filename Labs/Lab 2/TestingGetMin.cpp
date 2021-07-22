#include "AnyList.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::cout << "TEST: getMin...\n\n";

	std::vector< std::vector<int>> v1 = {
		{ 1 },
		{ 5, 6, 2, 9, 3 },
		{ 3, 9 },
		{ 5, 7 },
		{ 2, 6, 9 },
		{ 9, 7, 5 },
		{ 6, 8, 3 },
		{ 2, 5, 3, 7, 9, 4, 1 },
		{ 2, 5, 7, 3, 4, 8, 6, 9 }
	};

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

		// Get minimum value
		std::cout << "\nGet minimum value...";
		std::cout << "\n   Expected: "
			<< *(min_element(v1[i].begin(), v1[i].end()));
		std::cout << "\nYour output: "
			<< list1.getMin();

		std::cout << "\n\n----------------------------------------\n";
	}

	std::cout << std::endl;
	return 0;
}
