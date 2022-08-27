#include <iostream>
#include <assert.h>
#include "doubly_linked_list.h"

using namespace std;

void print_int(int);
void test1(int);
void check_same(int, int);
int identity(int);
int add_nums(int, int);

bool compare_bigger(int first, int second) {
    return first > second;
}

void check_reversed(int num, int index) {
    assert(index == 9 - num);
}


int main() {

    cout << "Begin Tests on List class:" << endl;
    cout << "Implementation: doubly linked list" << endl << endl;

    
    cout << "Initializing list and Testing length method" << endl;
    List<int> first;
    assert(first.length() == 0);
    cout << "Test successful" << endl << endl;


    cout << "Testing naive traversal method with no elements" << endl; 
    assert(!first.traverse());
    cout << "Test successful" << endl << endl;


    cout << "Testing push method" << endl;
    first.push(5);
    assert(first.length() == 1);
    first.push(2);
    assert(first.length() == 2);
    first.push(9);
    assert(first.length() == 3);
    cout << "Test successful" << endl << endl;


    cout << "Testing naive traversal method with elements" << endl;
    assert(first.traverse());
    cout << "Test successful" << endl << endl;


    cout << "Testing verbose traversal method with true flag" << endl;
    assert(first.traverse(true));
    cout << "Test successful" << endl << endl;


    cout << "Testing verbose traversal method with false flag" << endl;
    assert(first.traverse(false));
    cout << "Test successful" << endl << endl;


    cout << "Testing empty method" << endl;
    List<int> second;
    assert(second.empty());
    assert(!first.empty());
    cout << "Test successful" << endl << endl;

    


    cout << "Testing traversal method with unary function pointer as parameter" << endl; 
    for(int i = 0; i < 10; i++) {
        second.push(i);
    }
    cout << "elements: ";
    assert(second.traverse(print_int));
    cout << endl << "Test successful" << endl << endl;


    cout << "Testing traversal method with binary function pointer as parameter" << endl; 
    assert(second.traverse(check_same));
    cout << "Test successful" << endl << endl;


    cout << "Testing overloaded bracket operator" << endl;
    assert(first[0] == 5);
    assert(first[1] == 2);
    assert(first[2] == 9);
    cout << "Test successful" << endl << endl;


    cout << "Testing at method" << endl;
    assert(first.at(0) == 5);
    assert(first.at(1) == 2);
    assert(first.at(2) == 9);
    cout << "Test successful" << endl << endl;


    cout << "Testing unshift method" << endl;
    first.unshift(23);
    assert(first[0] == 23);
    assert(first.length() == 4);
    cout << "Test successful" << endl << endl;


    cout << "Testing delete_item method" << endl;
    first.delete_item(2);
    assert(first.length() == 3);
    first.delete_item(1);
    assert(first.length() == 2);
    assert(first[0] == 23);
    // cout << first[0] << endl;
    // cout << first[1] << endl;
    // cout << "length = " << first.length() << endl;
    // first.traverse();
    assert(first[1] == 9);
    cout << "Test successful" << endl << endl;


    cout << "Testing pop method" << endl;
    assert(first.pop() == 9);
    assert(first.length() == 1);
    cout << "Test successful" << endl << endl;


    cout << "Testing shift method" << endl;
    assert(first.shift() == 23);
    assert(first.length() == 0);
    cout << "Test successful" << endl << endl;

    
    cout << "Testing map method" << endl;
    List<int> third;
    
    // cout << "Test successful" << endl << endl;
    cout << "Test not written" << endl << endl;

    
    cout << "Testing map method" << endl;
    List<int> fourth;
    cout << "Test not written" << endl << endl;
    // cout << "Test successful" << endl << endl;
    

    cout << "Testing sort method" << endl;
    List<int> five;
    for(int i=9; i >= 0; i--) {
        five.push(i);
    }
    cout << "Original order:\t\t";
    five.traverse(print_int);
    cout << endl;
    cout << "Sorted order:\t\t";
    five.sort();
    five.traverse(print_int);
    cout << endl;
    assert(five.traverse(check_same));
    // cout << "Test not written" << endl << endl;
    cout << "Test successful" << endl << endl;


    cout << "Testing sort method with binary function pointer as parameter" << endl;
    cout << "Reversed order:\t\t";
    five.sort(compare_bigger);
    five.traverse(print_int);
    cout << endl;
    assert(five.traverse(check_reversed));
    // cout << "Test not written" << endl << endl;
    cout << "Test successful" << endl << endl;
    


    cout << "All Tests Passed!" << endl;


    // cout << "Testing sort method" << endl;
    // cout << "Test successful" << endl << endl;
    

    // cout << "Contents of Index 1: " << first.at(0) << endl;

    // should abort with message "Index does not exist"
    // cout << "Contents of Index 2: " << first.get(1) << endl; 


    // cout << "length: " << first.length() << endl;

    // first.delete_item(0);

    // cout << "length: " << first.length() << endl;

    // should abort with message "Index does not exist"
    // first.delete_item(1);

    // first.traverse();
    // first.traverse(print_int);

    // for(int i = 0; i <= 10; i++) {
    //     first.push(i+1);
    // }

    // cout << "print all indicies" << endl;
    // first.traverse();

    // cout << endl << "print contents for each indicie" << endl;
    // first.traverse(print_int);

    // cout << "testing bracket overloading" << endl;

    // cout << "first[0] = 1: " << first[0] << endl;
    // cout << "first[10] = 11: " << first[10] << endl;


    return 0;
}


void print_int(int val) {
    cout << val << "\t";
}


void check_same(int num, int index) {
    assert(num == index);
}


int identity(int num) {
    return num;
}


int add_nums(int num1, int num2) {
    return num1 + num2;
}