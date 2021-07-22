#include "AnyList.h"

using namespace std;

void AnyList::insertFront(int newData)
{
	ptrToFirst = new Node(newData, ptrToFirst);
	++count;
}

void AnyList::print() const
{
	if (ptrToFirst == nullptr)
		// Check if the list is empty.
		// You can also use: if (count < 1)
		cerr << "List is empty.";
	// Use cerr, instead of cout. Why?
	else
	{
		Node* current = ptrToFirst;
		// Create a pointer to traverse the list.		
		// This pointer will point to the first node in the list.

		while (current != nullptr)
			// While the current pointer is NOT a nullptr,
			// that is, while the current pointer has not reached  
			// the end of the list.
		{
			// Output the data. 
			cout << current->getData() << " ";
			// Move the pointer current forward.
			current = current->getPtrToNext();
		}
	}
}

// This function does not delete the 
// list object; it ONLY deletes the nodes.
void AnyList::clearList()
{
	Node* temp = ptrToFirst;
	// Pointer to delete the node, which	
	// starts by pointing to the first node.

	while (ptrToFirst != nullptr)
	{
		ptrToFirst = ptrToFirst->getPtrToNext();
		delete temp;
		temp = ptrToFirst;
	}

	// Update the count outside the loop.
	count = 0;
}

AnyList::~AnyList()
{
	clearList();
}