#include <iostream>
#include "../Libs/Node/node.cpp"

#pragma region DECLARE STACK
template<typename T> class stack
{
private:
    node<T>* top;
    int count;
public:
    stack(/* args */);
    ~stack();

    void increaseSize(int step);
    int getSize()const;
    node<T>* getTop() const;
    void setTop(node<T>* value);
    void push(T data);
    T  pop();
    bool isEmpty() const ;
    stack<T>* clone();
    void clear();
    void print2console ()const;
};

#pragma endregion

#pragma region MAIN FUNCTION
int main(){
    std::cout << "Let's stack something" << std::endl;
    
    stack<int> stack_a;
    stack_a.push(10);
    stack_a.push(5);
    stack_a.push(12);
    stack_a.print2console();

    stack<int>* stack_b = stack_a.clone();
    stack_b->print2console();

    return 0;
}
#pragma endregion


#pragma region  IMPLEMENTATION OF THE METHODS IN CLASS STACK

template <typename T> stack<T>::stack(/* args */)
{
    this->top = nullptr;
    this->count =0;
}

template <typename T> stack<T>::~stack()
{
    this->clear();
}

template <typename T> void stack<T>::increaseSize(int step){

    this->count += step;

}
template <typename T> node<T>* stack<T>::getTop() const{
    return this->top;

}
template <typename T> void stack<T>::setTop(node<T>* value){
    this->top = value;

}


template<typename T>  void stack<T>::push(T data){
    node<T>* newNode = new node<T>(data);
    newNode->setNext(this->getTop());
    this->setTop(newNode);
    this->increaseSize(1);
}

template<typename T> T stack<T>::pop(){
    node<T>* popNode = this->getTop();
    this->setTop(this->getTop()->getNext());
    delete popNode;
    this->increaseSize( -1 );
    return 1;
}

template<typename T> bool stack<T>::isEmpty() const {
    if(this->getSize()>0) return false;
    return true;
}

template<typename T> int stack<T>::getSize()const{
    return this->count;
}

template<typename T> stack<T>* stack<T>::clone(){
    stack<T>* clonedStack = new stack<T>();
    node<T>* current = this->getTop();

    while (current != nullptr)
    {
        clonedStack->push(current->getData());
        current = current->getNext();
    }
    

    return clonedStack; 
}

template<typename T> void stack<T>::clear(){

    while (this->getTop() != nullptr)
    {
        this->pop();

    }
    
}

template<typename T> void stack<T>::print2console() const{
    node<T>* walk = this->getTop();

    if (walk == nullptr)
    {
        std::cout << "In print2Console function, Walk is Null" << std::endl; 
    }
    
    std::cout << "Count = " << this->getSize() << std::endl;

    while (walk != nullptr)
    {
        std::cout << walk->getData() << " ";
        walk = walk->getNext();
    }
    std::cout << std::endl;
}


#pragma endregion