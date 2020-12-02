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

        // length, empty, traverse, insert, delete, get, exists

        int length();
        bool empty();
        void traverse();
        bool traverse(void(*)(N));
        void insert(N, int);
        void delete_item(int);
        N& get(int);
        bool exists(int);

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
    tail->id = 99999999;

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
            _length--;
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
    element *new_item = new element;
    element *prior, *next;
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
        _length++;
    } else {
        cout << "Index is not unique" << endl;
        throw;
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
N& List<N>::get(int id) {
    element *prior, *next, *c;

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
N& List<N>::operator[] (int id) {
    element *prior, *next, *c;

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
    element *prior, *next, *c;

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
