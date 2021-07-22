#include "AnyList.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::cout << "TEST: commonEnds\n\n";

	std::vector< std::vector<int>> vCalling = {
		{ 1 },
		{ 2 },
		{ 6, 3 },
		{ 7, 5 },
		{ 8, 4, 2, 9, 5, 6, 7, 1 },
		{ 1, 2, 3 },
		{ 1, 2, 3, 4, 5 },
		{ 1, 2, 3, 4, 5, 6, 7 , 8, 9 },
		{ 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85 },
		{ 67, 45, 23, 79, 15, 62, 94, 57, 71, 29, 45, 32 }

	};

	std::vector< std::vector<int>> vParameter = {
		{ 3 },
		{ 2 },
		{ 6, 4 },
		{ 8, 5 },
		{ 8, 4, 2, 9 },
		{ 7, 3, 3 },
		{ 4, 9, 2, 5 },
		{ 1, 23, 45, 78, 75, 25, 13, 67, 43, 25, 9 },
		{ 10, 25, 50, 45, 96, 60, 90, 36, 74, 93, 60, 87, 34, 14, 56, 85 },
		{ 67, 12, 36, 79, 97, 26, 49, 75, 71, 92, 54, 76, 34, 45, 32 }
	};

	auto sizeV1 = vCalling.size();
	auto sizeV2 = vParameter.size();

	for (int i = 0; i < sizeV1; ++i)
	{
		// Create lists and insert elements
		AnyList callingList;
		AnyList paramList;

		auto sizeInnerV1 = vCalling[i].size();
		auto sizeInnerV2 = vParameter[i].size();

		// Casting needed to avoid 4-8 byte overflow bug in VS.
		int limit1 = static_cast<int>(sizeInnerV1 - 1);
		int limit2 = static_cast<int>(sizeInnerV2 - 1);
		for (int j = limit1; j >= 0; --j)
			callingList.insertFront(vCalling[i].at(j));
		for (int j = limit2; j >= 0; --j)
			paramList.insertFront(vParameter[i].at(j));

		// Print out
		std::cout << "Elements inserted in calling obj: ";
		for (auto elem : vCalling[i])
			std::cout << elem << " ";
		std::cout << "\n             Your calling obj is: ";
		callingList.print();
		// Print out
		std::cout << "\nElements inserted in parameter obj: ";
		for (auto elem : vParameter[i])
			std::cout << elem << " ";
		std::cout << "\n             Your parameter obj is: ";
		paramList.print();
		std::cout << "\n    Common ends? ";
		bool result = false;
		if (sizeInnerV1 != 0 && sizeInnerV2 != 0)
			result = (vCalling[i].at(0) == vParameter[i].at(0) &&
				vCalling[i].at(sizeInnerV1 - 1) ==
				vParameter[i].at(sizeInnerV2 - 1));
		std::cout << "\n             Expected: "
			<< ((result) ? "Yes." : "No.");
		std::cout << "\n          Your output: ";
		callingList.commonEnds(paramList);
		std::cout << ((result) ? "Yes." : "No.");

		std::cout << "\n\n----------------------------------------\n";
	}

	std::cout << std::endl;
	return 0;
}
