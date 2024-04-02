#include "MyLinkedList.h"

LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}

void LinkedList::Insert(int val)
{
    //create a node if there is none and add data to it and then move the next pointer
    if (size == 0)
    {   
        Node * newNode = new Node();
        newNode->data = val;
        newNode->next = head;
    }
    else
    {
        Node* newNode = new Node();
        newNode->prev = head;
        newNode->data = val;
        newNode->next = head;
    }
    size++;


}
