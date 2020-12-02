#include <iostream>
#include "linked_list.h"

using namespace std;

void print_int(int);



int main() {

    List<int> first;

    first.traverse();

    first.push(5);

    first.traverse();
    first.traverse(print_int);


    cout << "Contents of Index 1: " << first.get(0) << endl;

    // should abort with message "Index does not exist"
    // cout << "Contents of Index 2: " << first.get(1) << endl; 


    cout << "length: " << first.length() << endl;

    first.delete_item(0);

    cout << "length: " << first.length() << endl;

    // should abort with message "Index does not exist"
    // first.delete_item(1);

    first.traverse();
    first.traverse(print_int);

    for(int i = 0; i <= 10; i++) {
        first.push(i+1);
    }

    cout << "print all indicies" << endl;
    first.traverse();

    cout << endl << "print contents for each indicie" << endl;
    first.traverse(print_int);

    cout << "testing bracket overloading" << endl;

    cout << "first[0] = 1: " << first[0] << endl;
    cout << "first[10] = 11: " << first[10] << endl;

    cout << "All Tests Passed!" << endl;

    return 0;
}


void print_int(int val) {
    cout << val << endl;
}