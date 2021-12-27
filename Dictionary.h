#ifndef LABA3SEM3_DICTIONARY_H
#define LABA3SEM3_DICTIONARY_H

#pragma once

#include "BinaryTree.h"
#include <stdexcept>

template<class TKey, class TElement>
class PairKE
{
private:
    TKey key;
    TElement element;
public:
    PairKE() = default;
    PairKE(TKey key, TElement element)
    {
        this->key = key;
        this->element = element;
    }
    ~PairKE() = default;
    TElement getElem() const
    {
        return this->element;
    }
    TKey getKey() const
    {
        return this->key;
    }
    void setKey(TKey key)
    {
        this->key = key;
    }
    void setElem(TElement elem)
    {
        this->element = elem;
    }
    bool operator<(const PairKE another)
    {
        return this->key < another.key;
    }
    bool operator>(const PairKE another)
    {
        return this->key > another.key;
    }
    bool operator<=(const PairKE another)
    {
        return this->key <= another.key;
    }
    bool operator>=(const PairKE another)
    {
        return this->key >= another.key;
    }
    bool operator!=(const PairKE another)
    {
        return this->key != another.key;
    }
    bool operator==(const PairKE another)
    {
        return this->key == another.key;
    }
};
template <class TKey, class TElement>
std::ostream& operator<< (std::ostream &out, const PairKE<TKey, TElement> pair)
{
    return out << "<" << pair.getKey() << ", " << pair.getElem() << ">";
}

template <class TKey, class TElement>
class Dictionary
{
protected:

    BinaryTree<PairKE<TKey,  TElement>>* dict;

public:
    Dictionary(const TKey key, const TElement elem, bool (*cmp)(PairKE<TKey, TElement>, PairKE<TKey, TElement>))
    {
        PairKE<TKey, TElement> spair = PairKE<TKey, TElement>(key, elem);
        this->dict = new BinaryTree<PairKE<TKey, TElement>>(spair, cmp);
    }
    ~Dictionary(){
        delete dict;
    }
    int getCount()
    {
        return this->dict->getSize();
    }
    TElement Get(TKey key)
    {
        PairKE<TKey, TElement> spair = PairKE<TKey, TElement>();
        spair.setKey(key);
        if(this->dict->find(spair))
        {
            return this->dict->getElem(dict->search(spair)).getElem();
        }
        throw out_of_range("No element!");
    }
    bool containsKey(TKey key)
    {
        PairKE<TKey, TElement> spair = PairKE<TKey, TElement>();
        spair.setKey(key);
        return this->dict->find(spair);
    }
    void add(TKey key, TElement element)
    {
        PairKE<TKey, TElement> spair = PairKE<TKey, TElement>(key, element);

        if(this->dict->find(spair))
        {
            this->dict->changeElem(this->dict->search(spair)->elem, spair);
        }

        this->dict->add(spair);

    }
    void remove(TKey key)
    {
        PairKE<TKey, TElement> spair = PairKE<TKey, TElement>();
        spair.setKey(key);
        if(this->dict->find(spair))
        {
            this->dict->erase(spair);
            return;
        }
        throw out_of_range("No element!");
    }
    void print()
    {
        this->dict->printAll();
    }

    string toString()
    {
        return this->dict->toString();
    }

    void changeElem(TKey key, TElement elem)
    {
        PairKE<TKey, TElement> pair = PairKE<TKey, TElement>(key, elem);
        this->dict->setElem(this->dict->search(pair), pair);
    }
};

#endif //LABA3SEM3_DICTIONARY_H
