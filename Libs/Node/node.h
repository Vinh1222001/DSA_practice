#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T> class node
{
private:
    T data;
    node<T>* next;
public:
    node();
    node(T data);
    ~node();

    void setData(T data);
    T getData();
    void setNext(node<T>* next);
    node<T>* getNext();

};

#endif