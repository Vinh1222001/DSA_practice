#include <iostream>
#include <node.cpp>

#pragma region DECLARE CLASS
template<typename T> class queue{
    private:

        node<T>* front;
        node<T>* rear;
        int count;
    public:
        queue();
        ~queue();
        void enqueue(T data);
        T dequeue();
        node<T>* queueFront();
        node<T>* queueRear();
        bool isEmpty() const;
        void clear();
        queue<T>* clone();
        int queueSize();

        void print2Console();
};

#pragma endregion

#pragma region MAIN FUNCTION
int main(){

    queue<int> q1;
    q1.enqueue(5);
    q1.enqueue(8);
    q1.enqueue(15);
    q1.enqueue(10);
    q1.print2Console();

    queue<int> * q2 = new queue<int>();
    q2 = q1.clone();
    q2->print2Console();
    return 0;
}
#pragma endregion

#pragma region IMPLEMENTATION
template<typename T> queue<T>::queue(){
    this->front= nullptr;
    this->rear = nullptr;
    this->count =0;
}
template<typename T> queue<T>::~queue(){
    this->clear();
}
template<typename T> void queue<T>::enqueue(T data){
    node<T>* newNode = new node<T>(data);
    if(this->count <= 0){
        this->rear = newNode;
        this->front = newNode;
    }else{
        this->rear->setNext(newNode);
        this->rear =newNode;
    }

    this->count++;
}
template<typename T> T queue<T>::dequeue(){

    if(this->isEmpty()){
        std::cout << "Can't deleted because the queue is empty!"<< std::endl;
        return -1;
    }


    T tempData = front->getData();
    node<T>* dltNode = front;

    if(this->count == 1){
        this->front = nullptr;
        this->rear = nullptr;
        delete dltNode;
        this->count--;
        return tempData;
    }

    front = this->front->getNext();
    
    dltNode->setNext(nullptr); 

    delete dltNode;

    this->count--;

    return tempData;
}
template<typename T> node<T>* queue<T>::queueFront(){
    return this->front;
}
template<typename T> node<T>* queue<T>::queueRear(){
    return this->rear;
}
template<typename T> bool queue<T>::isEmpty() const{
    return this->count <= 0;
}
template<typename T> void queue<T>::clear(){
    while( this->front != nullptr){
        dequeue();
    }
}
template<typename T> queue<T>* queue<T>::clone(){
    queue<T>* result  = new queue<T>();
    node<T>* walk = this->front;

    while(walk != nullptr){
        result->enqueue(walk->getData());
        walk = walk->getNext();
    }
    return result;
}

template<typename T> int queue<T>::queueSize(){
    return this->count;
}

template<typename T> void queue<T>::print2Console(){
    std::cout << "Count = " <<this->count << std::endl;
    node<T>* temp = front;

    while (temp != nullptr)
    {
        std::cout << temp->getData() << " "; 
        temp = temp -> getNext();
    }

    std::cout << std::endl;
    
}

#pragma endregion
