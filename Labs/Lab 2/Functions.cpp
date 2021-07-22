/*                      
    Kim, Yuna   
    Neciosup Sanchez, Belen       
	Dickson, Hali
	Ho, Adam
	Luu, Goldar
                       
    February 17, 2021   
                        
    CS A250             
    Lab 2              
*/

#include "AnyList.h"
#include <string>

using namespace std;

// Definition function getMin
int AnyList::getMin() const
{
	int smallest = ptrToFirst->getData();
	Node *current = ptrToFirst->getPtrToNext();
	while (current != nullptr)
	{
		if (current->getData() < smallest)
			smallest = current->getData();

		current = current->getPtrToNext();
	}
	return smallest;
}

// Definition function haveThree
bool AnyList::haveThree() const
{
	Node* trailCurrent = ptrToFirst;
	Node* current = ptrToFirst->getPtrToNext();
	int countThree = 0;

	while (current != nullptr)
	{
		if (trailCurrent->getData() == 3)
		{
			++countThree;
			if (current->getData() == 3)
				return false;
		}
		trailCurrent = trailCurrent->getPtrToNext();
		current = current->getPtrToNext();
	}
	if (trailCurrent->getData() == 3)
		++countThree;

	return (countThree == 3);
}

// Definition function preFour
void AnyList::preFour(const AnyList& list) 
{
    Node * param = list.ptrToFirst;
    // While the object data's is not 4 and the it isn't empty 
    while (param->getData() != 4 && param != nullptr) 
    {
        insertFront(param->getData()); 
		//taking the data from the param to insert into the calling object.
        param = param->getPtrToNext(); // increments param 
    }
}

// Definition function commonEnds
bool AnyList::commonEnds(const AnyList& list) const
{
	Node* paramList = ptrToFirst; 
	Node* callingList = list.ptrToFirst; 
	if (paramList->getData() == callingList->getData())
	{
		while (paramList->getPtrToNext() != nullptr)
		{
			// how do ytou find the nullptr 
			paramList = paramList->getPtrToNext();
		}
		while (callingList->getPtrToNext() != nullptr)
		{
			callingList = callingList->getPtrToNext();
		}
		if (callingList->getData() == paramList->getData())
			return true; 
	}
	return false;
}