// // Stack functions:
// // I chose to create a dynamic stack with a linked list 

// #include <iostream>

// #include "dynamic_stack.h"


// using namespace std;




// template <class N>
// Stack<N>::Stack() {

//     head = new stack;
//     tail = new stack;

//     head->link = tail;
//     tail->link = NULL;

//     // head->data = NULL;
//     // tail->data = NULL;
// }


// template <class N>
// bool Stack<N>::emptyStack() {
//     return head->link == tail;
// }


// template <class N>
// void Stack<N>::push(N data) {
//     stack *newItem = new stack;
    
//     newItem->data = data;

//     newItem->link = head->link;
//     head->link = newItem;
// }


// template <class N>
// N Stack<N>::pop() {
//     stack *c;
//     N data;
//     // N data = NULL;

//     if (!emptyStack()) {
//         c = head->link;
//         data = c->data;
//         head->link = c->link;
//         delete c;
//         return data;
//     }
// }


// template <class N>
// N Stack<N>::peak() {
//     N data;
//     // N data = NULL;

//     if(!emptyStack()) {
//         data = head->link->data;
//         return data;
//     }

// }

// // int main() {

// //     Stack<int> first;

// //     Stack<int*> second;
    

// //     first.push(2);

// //     int test = 1;
// //     int *t = &test;
// //     second.push(t);
// //     cout << test << " " << &test << endl;

// //     // cout << *t << " " << second.pop() << endl;
// //     cout << *second.peak() << " " << second.pop() << endl;
// //     cout << second.pop() << " ";
// //     cout << first.pop();
// //     cout << " testing" << endl;
// //     return 0;
// // }

// // template <class N>
// // N giveN(N data) {
// //     return data;
// // }