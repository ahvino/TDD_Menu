#include "BST.h"
#include <stdio.h>
#include <iostream>

/*
* Need to add the following:
*   ADD
*   Remove
*   In Order Traverse
*   Maximum
*   Find
*/


TNode* BST::GetRoot()
{
    return root;
}

bool BST::Find(int val)
{
    int found = false;
    TNode* curr = root;
    if (curr == nullptr)
    {
        return found;
    }

    while (curr != nullptr)
    {
        if (val == curr->data)
        {
            found = true;
            printf("We found the value '%i' in the Tree.\n", val);
            return found;
        }
        else if (val < curr->data)
        {
            if (curr->left != nullptr)
            {
                curr = curr->left;
            }
            else
            {
                printf("We did not find the value '%i' in the Tree.\n", val);

                return found;
            }
        }
        else
        {
            if (curr->right != nullptr)
            {
                curr = curr->right;
            }
            else
            {
                printf("We did not find the value '%i' in the Tree.\n", val);

                return found;
            }
        }
    }


    return found;
}

int BST::Maximum()
{
    int val = -1;

    TNode* curr = root;
    if (root == nullptr)
    {
        printf("No maximum can be found in an empty tree.\n");
        return val;
    }
    while (curr != nullptr)
    {
        if (curr->right != nullptr)
        {
            curr = curr->right;
        }
        else
        {
            val = curr->data;
            printf("Maximum value is '%i'\n", val);
            return val;
        }
    }

    return val;
}

/// <summary>
/// check if the left or right equals the data first before moving forward
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
BST BST::Remove(int data)
{
    BST * temp = nullptr;

    TNode* curr = root;
    if (root == nullptr)
    {
        printf("Unable to remove an item from an empty tree");
        return * temp;
    }

    while (curr != nullptr)
    {
        //founbd the node to delete
        if (curr->data == data)
        {
            if (curr->right != nullptr)
            {
                //this will overwrite the current node that
                if (curr->left != nullptr)
                {
                    curr->right->left = curr->left;
                    curr = curr->right;
                }
                else
                {
                    curr = curr->right;
                }
            }
            else
            {
                if (curr->left != nullptr)
                {
                    curr = curr->left->left;
                }
                else
                {
                    curr = nullptr;
                }
            }
        }
        else if (data < curr->data)
        {
            if (curr->left != nullptr)
            {
                curr = curr->left;
            }
            else
            {
                printf("This value is not found in the tree.");
            }
        }
        else
        {
            if (curr->right != nullptr)
            {
                curr = curr->right;
            }
            else
            {
                printf("This value is not found in the tree.");
            }
        }
    }
    temp = this;
}


void BST::Add(int data)
{
    TNode* node = new TNode(data);

    if (root == nullptr)
    {
        root = node;
        return;
    }

    else
    {
        TNode* curr = root;
        while (curr != nullptr)
        {
            if (data == curr->data)
            {
                printf("The tree already contains a node with the value '%i' \n", data);
                
                return;
            }
            else if (data < curr->data)
            {
                if (curr->left == nullptr)
                {
                    curr->left = node;
                    return;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->right == nullptr)
                {
                    curr->right = node;
                    return;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
    }

    return;
}

void BST::InOrderTraverse(TNode* curr)
{
    if (curr == nullptr)
    {
        return;
    }
    else
    {
        InOrderTraverse(curr->left);
        std::cout << curr->data << std::endl;
        InOrderTraverse(curr->right);
    }
}