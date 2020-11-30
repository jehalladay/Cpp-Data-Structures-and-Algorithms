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
        typedef list_link<N> slice;
        slice *head, *tail;
        bool empty();
    public:
        // constructors
        List();
        int length;
        // traverse, insert, delete, get, exists
        void traverse();
        bool traverse(void(*)(N));
        void insert(N, int);
        void delete_item(int);
        N get(int);
        bool exists(int);

        N& operator [] (int i);
};



template <class N>
List<N>::List() {

    head = new slice;
    tail = new slice;

    head->link = tail;
    tail->link = NULL;

    head->id = -1;
    tail->id = 99999999;

    length = 0;
}


template <class N>
bool List<N>::empty() {
    return head->link == tail;
}


template <class N>
void List<N>::delete_item(int id) {
    slice *prior, *next, *c;

    if(!empty()) {
        prior = head;
        c = head->link;
        next = c->link;

        while(next != tail && id > c->id) {
            prior = c;
            c = next; 
            next = next->link;
        }
        
        if(id == c->id) {
            prior->link = next;
            delete c;
            length--;
        } else {
            cout << "Index does not exist" << endl;
            throw;
        }
    } else {
        cout << "Index does not exist" << endl;
        throw;
    }
}


template <class N>
void List<N>::insert(N item, int id) {
    slice *new_item = new slice;
    slice *prior, *next;
    bool unique_id = true;

    new_item->id = id;
    new_item->data = item;

    prior = head;
    next = head->link;

    while(next != tail && id > next->id) {
        if(next->id == id) unique_id = false;
        prior = next;
        next = next->link;
    }

    if(unique_id) {
        prior->link = new_item;
        new_item->link = next;
        length++;
    } else {
        cout << "Index is not unique" << endl;
        throw;
    }
}


template <class N>
void List<N>::traverse() {
    slice *c;

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
    slice *c;

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
N List<N>::get(int id) {
    slice *prior, *next, *c;

    if(!empty()) {
        prior = head;
        c = head->link;
        next = c->link;

        while(next != tail && id > c->id) {
            prior = c;
            c = next; 
            next = next->link;
        }

        if(id == c->id) {
            return c->data;
        } else {
            cout << "Index does not exist" << endl;
            throw;
        }
    } 
}

template <class N>
bool List<N>::exists(int id) {
    bool here = false;
    slice *prior, *next, *c;

    if(!empty()) {
        prior = head;
        c = head->link;
        next = c->link;

        while(next != tail && id > c->id) {
            prior = c;
            c = next; 
            next = next->link;
        }

        if(id == c->id) {
            here = true;
        }
    } 



    return here;
}
