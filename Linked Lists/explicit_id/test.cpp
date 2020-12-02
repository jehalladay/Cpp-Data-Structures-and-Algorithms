#include <iostream>
#include "linked_list.h"

using namespace std;

void print_int(int);



int main() {

    List<int> first;

    first.traverse();
    first.traverse(print_int);

    first.insert(5, 1);

    first.traverse();
    first.traverse(print_int);

    cout << "Does Index 1 exist?: " << first.exists(1) << endl;
    cout << "Does Index 2 exist?: " << first.exists(2) << endl;


    cout << "Contents of Index 1: " << first.get(1) << endl;

    // should abort with message "Index does not exist"
    // cout << "Contents of Index 2: " << first.get(2) << endl; 


    cout << "length: " << first.length() << endl;

    first.delete_item(1);

    cout << "length: " << first.length() << endl;

    // should abort with message "Index does not exist"
    // first.delete_item(2);

    first.traverse();
    first.traverse(print_int);

    return 0;
}


void print_int(int val) {
    cout << val << endl;
}