#include <iostream>
#include <set>
// #include "set.h"


using namespace std;

void print_int(int);



int main() {
    cout << "Begin Tests on class Set:" << endl;

    set<int> intSet;

    intSet.insert(2);
    intSet.insert(7);
    intSet.insert(7);
    intSet.insert(7);
    intSet.insert(1);
    intSet.insert(3);
    cout << intSet.size() << endl;

    for (set<int>::iterator it=intSet.begin(); it!=intSet.end(); ++it)
        cout << *it << ' ';
    cout<<"\n";



    return 0;
}


void print_int(int val) {
    cout << val << endl;
}