#pragma once

#include <iostream>
#include <iomanip>

using namespace std; 

template <class N>
struct list_link {
    int id;
    list_link *link;
    N data;
};

template <class N>
class List {
    private:
        typedef list_link<N> element;
        element *head, *tail;
        int _length;
    public:
        // constructors

        List();

        // empty, traverse, push, unshift, delete, pop, shift, get

        int length();
        bool empty();
        void traverse();
        bool traverse(void(*)(N));
        void push(N);
        void unshift(N);
        void delete_item(int);
        N pop();
        N shift();
        N& get(int);

        // overloaded operators

        N& operator [] (int i);
};



template <class N>
List<N>::List() {

    head = new element;
    tail = new element;

    head->link = tail;
    tail->link = NULL;

    head->id = -1;
    tail->id = 9999999;

    _length = 0;
}


template <class N>
int List<N>::length() {
    return _length; 
}


template <class N>
bool List<N>::empty() {
    return head->link == tail;
}


template <class N>
void List<N>::delete_item(int id) {
    element *prior, *next, *c;

    if(empty() || id >= _length || id < 0) {
        cout << "Index does not exist" << endl;
        throw;
    } 

    prior = head;
    c = head->link;
    next = c->link;

    while(next != tail && id > c->id) {
        prior = c;
        c = next; 
        next = next->link;
    }
    
    prior->link = next;
    delete c;
    _length--;
}


template <class N>
void List<N>::push(N item) {
    element *new_item = new element, *c = head;

    new_item->id = _length;
    new_item->data = item;

    while(c->link != tail) {
        c = c->link;
    }

    c->link = new_item;
    new_item->link = tail;
    _length++;
}


template <class N>
void List<N>::unshift(N item) {
    element *new_item = new element;
    element *c;

    new_item->id = 0;
    new_item->data = item;
    new_item->link = head->link;
    head->link = new_item;
    _length++;

    c = new_item->link;

    while(c != tail) {
        c.id++;
        c = c->link;
    }
}


template <class N>
void List<N>::traverse() {
    element *c;

    if(!empty()) {
        c = head->link;

        while(c != tail) {
            cout << c->id << endl;

            c = c->link;
        }

    } else {
        cout << "The list is empty!" << endl;
    }
}


template <class N>
bool List<N>::traverse(void (*fn)(N)) {
    element *c;

    if(!empty()) {
        c = head->link;

        while(c != tail) {
            fn(c->data);
            c = c->link;
        }
        return true;
    }
    return false;
}


template <class N>
N List<N>::shift(){
    element *c, *item;
    N data = NULL;

    if (empty()) {
        cout << "List is empty, cannot shift" << endl;
        throw;
    }

    item = head->link;
    head->link = c = item->link;

    while(c != tail) {
        c->id--;
        c = c->link;
    }

    data = item->data;
    delete item;
    _length--;

    return data;
}


template <class N>
N List<N>::pop() {
    element *prior, *next;
    N data;
    if(empty()){
        cout << "Cannot pop, list is empty" << endl;
        throw;
    }

    prior = head;
    next = head->link;

    while(next->link != tail) {
        prior = next;
        next = next->link;
    }

    prior->link = tail;
    data = next->data;
    delete next;
    _length--;

    return data;
}


template <class N>
N& List<N>::get(int id) {
    element *prior, *next, *c;

    if(empty() || id >= _length || id < 0) {
        cout << "Index does not exist" << endl;
        throw;
    }

    prior = head;
    c = prior->link;
    next = c->link;

    while(next != tail && id > c->id) {
        prior = c;
        c = next; 
        next = next->link;
    }

    return c->data;
} 


template <class N>
N& List<N>::operator[](int id) {
    element *prior, *next, *c;

    if(empty() || id >= _length || id < 0) {
        cout << "Index does not exist" << endl;
        throw;
    }

    prior = head;
    c = prior->link;
    next = c->link;

    while(next != tail && id > c->id) {
        prior = c;
        c = next; 
        next = next->link;
    }

    return c->data;
} 
