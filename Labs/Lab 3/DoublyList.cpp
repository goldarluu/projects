#include "DoublyList.h"

using namespace std;

void DoublyList::insertFront(int newData)
{
    if (first == nullptr)
    {
        first = new Node(newData, nullptr, nullptr);
        last = first;	
        // Common error: Forgetting to re-set pointer last.
    }
    else
    {
        first = new Node(newData, nullptr, first);
        first->getNext()->setPrev(first);
        // Common error: Forgetting to connect pointer 
        // prev of what is now the second node to the 
        // new first node.
    }

    ++count;
}

int DoublyList::front() const
{
    return first->getData();
}

int DoublyList::back() const
{
    return last->getData();
}

void DoublyList::printForward() const
{
    Node* current = first;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getNext();
    }
}

void DoublyList::printReverse() const
{
    Node* current = last;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getPrev();
    }
}

void DoublyList::clearList()
{ 	
    Node* temp = first;

    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }

    last = nullptr;		
    // Don't forget to reset the last pointer to nullptr.
	count = 0;
}
bool DoublyList::deleteElem(int search)
{
    // if the list is empty
    if (count == 0)
        return false; 

    else // otherwise, its either in the front, back, or somewhere in 
    {
        bool found = false;
        // if the elemtn is the first 
        if (first->getData() == search)
        {
            // if the list has only one element 
            if (first == last)
            {
                delete first;
                first = last = nullptr;
            }
            else // if the list actually has multiple elements 
            {
                first = first->getNext();
                delete first->getPrev();
                first->getNext()->setPrev(nullptr);

            }
            found = true; // we have found it 
            --count;
        }

        // now we consider if its the last 
        else if (last->getData() == search)
        {
            last = last->getPrev(); // because the second to last is already connect we don't need to do it. 
            delete last->getNext();
            last->setNext(nullptr);
            found = true; 
            --count;
        }
        // if the element is in the list itself 
        else
        {
            Node* current = first; 
            while (!found && current != nullptr)
            {
                if (current->getData() == search)
                {
                    current->getNext()->setPrev(current->getPrev()); 
                    current->getPrev()->setNext(current->getNext()); 
                    delete current; 
                    current = nullptr; 
                    found = true; 
                    --count; 
                }
                else    
                    current = current->getNext(); 
            }
        }
    }
    if (!found) 
}
int DoublyList::check() const
{
    return count; 
}

DoublyList::~DoublyList()
{
	clearList();
}