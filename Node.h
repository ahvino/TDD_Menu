#pragma once

struct Node
{
    int data;
    Node* next;
    Node* prev;
    

    Node(int val) : data(val), next(nullptr) , prev(nullptr){}
};

struct TNode
{
    int data;
    TNode* left;
    TNode* right;


    TNode(int val) : data(val), left(nullptr), right(nullptr) {}
};