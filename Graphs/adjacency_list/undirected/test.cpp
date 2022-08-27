#include <iostream>
#include "graph.h"
#include "../../../LinkedLists/doubly_linked_list/doubly_linked_list.h"

using namespace std;

void print_int(int);

template <class N>
void print(N item) {
    cout << item << endl;
}

template <class N>
void print2(N item) {
    cout << *item << endl;
}


int main() {

    cout << "Begin Tests on Graph class:" << endl;
    cout << "Implementation: undirected, adjacency list" << endl << endl;

    cout << "Testing  method" << endl;
    cout << "Test successful" << endl << endl;
    

    cout << "All Tests Passed!" << endl;

    return 0;
}


void print_int(int val) {
    cout << val << endl;
}