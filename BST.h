#pragma once
struct TNode
{
    int data;
    TNode* left;
    TNode* right;

    TNode() : data(-1),left(nullptr), right(nullptr) {}
    TNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
    private:
        TNode* m_root;

    public:
        BST() : m_root(nullptr) {};
        void Add(int data);
        void InOrderTraverse(TNode* curr);
        TNode * GetRoot();
        TNode* Remove(TNode* root,int data);
        TNode* Delete(TNode* root,int data);
        int Maximum();
        bool Find(int data);
};