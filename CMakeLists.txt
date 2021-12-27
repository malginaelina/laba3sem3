cmake_minimum_required(VERSION 3.21)
project(laba3sem3)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)
add_executable(laba3sem3 main.cpp Graph.h ArraySequence.h Sequence.h LinkedList.h DynamicArray.h LinkedListSequence.h Interface.h DirGraph.h Matrix.h Tests.cpp SparseMatrix.h Dictionary.h BinaryTree.h)
include_directories(googletest/googletest/include)
target_link_libraries(laba3sem3 gtest gtest_main)