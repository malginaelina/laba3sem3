#ifndef LABA2SEM3_DYNAMICARRAY_H
#define LABA2SEM3_DYNAMICARRAY_H

#pragma once
#include <stdexcept>

template <typename T> class DynamicArray {
private:
    T* data = nullptr;
    int size = 0;
public:
    DynamicArray() : size(0) {}

    DynamicArray(int size) : size(size) {
        if (size < 0)
            throw length_error("Negative size!");
        this->data = new T[size];
    }

    DynamicArray(T* data, int size) : DynamicArray(size) {
        for (int i = 0; i < size; i++)
            this->data[i] = data[i];
    }

    DynamicArray(const DynamicArray<T>& array, int size) : DynamicArray(size) {
        if (size > array.size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; i++)
            this->data[i] = array.data[i];
    }

    DynamicArray(const DynamicArray<T>& array) :
            DynamicArray(array.data, array.size) {}

    ~DynamicArray() {
        delete[] this->data;
        this->size = 0;
    }


    T Get(int index) const {
        if (index < 0 || index >= this->size)
            throw out_of_range("Index out of range!");
        return this->data[index];
    }

    int GetSize() const {
        return this->size;
    }

    void Set(const T& value, int index) {
        if (index < 0 || index > this->size)
            throw out_of_range("Index out of range!");
        this->data[index] = value;
    }

    void Resize(int size) {
        if (size < 0)
            throw length_error("Negative size!");
        T* newData = new T[size];
        int tempsize = this->size > size ? size : this->size;
        for (int i = 0; i < tempsize; i++)
            newData[i] = data[i];
        delete[] data;
        this->data = newData;
        this->size = size;
    }

    T& operator [] (const int index) const
    {
        if (index < 0 || index >= this->size)
            throw out_of_range("Index out of range!");

        return this->data[index];
    }

    bool operator==(const DynamicArray<T>& arr) const {
        if (this->size != arr.size) return false;

        for (int i = 0; i < this->size; i++)
            if (this->Get(i) != arr.Get(i)) return false;

        return true;
    }

};

#endif //LABA2SEM3_DYNAMICARRAY_H
