#include "Queue.h"
#include <iostream>

/// <summary>
/// Queue implementation is FIFO order so 
/// First in, First out
/// This means that the first item entered into 
/// the queue should be the first one removed. 
/// </summary>
Queue::Queue()
{
    //this will be the start of the list
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void Queue::Push(int val)
{
    Node* NewNode = new Node(val);
    if (head == nullptr)
    {
        head = NewNode;
        tail = head;
    }
    else
    {
        // FIFO order for stack
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

int Queue::Size()
{
    return size;
}

void Queue::Top()
{
    if (head != nullptr)
    {
        std::cout << "(FIFO) Top of Queue: " << head->data << std::endl;
    }
    else
    {
        std::cout << "No data to view " << std::endl;

    }
}

void Queue::Pop()
{
    Node* curr;

    if (size > 0)
    {
        if (head == tail)
        {
            curr = head;
            head = nullptr;
            tail = nullptr;
            size--;

        }

        if (head != nullptr)
        {
            curr = head;
            head = head->next;
            head->prev = nullptr;

            //delete curr;
            size--;
        }
    }
    else
    {
        std::cout << "Queue is empty. Nothing to pop off Queue..." << std::endl;
    }



}

void Queue::Remove(int val)
{
    Node* curr = head;
    do
    {
        curr = curr->next;

        if (curr->data == val)
        {
            Node* tempPrev = curr->prev;
            Node* tempNext = curr->next;
            tempPrev->next = tempNext;
            tempNext->prev = tempPrev;

            size--;
            break;

        }

    } while (curr->next != nullptr);

}

void Queue::Print()
{
    Node* curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;

        if (head == nullptr) { return; }

    }
    std::cout << std::endl;

}