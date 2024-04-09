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
        //head->prev = nullptr;
        tail = head;
        //head->next = tail->next;
    }
    else
    {
        // LIFO order for stack
        //keep track of current tail before inserting new node
        Node* prevTail = tail;
        tail = NewNode;

        //set the previous tail's next to the new tail/new node
        prevTail->next = tail;

        //account for heads next pointer
        if (head->next == nullptr)
        {
            head->next = tail;
            tail->prev = head;
        }
        else
        {
            tail->prev = prevTail;
        }
    }
    size++;

}

void Stack::Pop()
{
    if (tail != nullptr)
    {
        tail = tail->prev;
        tail->next = nullptr;
        
        size--;
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
            size--;
            
        }

        curr = curr->next;
    }

}

void Stack::Print()
{
    Node* curr = tail;
    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->prev;
    }
    std::cout << std::endl;

}