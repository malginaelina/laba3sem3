#ifndef LABA3SEM3_BINARYTREE_H
#define LABA3SEM3_BINARYTREE_H

#include <string>
#include "cstdlib"
#include <iostream>

using namespace std;

template <class T>
bool compare(T a, T b)
{
    return a < b;
}

template <class T>
class BinaryTree
{
private:
    struct node
    {
        node* parent = nullptr;
        node* left = nullptr;
        node* right = nullptr;
        T elem;
    };
    node* root = nullptr;
    int size = 0;
    bool (*cmp)(T, T) = compare;

private:
    void destructor(node* curr)
    {
        if (curr)
        {
            destructor(curr->left);
            destructor(curr->right);
            delete curr;
        }
    }
    void erase_(node* delNode_)
    {
        node* delNode = delNode_;
        if (delNode == nullptr) return;
        if (delNode->right == nullptr && delNode->left == nullptr)
        {
            if (delNode == this->root)
            {
                delete delNode;
                this->root = nullptr;
            }
            else
            {
                if (delNode->parent->right == delNode) delNode->parent->right = nullptr;
                else delNode->parent->left = nullptr;
                delete delNode;
            }
        }
        else if (delNode->right != nullptr && delNode->left == nullptr)
        {
            if (delNode == this->root)
            {
                delNode->right->parent = nullptr;
                this->root = delNode->right;
            }
            else
            {
                if (delNode->parent->left == delNode) delNode->parent->left = delNode->right;
                else delNode->parent->right = delNode->right;
                delNode->right->parent = delNode->parent;
            }
            delete delNode;
        }
        else if (delNode->right == nullptr && delNode->left != nullptr)
        {
            if (delNode == this->root)
            {
                delNode->left->parent = nullptr;
                this->root = delNode->left;
            } else
            {
                if (delNode->parent->left == delNode) delNode->parent->left = delNode->left;
                else delNode->parent->right = delNode->left;
                delNode->left->parent = delNode->parent;
            }
            delete delNode;
        }
        else if (delNode->right != nullptr && delNode->left != nullptr)
        {
            node* swapNode = next(delNode);
            T tmp_value = delNode->elem;
            delNode->elem = swapNode->elem;
            swapNode->elem = tmp_value;
            this->erase_(swapNode);
        }
    }

    node* next(node* nodePtr)
    {
        if (nodePtr == nullptr) return nullptr;
        if (nodePtr->right != nullptr)
        {
            nodePtr = nodePtr->right;
            while (nodePtr->left != nullptr)
            {
                nodePtr = nodePtr->left;
            }
            return nodePtr;
        }
        else if (nodePtr->parent->left == nodePtr)
        {
            return nodePtr->parent;
        }
        else return nullptr;
    }

    void printAll(node* nodePtr)
    {
        if (nodePtr == nullptr) return;
        if (nodePtr->left != nullptr)
        {
            printAll(nodePtr->left);
        }
        cout << nodePtr->elem;
        cout << endl;
        if (nodePtr->right != nullptr)
        {
            printAll(nodePtr->right);
        }
    }

public:

    BinaryTree(){
        this->root = nullptr;
        this->size = 0;
        this->cmp = cmp;
    }

    BinaryTree(const T key, bool (*cmp) (T, T))
    {
        this->root = new node;
        this->root->elem = key;
        this->size = 1;
        this->cmp = cmp;
    }

    BinaryTree(const BinaryTree<T>& tree)
    {
        this->root = tree->root;
        this->root->elem = tree->root->elem;
        this->size = tree->size;
        this->cmp = tree->cmp;
    }

    void add(const T elem)
    {
        node* nodePtr = this->root;
        this->size++;
        if (this->root == nullptr){
            this->root = new node;
            this->root->elem = elem;
            return;
        }
        while (nodePtr != nullptr)
        {
            if (this->cmp(nodePtr->elem, elem))
            {
                if (nodePtr->right != nullptr)
                {
                    nodePtr = nodePtr->right;
                }
                else
                {
                    nodePtr->right = new node;
                    nodePtr->right->elem = elem;
                    nodePtr->right->parent = nodePtr;
                    break;
                }
            }
            else
            {
                if (nodePtr->left != nullptr)
                {
                    nodePtr = nodePtr->left;
                }
                else
                {
                    nodePtr->left = new node;
                    nodePtr->left->elem = elem;
                    nodePtr->left->parent = nodePtr;
                    break;
                }
            }
        }
    }

    T minimum()
    {
        if (this->root == nullptr) return T(0);
        node* nodePtr = this->root;
        while (nodePtr->left != nullptr)
        {
            nodePtr = nodePtr->left;
        }
        return nodePtr->elem;
    }
    T maximum()
    {
        node* nodePtr = this->root;
        if (this->root == nullptr)
        {
            return T(0);
        }
        while (nodePtr->right != nullptr)
        {
            nodePtr = nodePtr->right;
        }
        return nodePtr->elem;
    }

    node* search(const T elem)
    {
        node* nodePtr = this->root;
        while (nodePtr != nullptr)
        {
            if (this->cmp(nodePtr->elem, elem))
            {
                nodePtr = nodePtr->right;
            }
            else if (this->cmp(elem, nodePtr->elem))
            {
                nodePtr = nodePtr->left;
            }
            else return nodePtr;
        }
        return nullptr;
    }

    bool find(const T key)
    {
        if(search(key) != nullptr)
        {
            return true;
        }
        else return false;
    }

    void changeElem(const T elem, const T newElem){
        node* nodePtr = search(elem);
        this->setElem(nodePtr, newElem);
    }

    int getSize() const
    {
        return this->size;
    }

    T getElem(node* cur)
    {
        return cur->elem;
    }

    void setElem(node* cur, T elem)
    {
        cur->elem = elem;
    }

    void erase(T elem)
    {
        node* delNode = search(elem);
        if(delNode == nullptr) return;

        erase_(delNode);
        --this->size;
    }

    void printAll()
    {
        if (this->root == nullptr) return;
        printAll(this->root);
        cout << endl;
    }

    ~BinaryTree()
    {
        destructor(this->root);
        size = 0;
    }
};

#endif //LABA3SEM3_BINARYTREE_H
