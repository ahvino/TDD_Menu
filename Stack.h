#pragma once

#include "Node.h"

class Stack
{
private:
    Node* head;
    Node* tail;
    int size;

public:
    Stack();
    void Push(int val);
    void Pop();
    void Remove(int val);
    void Print();

};