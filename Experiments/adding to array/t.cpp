#include<iostream>

using namespace std;

int main() {
    int intArray[7] = {1, 3, 5, 7, 9, 11, 13};
    cout << "hello world" << endl;
    // intArray + 3;
    for (int i = 0; i < 7; i++){
        cout << intArray[i] << "\t";
    }
    intArray - 3;
    cout << endl;
    for (int i = 0; i < 7; i++){
        cout << intArray[i] << "\t";    
    }
    cout << endl;
        cout << *intArray << "\t";
        cout << *(intArray+6) << "\t";
    cout << endl;
    
}