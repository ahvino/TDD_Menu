#pragma once

#include "Node.h"

class LinkedList
{
    private:
        Node * head;

        int size;


    public:
        LinkedList();
        void Insert(int val);
};
