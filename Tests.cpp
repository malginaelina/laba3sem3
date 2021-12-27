#include <gtest/gtest.h>
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Graph.h"

TEST(DynamiсArray, Test) {
int initArr1[] = { 1,2,3,4,5 };
DynamicArray<int> arr1(initArr1, 5);

EXPECT_EQ(arr1.Get(0), 1);
EXPECT_EQ(arr1.Get(3), 4);
EXPECT_EQ(arr1.Get(4), 5);
EXPECT_EQ(arr1.GetSize(), 5);
}

TEST(LinkedList, Test) {
int initArr1[] = { 1,2,3,5 };
LinkedList<int> list1(initArr1, 4);

EXPECT_EQ(list1.Get(0), 1);
EXPECT_EQ(list1.GetFirst(), 1);
EXPECT_EQ(list1.Get(2), 3);
EXPECT_EQ(list1.Get(3), 5);
EXPECT_EQ(list1.GetLast(), 5);

list1.Prepend(0);
list1.Append(6);
list1.Insert(-1, 0);
list1.Insert(7, 7);
list1.Insert(4, 5);
EXPECT_EQ(list1.Get(0), -1);
EXPECT_EQ(list1.Get(5), 4);

list1.Set(-2, 0);
list1.Set(8, 8);
list1.Set(0, 7);
EXPECT_EQ(list1.Get(0), -2);
}

TEST(ArraySequence, Test) {
int initArr1[] = { 1,2,3,5 };
ArraySequence<int> seq1(initArr1, 4);

EXPECT_EQ(seq1.Get(0), 1);
EXPECT_EQ(seq1.GetFirst(), 1);
EXPECT_EQ(seq1.Get(2), 3);
EXPECT_EQ(seq1.Get(3), 5);
EXPECT_EQ(seq1.GetLast(), 5);
EXPECT_EQ(seq1.GetSize(), 4);
}

TEST(ListSequence, Test) {
int initArr1[] = { 1,2,3,5 };
ListSequence<int> seq1(initArr1, 4);

EXPECT_EQ(seq1.Get(0), 1);
EXPECT_EQ(seq1.GetFirst(), 1);
EXPECT_EQ(seq1.Get(2), 3);
EXPECT_EQ(seq1.Get(3), 5);
EXPECT_EQ(seq1.GetLast(), 5);
EXPECT_EQ(seq1.GetSize(), 4);
}

TEST(Graph, Test){
    auto* gr = new Graph<int>(7);
    gr->changeEdge(0, 1, 15);
    gr->changeEdge(0, 2, 2);
    gr->changeEdge(0, 6, 1);
    gr->changeEdge(2, 3, 3);
    gr->changeEdge(2, 4, 4);
    gr->changeEdge(3, 1, 1);
    gr->changeEdge(4, 1, 2);
    gr->changeEdge(5, 4, 10);
    gr->changeEdge(6, 0, 1);

    ArraySequence<int> *path;
    path = gr->getPath(6, 5);
    EXPECT_EQ(path->Get(0), 6);
    EXPECT_EQ(path->Get(1), 0);
    EXPECT_EQ(path->GetSize(), 5);
    EXPECT_EQ(gr->getPathWeight(path), 17);

    path = gr->getPath(0,2);
    EXPECT_EQ(path->Get(0), 0);
    EXPECT_EQ(path->Get(1), 2);
    EXPECT_EQ(path->GetSize(), 2);
    EXPECT_EQ(gr->getPathWeight(path), 2);
}