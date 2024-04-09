/**
 * @brief Link list
*/
#include <iostream>

#pragma region Create Node in struct

// template <typename ItemType> struct Node
// {
//     ItemType data;
//     Node<ItemType>* next;
// };

#pragma endregion

#pragma region Create Node in class 

template <typename ItemType> class Node{

    public:
        Node(){
            this->next = NULL;
        }

        Node(ItemType data){
            this->data = data;
            this->next =NULL;
        }

        ItemType data;
        Node<ItemType> *next;

};

#pragma endregion

#pragma region CREATE LINKED LIST

template <typename List_ItemType> class LinkedList{
    public:
        LinkedList();
        LinkedList(Node<List_ItemType>* firstNode);
        ~LinkedList();
        void InsertFirst(List_ItemType value);
        void InsertLast(List_ItemType value);
        int InsertItem(List_ItemType value, int position);
        List_ItemType DeleteFirst();
        List_ItemType DeleteLast();
        int DeleteItem(int Position);
        int GetItem(int Position, List_ItemType &dataOut);
        void Print2Console();
        void Clear();
        LinkedList<List_ItemType> *Clone();
    protected:
    Node<List_ItemType>* head;
    int count;
};

#pragma endregion

int main(void){

    // Node<int> node2(78);

    LinkedList<int> list_a;

    list_a.InsertFirst(10);
    list_a.InsertFirst(111);
    list_a.InsertLast(12);
    list_a.InsertLast(3);

    list_a.Print2Console();

    return 0;
}

#pragma region IMPLEMENTING FUNCTIONS

template <typename List_ItemType> LinkedList<List_ItemType>::LinkedList(){
    this->head =NULL;
    this->count =0;
}

template <typename List_ItemType> LinkedList<List_ItemType>::LinkedList(Node<List_ItemType>* firstNode){

    this->head =firstNode;
    this->count =1;
}

template <typename List_ItemType> LinkedList<List_ItemType>::~LinkedList(){

}

template <typename List_ItemType> void LinkedList<List_ItemType>::InsertFirst(List_ItemType value){
    Node<List_ItemType>* newNode = new Node<List_ItemType>(value);
    newNode->next = this->head;
    this->head= newNode;
    this->count++;

}

template <typename List_ItemType> void LinkedList<List_ItemType>::InsertLast(List_ItemType value){
    if(this->count <= 0){
        this->InsertFirst(value);
    }

    Node<List_ItemType>* newNode = new Node<List_ItemType>(value);
    Node<List_ItemType>* preNode = this->head;

    while (preNode->next != NULL)
    {
        preNode = preNode->next;
    }

    newNode->next = preNode->next;
    preNode->next = newNode;
    this->count++;
}

template <typename List_ItemType> int LinkedList<List_ItemType>::InsertItem(List_ItemType value, int position){

}

template <typename List_ItemType> List_ItemType LinkedList<List_ItemType>::DeleteFirst(){

}

template <typename List_ItemType> List_ItemType LinkedList<List_ItemType>::DeleteLast(){

}

template <typename List_ItemType> int LinkedList<List_ItemType>::DeleteItem(int Position){

}

template <typename List_ItemType> int LinkedList<List_ItemType>::GetItem(int Position, List_ItemType &dataOut){

}

template <typename List_ItemType> void LinkedList<List_ItemType>::Print2Console(){

    std::cout << "Count = " << this->count << std::endl; 

    Node<List_ItemType>* tempNode = this->head;
    while(tempNode != NULL){
        std::cout << tempNode->data << " ";
        tempNode= tempNode->next;
    }
}

template <typename List_ItemType> void LinkedList<List_ItemType>::Clear(){

}

template <typename List_ItemType> LinkedList<List_ItemType>* LinkedList<List_ItemType>::Clone(){

}


#pragma endregion 