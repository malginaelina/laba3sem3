#ifndef LABA3SEM3_DIRGRAPH_H
#define LABA3SEM3_DIRGRAPH_H

#include "ArraySequence.h"
#include "Matrix.h"
#include "SparseMatrix.h"

using namespace std;

template <class T>
class DirGraph
{
protected:
    SparseMatrix<T> *adjMatrix;
private:
    void topologicalSortHelp(int v, bool visited[], ArraySequence<int> *stack)
    {
        visited[v] = true;
        for(int i = 0; i < this->getSize(); i++)
        {
            if(this->adjMatrix->Get(v, i) != 0)
            {
                if(!visited[i]) this->topologicalSortHelp(i, visited, stack);
            }
        }
        stack->Prepend(v);
    }
public:

    DirGraph()
    {
        this->adjMatrix = new SparseMatrix<T>();
    }

    DirGraph(int size)
    {
        this->adjMatrix = new SparseMatrix<T>(size, size);
    }

    ~DirGraph(){
        delete adjMatrix;
    }

    virtual void changeEdge(int vert1, int vert2, T weight)
    {
        if(vert1 == vert2) throw out_of_range("Wrong index!");
        this->adjMatrix->Set(vert1, vert2, weight);

    }

    int getSize()
    {
        return this->adjMatrix->GetRows();
    }

    T getPathWeight(int ver1, int ver2)
    {
        return this->adjMatrix->Get(ver1, ver2);
    }

    ArraySequence<int>* getPath(int vert1, int vert2)
    {
        const int INF = INT_MAX;
        ArraySequence<int> dist(this->getSize());
        ArraySequence<bool> visited(this->getSize());
        ArraySequence<int> parent(this->getSize());
        for(int i = 0; i < this->getSize(); i++)
        {
            dist.Set(i, INF);
            visited.Set(i, false);
            parent.Set(i, -1);
        }
        int min;
        int index_min = 0;
        int temp;
        dist.Set(vert1, 0);

        for(int i = 0; i < this->getSize(); i++)
        {
            min = INF;
            for(int j = 0; j < this->getSize(); ++j)
            {
                if(!visited.Get(j) && dist.Get(j) < min)
                {
                    min = dist.Get(j);
                    index_min = j;
                }
            }
            visited.Set(index_min, true);
            for (int j = 0; j < this->getSize(); ++j)
            {
                if (adjMatrix->Get(index_min, j) > 0)
                {
                    temp = min + adjMatrix->Get(index_min, j);
                    if (temp < dist.Get(j))
                    {
                        dist.Set(j, temp);
                        parent.Set(j, index_min);
                    }
                }
            }
            if (visited.Get(vert2)) break;
        }
        auto *path = new ArraySequence<int>();
        if (parent.Get(vert2) == -1)
        {
            path->Append(-1);
            return path;
        }
        for(int i = vert2; i != -1; i = parent.Get(i))
            path->Prepend(i);
        return path;
    }

    T getPathWeight(ArraySequence<int> *path)
    {
        T result = 0;
        for (int i = 0; i < path->GetSize() - 1; i++)
        {
            if (this->adjMatrix->Get(path->Get(i), path->Get(i + 1)) == 0) throw invalid_argument("Incorrect path!");
            result += this->adjMatrix->Get(path->Get(i), path->Get(i + 1));
        }
        return result;
    }

    ArraySequence<int>* getTopologicalSort()
    {
        ArraySequence<int> *stack;
        stack = new ArraySequence<int>();
        bool *visited = new bool[this->getSize()];
        for (int i = 0; i < this->getSize(); i++)
            visited[i] = false;
        for (int i = 0; i < this->getSize(); i++)
            if (!visited[i])
            {
                this->topologicalSortHelp(i, visited, stack);
            }
        return stack;
    }
};

#endif //LABA3SEM3_DIRGRAPH_H
