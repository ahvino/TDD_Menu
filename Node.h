#pragma once

struct Node
{
    int data;
    Node* next;
    Node* prev;
    

    Node(int val) : data(val), next(nullptr) , prev(nullptr){}
};
