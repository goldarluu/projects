/*
	Goldar Luu
	Yuna Kim
	Adam Ho
	Hali Dickson
	Belen Neciosup Sanchez

	March 10, 2021

	CS A250
	Lab 05
*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;


int main()
{
cout << "*** Eve and the Suitors ***\n\n";

int numSuitors = 0;
char repeat = 'y';

while (repeat == 'y')
{
	cout << "Enter the number of suitors: ";
	cin >> numSuitors;

	// Create the vector and fill it
	vector<int> suitors(numSuitors);
	for (int i = 0; i < numSuitors ; i++)
	{
		suitors[i] = i + 1 ;
	}

// Begin removing suitors
	vector<int>::iterator iter = suitors.begin();
	int thirdPos = 0; 
	while (suitors.size() > 1) // while there is more than one suitor
	{
		//  check if we're at the 3rd suitor we preincrement it
		// and see if that will give us the 3rd 
		if (++thirdPos == 3) {
			// iter set equal to the next element iterator(erase)
			iter = suitors.erase(iter); 
			// if its the last elemtn then we need to reset it now 
			if (iter == suitors.end()) {
				iter = suitors.begin(); // we reset that shit 
			}
			thirdPos = 0; 
			// set it back to 3 for the next three elements 
		}
		// if not increment the iterator to scan through entirely
		else 
			iter++; 

		// from here we want to see if we are at the last element
		if (iter == suitors.end()) {
			iter = suitors.begin(); // we reset 
		}
	}

	
	cout << "\nTo win the princess, you should stand in position " 
			<< suitors.front() << endl;

	cout << "\nWould you like to repeat the process? (y/n) ";
	cin >> repeat;
	cout << endl;
}
		vector<int> yourVector = { -1, 2, 3, -2, 4, -5, -7, 1, 6 };
		auto iter = remove_if(yourVector.begin(), yourVector.end(),
			[](int x) { return x < 0; });
		cout << *iter; 
		yourVector.resize(iter - yourVector.begin());

	cout << "Good-bye! :-)";

	cout << endl;
	return 0;
}

