#ifndef LABA2SEM3_LINKEDLISTSEQUENCE_H
#define LABA2SEM3_LINKEDLISTSEQUENCE_H
#include "Sequence.h"
#include "LinkedList.h"
#include <stdexcept>

template <typename T>
class ListSequence : public Sequence<T> {
protected:
    LinkedList<T>* list;
public:
    ListSequence() {
        this->list = new LinkedList<T>();
        this->size = 0;
    }

    ListSequence(const ListSequence<T>& seq) {
        this->list = new LinkedList<T>(*seq.list);
        this->size = seq.size;
    }

    ListSequence(LinkedList<T>* list) {
        this->list = list;
        this->size = list->GetSize();
    }

    ListSequence(T* data, int size) {
        this->list = new LinkedList<T>(data, size);
        this->size = size;
    }

    ListSequence(int size) {
        this->list = new LinkedList<T>(size);
        this->size = size;
    }

    ~ListSequence() {
        delete this->list;
        this->size = 0;
    }


    T GetFirst() const override {
        return this->list->GetFirst();
    }

    T GetLast() const override {
        return this->list->GetLast();
    }

    T Get(int index) const override {
        return this->list->Get(index);
    }


    ListSequence<T>* GetSubsequence(int start, int end) const override {
        LinkedList<T>* subList = this->list->GetSublist(start, end);
        auto* seq = new ListSequence<T>(subList);
        return seq;
    }

    void Set(int index, const T &data) override {
        this->list->Set(data, index);
    }

    void Append(const T& item) override {
        this->list->Append(item);
        this->size++;
    }

    void Prepend(const T& item) override {
        this->list->Prepend(item);
        this->size++;
    }

    void Insert(const T& item, int index) override {
        this->list->Insert(item, index);
        this->size++;
    }

    T& operator [] (const int index) const
    {

        if (index < 0 || index >= this->size)
            throw out_of_range("Index out of range!");

        return this->Get(index);

    }

    int GetSize() {
        return this->size;
    }
    ListSequence<T>* Concat(const Sequence<T>& seq) const override {
        auto* newSequence = new ListSequence<T>();

        for (int i = 0; i < this->size; i++)
            newSequence->Append(this->Get(i));

        for (int i = 0; i < seq.GetSize(); i++)
            newSequence->Append(seq.Get(i));

        return newSequence;
    }
};


template <class T>
std::ostream& operator<< (std::ostream& out, const ListSequence<T>* seq){
    out << "<";
    for (int i = 0; i < seq->GetSize(); i++) {
        out << seq->Get(i);
    }
    out << ">";
    return out;
};

template <class T>
std::ostream& operator<< (std::ostream& out, const ListSequence<T> seq) {
    out << "<";
    for (int i = 0; i < seq.GetSize(); i++) {
        out << seq.Get(i);
    }
    out << ">";
    return out;
};


#endif //LABA2SEM3_LINKEDLISTSEQUENCE_H
