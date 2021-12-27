#ifndef LABA3SEM3_INTERFACE_H
#define LABA3SEM3_INTERFACE_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "Graph.h"
#include <iomanip>

using namespace std;

void printMatrix(DirGraph<int> *gr){
    for(int i = 0; i < gr->getSize() + 1; i++)
    {
        for (int j = 0; j < gr->getSize() + 1; j++)
        {
            if (i == 0 && j == 0)
                cout << setw(2) << '#' << " ";
            else if (i == 0)
                cout << setw(2) << j - 1 << " ";
            else if (j == 0)
                cout << setw(2) << i - 1 << " ";
            else
                cout << setw(2) << gr->getPathWeight(i - 1, j - 1) << " ";
        }
        cout << "\n";
    }
}

Graph<int>* getDefaultGraph()
{
    auto *gr = new Graph<int>(8);
    gr->changeEdge(0, 1, 7);
    gr->changeEdge(0, 2, 9);
    gr->changeEdge(1, 2, 3);
    gr->changeEdge(1, 4, 5);
    gr->changeEdge(2, 3, 2);
    gr->changeEdge(3, 4, 5);
    gr->changeEdge(3, 7, 4);
    gr->changeEdge(4, 5, 9);
    gr->changeEdge(1, 5, 4);
    gr->changeEdge(5, 6, 3);
    gr->changeEdge(6, 7, 4);
    return gr;
}
DirGraph<int>* getDefaultDirGraph()
{
    auto *gr = new DirGraph<int>(8);
    gr->changeEdge(0, 1, 5);
    gr->changeEdge(0, 2, 9);
    gr->changeEdge(1, 2, 3);
    gr->changeEdge(1, 4, 6);
    gr->changeEdge(2, 3, 2);
    gr->changeEdge(3, 4, 5);
    gr->changeEdge(3, 7, 4);
    gr->changeEdge(4, 5, 9);
    gr->changeEdge(1, 5, 8);
    gr->changeEdge(5, 6, 3);
    gr->changeEdge(6, 7, 1);
    return gr;
}
void editGraph(Graph<int> *gr)
{
    int choose = 0;
    int vert1 = 0;
    int vert2 = 0;
    int weight = 0;
    while(true)
    {
        cout << "Adjacency matrix:" << endl;
        printMatrix(gr);
        cout << endl;
        cout << "1 - change an edge" << endl;
        cout << "2 - continue" << endl;
        cin >> choose;
        cout << endl;
        switch(choose)
        {
            case 1:
                cout << "The first vertex" << endl;
                cin >> vert1;
                cout << endl;
                cout << "The second vertex" << endl;
                cin >> vert2;
                cout << endl;
                cout << "The weight of the edge" << endl;
                cin >> weight;
                cout << endl;
                gr->changeEdge(vert1, vert2, weight);
                break;
            case 2:
                return;
            default:
                cout << "Wrong number!" << endl;
                break;
        }
    }
}
void editDirGraph(DirGraph<int> *gr)
{
    int choose = 0;
    int vert1 = 0;
    int vert2 = 0;
    int weight = 0;
    while(true)
    {
        cout << "Adjacency matrix:" << endl;
        printMatrix(gr);
        cout << endl;
        cout << "1 - change an edge" << endl;
        cout << "2 - continue" << endl;
        cin >> choose;
        cout << endl;
        switch(choose)
        {
            case 1:
                cout << "The first vertex" << endl;
                cin >> vert1;
                cout << endl;
                cout << "The second vertex" << endl;
                cin >> vert2;
                cout << endl;
                cout << "The weight of the edge" << endl;
                cin >> weight;
                cout << endl;
                gr->changeEdge(vert1, vert2, weight);
                break;
            case 2:
                return;
            default:
                cout << "Wrong number!" << endl;
                break;
        }
    }
}

