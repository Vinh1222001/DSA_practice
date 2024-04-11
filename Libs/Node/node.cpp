#include "node.h"

template <typename T> node<T>::node(){
    this->data = 0;
    this->next = nullptr;
}

template <typename T> node<T>::node(T data){
    this->data = data;
    this->next = nullptr;
}

template <typename T> node<T>::~node(){

}
template <typename T> void node<T>::setData(T data){
    this->data = data;
}
template <typename T> T node<T>::getData(){
    return this->data;
}
template <typename T> void node<T>::setNext(node<T>* next){
    this->next = next;
}
template <typename T> node<T>* node<T>::getNext(){
    return this->next;
}