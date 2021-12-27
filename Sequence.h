#ifndef LABA2SEM3_SEQUENCE_H
#define LABA2SEM3_SEQUENCE_H

#include <stdexcept>
using namespace std;

template <class T>
class Sequence
{
public:
    int size = 0;
public:

    Sequence() = default;

    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(const int index) const = 0;
    virtual int GetSize() const { return this->size; }
    virtual Sequence<T>* GetSubsequence(const int start_index, const int end_index) const = 0;
    virtual void Append(const T &value) = 0;
    virtual void Prepend(const T &value) = 0;
    virtual void Set(int index, const T &data) = 0;
    virtual void Insert(const T &value, const int index) {};
    virtual Sequence<T>* Concat(const Sequence<T>& seq) const = 0;
    virtual bool operator==(const Sequence<T>& seq) {
        if (this->size != seq.size) return false;

        for (int i = 0; i < this->size; i++) {
            if (this->Get(i) != seq.Get(i)) return false;
        }
        return true;
    }
    virtual bool operator==(const Sequence<T>* seq) {
        if (this->size != seq->size) return false;

        for (int i = 0; i < this->size; i++) {
            if (this->Get(i) != seq->Get(i)) return false;
        }
        return true;
    }
    ~Sequence() = default;

    T& operator [] (const int index) const
    {

        if (index < 0 || index >= this->size)
            throw out_of_range("Index out of range!");

        return this->Get(index);

    }
};

#endif //LABA2SEM3_SEQUENCE_H
