#pragma once

#include <iostream>
#include <iomanip>

using namespace std; 

template <class N>
struct set_link {
    int id;
    set_link *next;
    set_link *prior;
    N data;
};

template <class N>
class Set {
    private:
        typedef set_link<N> member;
        member *head, *tail;
        int _length;
    public:
        // constructors

        Set();
        int length();

        // empty, traverse, push, unshift, delete, pop, shift, get

        bool empty();
        void traverse();
        bool traverse(void(*)(N));
        bool traverse(void(*)(N, int));
        void push(N);
        void unshift(N);
        void delete_item(int);
        N pop();
        N shift();
        N& get(int);

        template <class M>
        Set<M> map(M (*)(N));

        template <class M>
        Set<M> map(M (*)(N, int));

        // overloaded operators

        N& operator [] (int i);
};



template <class N>
Set<N>::Set() {

    head = new member;
    tail = new member;

    head->next = tail;
    tail->prior = head;

    head->prior = NULL;
    tail->next = NULL;

    head->id = -1;
    tail->id = 9999999;

    _length = 0;
}


template <class N>
int Set<N>::length() {
    return _length; 
}

template <class N>
bool Set<N>::empty() {
    return head->next == tail;
}


template <class N>
void Set<N>::delete_item(int id) {
    member *prior, *next, *c;
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
void Set<N>::push(N item) {
    member *new_item = new member, *c = tail->prior;

    new_item->id = _length;
    new_item->data = item;


    c->next = new_item;
    new_item->next = tail;

    new_item->prior = c;
    tail->prior = new_item;

    _length++;
}


template <class N>
void Set<N>::unshift(N item) {
    member *new_item = new member;
    member *c;

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
void Set<N>::traverse() {
    member *c;

    if(!empty()) {
        c = head->next;

        while(c != tail) {
            cout << c->id << endl;

            c = c->next;
        }

    } else {
        cout << "The Set is empty!" << endl;
    }
}


template <class N>
bool Set<N>::traverse(void (*fn)(N)) {
    member *c;

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
bool Set<N>::traverse(void (*fn)(N, int)) {
    member *c;
    int index = 0;

    if(!empty()) {
        c = head->next;

        while(c != tail) {
            fn(c->data, index);
            index++;
            c = c->next;
        }

        return true;
    }

    return false;
}


template <class N>
N Set<N>::shift(){
    member *c, *item;
    N data;

    if (empty()) {
        cout << "Set is empty, cannot shift" << endl;
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
N Set<N>::pop() {
    member *c;
    N data;
    if(empty()){
        cout << "Cannot pop, Set is empty" << endl;
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
N& Set<N>::get(int id) {
    member *prior, *next, *c;
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
template <class M>
Set<M> Set<N>::map(M (*fn)(N)) {
    Set<M> new_list;
    member *c;

    if(!empty()) {

        c = head->next;

        while(c != tail) {
            new_list.push(fn(c->data));
            c = c->next;
        }
    }
    
    return new_list;
}


template <class N>
template <class M>
Set<M> Set<N>::map(M (*fn)(N, int)) {
    Set<M> new_list;
    member *c;
    int index = 0;

    if(!empty()) {

        c = head->next;

        while(c != tail) {
            new_list.push(fn(c->data, index));
            index++;
            c = c->next;
        }
    }
    
    return new_list;
}


template <class N>
N& Set<N>::operator[](int id) {
    member *prior, *next, *c;
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