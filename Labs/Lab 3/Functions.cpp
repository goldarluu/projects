/*
    Goldar Luu
    Yuna Kim
    Adam Ho
    Hali Dickson
    Belen Neciosup Sanchez

    Febuary 20, 2021

    CS A250
    Lab 03
*/

#include "DoublyList.h"

using namespace std;

// Definition function insertInOrder 


    void DoublyList::insertInOrder(int newData)
    {
        if (first == nullptr)
        {
            insertFront(newData); 
        }
        else if (last->getData() < newData)
        {
            Node * newNode = new Node(newData, last, nullptr); 
            last = last->getNext(); // let it continue; 
        }

        else
        {
            Node* current = first; 

            while (current->getData() < newData && current->getNext()->getData() < newData)
            {
                current = current->getNext(); 
            }

            Node* newNode = new Node(newData, current, current->getNext());
            current->setNext(newNode); 
            current->getNext()->setPrev(newNode); 
        }
    }






















    
























  