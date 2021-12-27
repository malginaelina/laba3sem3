#ifndef LABA3SEM3_GRAPH_H
#define LABA3SEM3_GRAPH_H

#pragma once

#include "DirGraph.h"

using namespace std;

template <class T>
class Graph : virtual public DirGraph<T>
{
public:
    Graph(int size): DirGraph<T>(size) {};
    virtual void changeEdge(int vert1, int vert2, T weight)
    {
        if(vert1 == vert2) throw out_of_range("INCORRECT INDEX");
        this->adjMatrix->Set(vert1, vert2, weight);
        this->adjMatrix->Set(vert2, vert1, weight);
    }
    ArraySequence<int> topologicalSort()
    {
        throw "CANNOT BE TOPOLOGICALLY SORTED";
    }
};
#endif //LABA3SEM3_GRAPH_H
