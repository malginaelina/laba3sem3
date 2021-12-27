#include <iostream>
#include "Interface.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    int test;
    cout << ("Show tests? 1 - yes, 0 - no") << endl;
    cin >> test;
    if (test == 1){
        printf("Running main() from %s\n", __FILE__);
        testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
        cout << endl;
    }

    int choose = 0;

    cout << "1 - directed graph" << endl;
    cout << "2 - undirected graph" << endl;
    cout << "0 - exit" << endl;
    cin >> choose;
    cout << endl;

    switch(choose)
    {
        case 0:
            break;
        case 1:
            interfaceDirGraph();
            break;
        case 2:
            interfaceGraph();
            break;
        default:
            break;
    }

    return 0;
}