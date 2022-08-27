#pragma once

#include <iostream>
#include <iomanip>

#include "../../Utility/Swap/swap.h"
#include "../../Stacks/linked_list/stack.h"

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

        // Internal Class Types

        typedef list_link<N> element;

        // Private Constructors

        List(element*, element*, int);
        
        // Data Elements

        element *head, *tail;
        int _length;
        N _save;

        // Private member functions
        
        N& get(int);

    public:
        
        // Constructors

        List();
        int length();

        // Member Functions
        //      empty, traverse, push, unshift, 
        //      delete, pop, shift, at

        bool empty();
        bool traverse();
        bool traverse(bool);
        bool traverse(void(*)(N));
        bool traverse(void(*)(N, int));
        void push(N);
        void unshift(N);
        void delete_item(int);
        N pop();
        N shift();
        N& at(int);

        // Sorting Algorithms
        //      sort, quick_sort, insert_sort
        //      sort automatically chooses which algorithm to use

        void sort();
        void sort(bool (*) (N, N));
        void quick_sort();
        void quick_sort(bool (*) (N, N));
        void insert_sort();
        void insert_sort(bool (*) (N, N));

        // List Generation Algorithms

        List<N> copy();
        List<N> slice();
        List<N> filter(bool (*)(N));
        List<N> filter(bool (*)(N, int));

        template <class M>
        List<M> map(M (*)(N));

        template <class M>
        List<M> map(M (*)(N, int));

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
List<N>::List(element *first, element *last, int new_length) {

    head = new element;
    tail = new element;

    head->next = first;
    first->prior = head;

    tail->prior = last;
    last->next = tail;

    head->prior = NULL;
    tail->next = NULL;

    head->id = -1;
    tail->id = 9999999;

    _length = new_length;
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

    while(next != tail) {
        next->id--;
        next = next->next;
    }
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
        c->id++;
        c = c->next;
    }
}


template <class N>
bool List<N>::traverse() {
    element *c;
    bool members;

    if(empty()) {
        members = false;
    } else {
        members = true;
        c = head->next;

        while(c != tail) {
            cout << c->id << endl;
            c = c->next;
        }
    }

    return members;
}


template <class N>
bool List<N>::traverse(bool verbose) {
    element *c;
    bool members;

    if(empty()) {
        members = false;
        if(verbose) {
            cout << "List is Empty!" << endl;
        }
    } else {
        members = true;
        c = head->next;

        while(c != tail) {
            if(verbose) {
                cout << c->id << endl;
            }
            c = c->next;
        }
    }

    return members;
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
bool List<N>::traverse(void (*fn)(N, int)) {
    element *c;
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
void List<N>::sort() {
    // N save;
    // _save = save; 

    quick_sort();
}


template <class N>
void List<N>::sort(bool (*fn) (N, N)) {
    // _save = NULL;

    quick_sort(fn);
}


template <class N>
void List<N>::quick_sort() {
    int current_start, current_end, position, i;
    Stack<int> next_iteration;

    current_start = 0;
    current_end = _length - 1;
    
    next_iteration.push(current_start);
    next_iteration.push(current_end);

    while(!next_iteration.empty()) {
        current_end = next_iteration.pop();
        current_start = next_iteration.pop();

        position = current_start - 1;

        for(i = current_start; i <= current_end - 1; i++) {
            if(get(i) <= get(current_end)) {
                position++;
                swapElement(get(position), get(i));
            }
        }

        position++;
        swapElement(get(position), get(current_end));

        if(position - 1 > current_start) {
            next_iteration.push(current_start);
            next_iteration.push(position - 1);
        }

        if(position + 1 < current_end) {
            next_iteration.push(position + 1);
            next_iteration.push(current_end);
        }
    }
}


template <class N>
void List<N>::quick_sort(bool (*fn) (N, N)) {
    int current_start, current_end, position, i;
    Stack<int> next_iteration;

    current_start = 0;
    current_end = _length - 1;
    next_iteration.push(current_start);
    next_iteration.push(current_end);

    while(!next_iteration.empty()) {
        current_end = next_iteration.pop();
        current_start = next_iteration.pop();

        position = current_start - 1;

        for(i = current_start; i <= current_end - 1; i++) {
            if(fn(get(i), get(current_end))) {
                position++;
                swapElement(get(position), get(i));
            }
        }

        position++;
        swapElement(get(position), get(current_end));

        if(position - 1 > current_start) {
            next_iteration.push(current_start);
            next_iteration.push(position - 1);
        }

        if(position + 1 < current_end) {
            next_iteration.push(position + 1);
            next_iteration.push(current_end);
        }
    }
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
N& List<N>::at(int id) {
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
N& List<N>::get(int id) {
    element *prior, *next, *c;
    int split; 

    if(empty() || id > _length || id < 0) {
        cout << "Index " << id << " does not exist" << endl;
        throw;
    }

    if(id == _length) {
        return _save;
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
List<M> List<N>::map(M (*fn)(N)) {
    List<M> new_list;
    element *c;

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
List<M> List<N>::map(M (*fn)(N, int)) {
    List<M> new_list;
    element *c;
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
