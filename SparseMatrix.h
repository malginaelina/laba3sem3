#ifndef LABA3SEM3_SPARSEMATRIX_H
#define LABA3SEM3_SPARSEMATRIX_H

#pragma once
#include "Dictionary.h"
#include "Matrix.h"
#include <string>

#include "cstdlib"
using namespace std;

template<class T1, class T2>
class Pair
{
private:
    T1 index_i;
    T2 index_j;
public:
    Pair() = default;
    Pair(T1 index_i, T2 index_j)
    {
        this->index_i = index_i;
        this->index_j = index_j;
    }
    ~Pair() = default;
    T1 getFirst() const
    {
        return this->index_i;
    }
    T2 getSecond() const
    {
        return this->index_j;
    }
    void setFirst(T1 index_i)
    {
        this->index_i = index_i;
    }
    void setSecond(T2 index_j)
    {
        this->index_j = index_j;
    }

    bool operator<(const Pair another)
    {
        if (this->index_i != another.index_i)
            return this->index_i < another.index_i;
        else return this->index_j < another.index_j;
    }
    bool operator>(const Pair another)
    {
        if (this->index_i != another.index_i)
            return this->index_i > another.index_i;
        else return this->index_j > another.index_j;
    }
    bool operator<=(const Pair another)
    {
        if (this->index_i == another.index_i)
            return this->index_j <= another.index_j;
        else return this->index_i <= another.index_i;
    }
    bool operator>=(const Pair another)
    {
        if (this->index_i == another.index_i)
            return this->index_j >= another.index_j;
        return this->index_i >= another.index_i;
    }
    bool operator!=(const Pair another)
    {
        if (this->index_i != another.index_i)
            return this->index_j != another.index_j;
        else return false;
    }
    bool operator==(const Pair another)
    {
        if (this->index_i == another.index_i)
            return this->index_j == another.index_j;
        else return false;
    }

};
template <class T1, class T2>
std::ostream& operator<< (std::ostream &out, const Pair<T1, T2> pair)
{
    return out << "(" << pair.getFirst() << "; " << pair.getSecond() << ")";
}

template <class T>
class SparseMatrix
{
private:
    Dictionary<Pair<int, int>, T> *dict;
    int rows = 0;
    int columns = 0;
public:

    SparseMatrix()
    {
        this->rows = 0;
        this->columns = 0;
        this->dict = new Dictionary<Pair<int, int>, T>(Pair<int,int>(0,0), (T)0, compare);
    }

    SparseMatrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        this->dict = new Dictionary<Pair<int, int>, T>(Pair<int,int>(0,0), (T)0, compare);
    }

    ~SparseMatrix(){
        delete dict;
    }
    
    void Set(int x, int y, T value)
    {
        this->Set(Pair<int, int>(x,y), value);
    }
    void Set(Pair<int, int> pair, T value)

    {
        if (pair.getFirst() >= this->rows or pair.getSecond() >= this->columns)
        {
            throw out_of_range("Index out of range!");
        }
        if (value != (T)0) {
            this->dict->add(pair, value);
        }
        else this->setToZero(pair);
    }
    void setToZero(int x, int y)
    {
        this->setToZero(Pair<int, int>(x,y));
    }
    void setToZero(Pair<int, int> pair)
    {
        if (pair.getFirst() >= this->rows or pair.getSecond() >= this->columns)
        {
            throw out_of_range("Index out of range!");
        }
        if (this->isNotZero(pair)) this->dict->remove(pair);
    }
    bool isNotZero(int x, int y)
    {
        return this->isNotZero(Pair<int,int>(x,y));
    }
    bool isNotZero(Pair<int, int> pair)
    {
        return this->dict->containsKey(pair);
    }
    T Get(int x, int y)
    {
        return this->Get(Pair<int,int>(x,y));
    }
    T Get (Pair<int,int> pair)
    {
        if (pair.getFirst() >= this->rows || pair.getSecond() >= this->columns)
        {
            throw out_of_range("Index out of range!");
        }
        if (this->isNotZero(pair))
        {
            return this->dict->Get(pair);
        } else return (T)0;
    }
    int getAmountOfNonZero()
    {
        return dict->getCount();
    }
    int GetRows()
    {
        return this->rows;
    }
    int GetColumns()
    {
        return this->columns;
    }
    void setRows(int a)
    {
        this->rows = a;
    }
    void setColumns(int a)
    {
        this->columns = a;
    }
    void printAsDict()
    {
        this->dict->print();
    }

};

#endif //LABA3SEM3_SPARSEMATRIX_H
