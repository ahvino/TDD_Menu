#include "MyLinkedList.h"

LinkedList::LinkedList()
{
    //this will be the start of the list
    head = nullptr;
    size = 0;
}

void LinkedList::Insert(int val)
{
    Node* newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        //current will iterate list until we get to a nullptr 
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}
 