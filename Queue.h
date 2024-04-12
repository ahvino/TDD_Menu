#pragma once

#include "Node.h"

class Queue
{
private:
    Node* head;
    Node* tail;
    int size;

public:
    Queue();
    void Push(int val);
    void Pop();
    void Remove(int val);
    void Print();
    void Top();
    int Size();

};