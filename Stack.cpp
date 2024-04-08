#include "Stack.h"
#include <iostream>

/// <summary>
/// Stack implementation is LIFO order so 
/// Last in, First out
/// This means that the lasat item entered into 
/// the stack should be the first one removed. 
/// </summary>
Stack::Stack()
{
    //this will be the start of the list
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void Stack::Push(int val)
{
    Node* NewNode = new Node(val);
    if (head == nullptr)
    {
        head = NewNode;
        head->prev = nullptr;
        tail = head;

    }
    else
    {
        
        tail->next = NewNode;
        NewNode->prev = tail;
        tail = NewNode;
        head->next = tail;
        tail->next = nullptr;
    }
    size++;

}

void Stack::Pop()
{
    if (tail != nullptr)
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
}

void Stack::Remove(int val)
{
    Node* curr = head;
    while (curr->next != nullptr)
    {
        if (curr->data == val)
        {
            Node* tempPrev = curr->prev;
            Node* tempNext = curr->next;
            tempPrev->next = tempNext;
            tempNext->prev = tempPrev;

            delete curr;
            
        }
        else
        {

        }

        curr = curr->next;
    }

}

void Stack::Print()
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
    }
}