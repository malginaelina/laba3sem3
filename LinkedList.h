#ifndef LABA2SEM3_LINKEDLIST_H
#define LABA2SEM3_LINKEDLIST_H

#pragma once
#include <stdexcept>

using namespace std;

template <class T>
class LinkedList
{

private:

    struct Node
    {
        T data;
        Node* next = nullptr;
    };

    int size = 0;
    Node* head = nullptr;

public:

    LinkedList() : size(0){
        this->size = 0;
        this->head = nullptr;
    };

    LinkedList(int size) : LinkedList() {
        if (size < 0) throw length_error("Negative size!");

        Node** tmp = &(this->head);
        for (int i = 0; i < size; i++) {
            *tmp = new Node;
            (*tmp)->data = T();
            tmp = &((*tmp)->next);
        }
        this->size = size;
    }

    LinkedList(const T* data, const int size) : LinkedList()
    {
        if (size < 0)
            throw out_of_range("Negative size!");

        this->size = size;
        for (int i = 0; i < size; i++) {
            this->Append(data[i]);
        }
    }

    LinkedList(const LinkedList<T>& list) {
        for (int i = 0; i<list.GetSize(); i++) {
            this->Append(list.Get(i));
        }
    }

    ~LinkedList() {
        Node* ptr = this->head;
        Node* next;
        while (ptr != nullptr) {
            next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }

    T GetFirst() const
    {
        if (this->size == 0)
            throw length_error("Zero size!");
        return this->head->data;
    }

    T GetLast() const
    {
        if (this->size == 0)
            throw length_error("Zero size!");
        Node* ptr = this->head;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        return ptr->data;
    }

    T Get(const int index) const
    {
        if (index < 0 || index >= this->size)
            throw out_of_range("Index out of range!");
        Node* ptr = this->head;
        for (int i = 0; i < index; i++)
            ptr = ptr->next;
        return ptr->data;
    }

    LinkedList<T>* GetSublist(const int start_index, const int end_index) const
    {
        if (start_index < 0 || start_index >= this->size) throw out_of_range("Index out of range!");
        if (end_index < 0 || end_index > this->size) throw out_of_range("Index out of range!");
        if (start_index > end_index) throw logic_error("Wrong order!");

        auto* list = new LinkedList<T>();
        for (int i = start_index; i <= end_index; i++) {
            list->Append(this->Get(i));
        }
        list->size = end_index - start_index + 1;
        return list;

    }

    int GetSize() const
    {
        return  this->size;
    }

    void Append(const T &data)
    {
        Node** ptr = &(this->head);
        while (*ptr != nullptr)
            ptr = &((*ptr)->next);
        (*ptr) = new Node;
        (*ptr)->data = data;
        this->size++;
    }

    void Prepend(const T &data)
    {
        auto* ptr = new Node{ data, this->head };
        this->head = ptr;

        this->size++;

    }

    void Set(const T& data, int index) {
        if (index < 0 || index >= this->size)
            throw out_of_range("Index out of range!");
        Node* ptr = this-> head;
        for (int i = 0; i < index; i++){
            ptr = ptr->next;
        }
        ptr->data = data;
    }

    void Insert(const T& data, const int index) {
        if (index < 0 || index > this->size)
            throw out_of_range("Index out of range!");

        if (index == 0)
        {
            this->Prepend(data);
        }
        else
        {
            auto* ptr = new Node{ data, this->head };
            auto* newptr = new Node{ data, this->head };
            for (int i = 0; i < index ; i++)
                ptr = ptr->next;
            newptr->next = ptr->next;
            ptr->next = newptr;
            this->size++;
        }
    }

    LinkedList<T>* Concat(const LinkedList<T> &list)
    {
        Node* ptr1 = this->head;
        Node* ptr2 = list.head;

        auto* newList = new LinkedList<T>();
        Node** ptr = &(newList->head);
        while (ptr1 != nullptr) {
            *ptr = new Node{
                    ptr1->data,
                    ptr1->next
            };

            ptr1 = ptr1->next;
            ptr = &((*ptr)->next);
        }
        while (ptr2 != nullptr) {
            *ptr = new Node{ptr2->data,ptr2->next};
            ptr2 = ptr2->next;
            ptr = &((*ptr)->next);
        }

        newList->size = this->size + list.size;
        return newList;
    }


    T& operator [] (const int index) const
    {
        if (this->head == nullptr || index < 0 || index >= this->size)
            throw out_of_range("Index out of range!");
        Node* ptr = this->head;
        for (int i = 0; i < index; i++)
            ptr = ptr->next;

        return ptr->data;
    }

    bool operator==(const LinkedList<T>& list) const {
        if (this->size != list.size) return false;

        for (int i = 0; i < this->size; i++) {
            if (this->Get(i) != list.Get(i)) return false;
        }
        return true;
    }
};

template <class T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T> seq) {
    out << "<";
    for (int i = 0; i < seq.GetSize(); i++) {
        out << seq.Get(i);
    }
    out << ">";
    return out;
};

#endif //LABA2SEM3_LINKEDLIST_H
