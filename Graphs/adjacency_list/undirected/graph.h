#pragma once

#include <iostream>
#include <iomanip>

#include "../../../LinkedLists/doubly_linked_list/doubly_linked_list.h"

using namespace std; 


template <class N>
class Vertex {
    private:

        // Data Elements
        
        List<Vertex<N>*> adjacent;
        // List<Vertex<N>> adjacent_to;
        int _degree;
        int _id;


    public:

        // Constructors

        Vertex(int);

        // Member Functions
        //      id, degree, add_edge

        int degree();
        int id();
        void add_edge(int);

        // Overloaded operators

        Vertex<N>& operator [] (int i);

        // friend functions
        //      compare_verticies
        
        template <class M>
        friend bool compare_verticies(Vertex<M>*, Vertex<M>*);
};


template <class N>
class Graph {
    private:

        // Data Elements
        
        int _size;
        List<Vertex<N>*> nodes;
    public:
    
        // Constructors

        Graph();
        Graph(List<N>);
        
        // Member functions
        //      size, add_node, add_edge

        int size();

        void add_node(N);
        void add_edge(int, int);

        // Overloaded operators

        Vertex<N>& operator [] (int i);
        
};




template <class N>
Vertex<N>::Vertex(int id) {
    _degree = 0;
    _id = id;
}


template <class N>
int Vertex<N>::id() {
    return _id;
}


template <class N>
void Vertex<N>::add_edge(int) {
}

template <class M>
bool compare_verticies(Vertex<M> *first, Vertex<M> *second) {
    return first->_id > second->id;
}

template <class N>
Graph<N>::Graph() {
    _size = 0;
}


template <class N>
int Graph<N>::size() {
    return _size;
}


template <class N>
void Graph<N>::add_node(N) {
}


template <class N>
void Graph<N>::add_edge(int first, int second) {
    nodes[first]->add_edge(second);
    nodes[second]->add_edge(first);
}