void interfaceGraph()
{
    int choose = 0;
    int i = 0;
    int j = 0;
    int vert1 = 0;
    int vert2 = 0;
    int weight = 0;
    Graph<int> *gr;
    ArraySequence<int> *path;

    cout << "1 - default graph" << endl;
    cout << "2 - enter graph" << endl;
    cout << "0 - exit" << endl;
    cin >> choose;
    cout << endl;
    switch (choose)
    {
        case 0:
            return;
        case 1:
            gr = getDefaultGraph();
            break;
        case 2:
            cout << "Enter a number of vertexes" << endl;
            cin >> choose;
            cout << endl;
            gr = new Graph<int>(choose);
            break;
        default:
            cout << "Wrong number!" << endl;
            break;
    }
    editGraph(gr);
    while(true)
    {
        cout << "1 - the path on the graph:" << endl;
        cout << "2 - change an edge" << endl;
        cout << "0 - exit" << endl;
        cin >> choose;
        cout << endl;
        switch(choose)
        {
            case 0:
                return;
            case 1:
                cout << "The first vertex:" << endl;
                cin >> i;
                cout << endl;
                cout << "The last vertex" << endl;
                cin >> j;
                cout << endl;
                path = gr->getPath(i, j);
                cout << "The shortest path:" << endl;
                for (int i = 0; i < path->GetSize(); i++)
                    cout << path->Get(i) << " ";
                cout << endl;
                cout << "Path's weight: " << gr->getPathWeight(path) << endl;
                break;
            case 2:
                cout << "The first vertex" << endl;
                cin >> vert1;
                cout << endl;
                cout << "The second vertex" << endl;
                cin >> vert2;
                cout << endl;
                cout << "The weight of the edge" << endl;
                cin >> weight;
                cout << endl;
                gr->changeEdge(vert1, vert2, weight);
                cout << "Adjacency matrix:" << endl;
                printMatrix(gr);
                cout << endl;
                break;
            default:
                cout << "Wrong number!" << endl;
                break;
        }
    }
}
void interfaceDirGraph()
{
    int choose = 0;
    int i = 0;
    int j = 0;
    int vert1 = 0;
    int vert2 = 0;
    int weight = 0;
    DirGraph<int> *gr;
    ArraySequence<int> *path;
    ArraySequence<int> *ts;

    while(true)
    {
        cout << "1 - default directed graph" << endl;
        cout << "2 - enter directed graph" << endl;
        cout << "0 - exit" << endl;
        cin >> choose;
        cout << endl;

        switch (choose)
        {
            case 0:
                return;
            case 1:
                gr = getDefaultDirGraph();
                break;
            case 2:
                cout << "Number of vertexes" << endl;
                cin >> choose;
                cout << endl;
                gr = new DirGraph<int>(choose);
                break;
            default:
                cout << "Wrong number!" << endl;
                break;
        }
        editDirGraph(gr);
        while(true)
        {
            cout << "1 - the path on the directed graph" << endl;
            cout << "2 - topological sort" << endl;
            cout << "3 - change an edge" << endl;
            cout << "0 - exit" << endl;
            cin >> choose;
            cout << endl;
            switch(choose)
            {
                case 0:
                    return;
                case 1:
                    cout << "The first vertex:" << endl;
                    cin >> i;
                    cout << endl;
                    cout << "The last vertex" << endl;
                    cin >> j;
                    cout << endl;
                    path = gr->getPath(i, j);
                    cout << "The shortest path:" << endl;
                    for (int i = 0; i < path->GetSize(); i++)
                        cout << path->Get(i) << " ";
                    cout << endl;
                    cout << "Path's weight: " << gr->getPathWeight(path) << endl;
                    break;
                case 2:
                    ts = gr->getTopologicalSort();
                    cout << "The topological sort:" << endl;
                    for (int i = 0; i < ts->GetSize(); i++)
                        cout << ts->Get(i) << " ";
                    cout << endl;
                    break;
                case 3:
                    cout << "The first vertex" << endl;
                    cin >> vert1;
                    cout << endl;
                    cout << "The second vertex" << endl;
                    cin >> vert2;
                    cout << endl;
                    cout << "The weight of the edge" << endl;
                    cin >> weight;
                    cout << endl;
                    gr->changeEdge(vert1, vert2, weight);
                    cout << "Adjacency matrix:" << endl;
                    printMatrix(gr);
                    cout << endl;
                    break;
                default:
                    cout << "Wrong number!" << endl;
                    break;
            }
        }
    }
}


#endif //LABA3SEM3_INTERFACE_H
