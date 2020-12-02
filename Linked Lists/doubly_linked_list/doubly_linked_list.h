#pragma once

#include <iostream>
#include <iomanip>

using namespace std; 

template <class N>
struct list_link {
    int id;
    list_link *next;
    list_link *prior;
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
        int length();

        // empty, traverse, push, unshift, delete, pop, shift, get

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

    head->next = tail;
    tail->prior = head;

    head->prior = NULL;
    tail->next = NULL;

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
    return head->next == tail;
}


template <class N>
void List<N>::delete_item(int id) {
    element *prior, *next, *c;
    int split;

    if(empty() || id >= _length || id < 0) {
        cout << "Index does not exist" << endl;
        throw;
    } 

    split = _length/2 - 1;

    if(id <= split) {
        prior = head;
        c = prior->next;
        next = c->next;

        while(next != tail && id > c->id) {
            prior = c;
            c = next; 
            next = next->next;
        }
    } else {
        next = tail;
        c = next->prior;
        prior = c->prior;

        while(prior != head && id < c->id) {
            next = c;
            c = prior;
            prior = prior->prior;
        }
    }

    next->prior = prior;
    prior->next = next;
    delete c;
    _length--;
}


template <class N>
void List<N>::push(N item) {
    element *new_item = new element, *c = tail->prior;

    new_item->id = _length;
    new_item->data = item;


    c->next = new_item;
    new_item->next = tail;

    new_item->prior = c;
    tail->prior = new_item;

    _length++;
}


template <class N>
void List<N>::unshift(N item) {
    element *new_item = new element;
    element *c;

    new_item->id = 0;
    new_item->data = item;
    
    new_item->prior = head;
    head->next->prior = new_item;
    
    new_item->next = head->next;
    head->next = new_item;
    _length++;

    c = new_item->next;

    while(c != tail) {
        c.id++;
        c = c->next;
    }
}


template <class N>
void List<N>::traverse() {
    element *c;

    if(!empty()) {
        c = head->next;

        while(c != tail) {
            cout << c->id << endl;

            c = c->next;
        }

    } else {
        cout << "The list is empty!" << endl;
    }
}


template <class N>
bool List<N>::traverse(void (*fn)(N)) {
    element *c;

    if(!empty()) {
        c = head->next;

        while(c != tail) {
            fn(c->data);
            c = c->next;
        }
        return true;
    }
    return false;
}


template <class N>
N List<N>::shift(){
    element *c, *item;
    N data;

    if (empty()) {
        cout << "List is empty, cannot shift" << endl;
        throw;
    }

    item = head->next;
    head->next = c = item->next;
    c->prior = head;

    while(c != tail) {
        c->id--;
        c = c->next;
    }

    data = item->data;
    delete item;
    _length--;

    return data;
}


template <class N>
N List<N>::pop() {
    element *c;
    N data;
    if(empty()){
        cout << "Cannot pop, list is empty" << endl;
        throw;
    }

    c = tail->prior;
    c->prior->next = tail;
    tail->prior = c->prior;
    
    data = c->data;
    delete c;
    _length--;
    
    return data;
}


template <class N>
N& List<N>::get(int id) {
    element *prior, *next, *c;
    int split; 

    if(empty() || id >= _length || id < 0) {
        cout << "Index does not exist" << endl;
        throw;
    }

    split = _length/2 - 1;

    if(id <= split) {
        prior = head;
        c = prior->next;
        next = c->next;

        while(next != tail && id > c->id) {
            prior = c;
            c = next; 
            next = next->next;
        }
    } else {
        next = tail;
        c = next->prior;
        prior = c->prior;

        while(prior != head && id < c->id) {
            next = c;
            c = prior;
            prior = prior->prior;
        }
    }

    return c->data;
} 


template <class N>
N& List<N>::operator[](int id) {
    element *prior, *next, *c;
    int split; 

    if(empty() || id >= _length || id < 0) {
        cout << "Index does not exist" << endl;
        throw;
    }

    split = _length/2 - 1;

    if(id <= split) {
        prior = head;
        c = prior->next;
        next = c->next;

        while(next != tail && id > c->id) {
            prior = c;
            c = next; 
            next = next->next;
        }
    } else {
        next = tail;
        c = next->prior;
        prior = c->prior;

        while(prior != head && id < c->id) {
            next = c;
            c = prior;
            prior = prior->prior;
        }
    }

    return c->data;
}