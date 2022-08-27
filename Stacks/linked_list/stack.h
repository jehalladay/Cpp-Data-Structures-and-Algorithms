
#pragma once

using namespace std; 

template <class N>
struct segment {
    N data;
    segment *link;
};

template <class N>
class Stack {
    private:

        // Internal Class Types

        typedef segment<N> stack;

        // Data Elements

        stack *head, *tail;

    public:

        // Constructors

        Stack();

        // Empty Stack, Peek, Pop, and Push

        bool empty();
        N& peek();
        N pop();
        void push(N data);
};


template <class N>
Stack<N>::Stack() {
    head = new stack;
    tail = new stack;

    head->link = tail;
    tail->link = NULL;
}


template <class N>
bool Stack<N>::empty() {
    return head->link == tail;
}


template <class N>
void Stack<N>::push(N data) {
    stack *newItem = new stack;
    
    newItem->data = data;

    newItem->link = head->link;
    head->link = newItem;
}


template <class N>
N Stack<N>::pop() {
    stack *c;
    N data;

    if (empty()) {
        cout << "Stack is empty, cannot pop" << endl;
        throw;
    }
    
    c = head->link;
    data = c->data;
    head->link = c->link;
    delete c;
    
    return data;
} 


template <class N>
N& Stack<N>::peek() {
    if(empty()) {
        cout << "Stack is empty" << endl;
        throw;
    }
    
    return head->link->data;

}
