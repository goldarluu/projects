#ifndef ANYLIST_H
#define ANYLIST_H

#include<iostream>
#include <string> 

class Node
{
public:
	Node() : data(0), ptrToNext(nullptr) {}
	Node(int theData, Node* newPtrToNext)
		: data(theData), ptrToNext(newPtrToNext) {}
	Node* getPtrToNext() const { return ptrToNext; }
	int getData() const { return data; }
	void setData(int theData) { data = theData; }
	void setPtrToNext(Node* newPtrToNext)
	{
		ptrToNext = newPtrToNext;
	}
	~Node() {}
private:
	int data;
	Node* ptrToNext; // Pointer that points to next node.
};


class AnyList
{
public:
	AnyList() : ptrToFirst(nullptr), count(0) {}

	void insertFront(int);

	void print() const;

	void clearList();
	~AnyList();


	/*********************************************************/

	// Declaration function getMin
	int getMin() const;

	// Declaration function haveThree
	bool haveThree() const;

	// Declaration function preFour
	void preFour(const AnyList& list);
	
	// Declaration function commonEnds
	bool commonEnds(const AnyList& list) const;


private:
	// Pointer to point to the first node in the list.
	Node* ptrToFirst;
	// Variable to keep track of number of nodes in the list.
	int count;
};

#endif