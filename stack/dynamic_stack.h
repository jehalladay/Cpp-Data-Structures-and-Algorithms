
#pragma once

using namespace std; 

template <class N>
struct slice {
    N data;
    slice *link;
};

template <class N>
class Stack {
    private:
        typedef slice<N> stack;
        stack *head, *tail;
        bool emptyStack() {
            return head->link == tail;
        };
    public:
        // constructors
        Stack(){
            head = new stack;
            tail = new stack;

            head->link = tail;
            tail->link = NULL;
        };

        // Peek, Pop, and Push
        N peek(){
            N data = NULL;

            if(!emptyStack()) {
                data = head->link->data;
            }

            return data;
        };

        N pop(){
            stack *c;
            N data = NULL;

            if (!emptyStack()) {
                c = head->link;
                data = c->data;
                head->link = c->link;
                delete c;
            }
            return data;
        };

        void push(N data){
            stack *newItem = new stack;
            
            newItem->data = data;

            newItem->link = head->link;
            head->link = newItem;
        };
};