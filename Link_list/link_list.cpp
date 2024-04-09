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
        List_ItemType DeleteItem(int Position);
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
    list_a.InsertLast(12);
    list_a.InsertItem(111,0);
    list_a.InsertItem(3,1);
    list_a.InsertItem(2,10);
    list_a.InsertItem(5,2);

    list_a.Print2Console();

    list_a.DeleteFirst();

    list_a.Print2Console();

    list_a.DeleteLast();

    list_a.Print2Console();

    int a=0;
    list_a.GetItem(2,a);
    std::cout << "Item at position 2 = " << a << std::endl;
    list_a.GetItem(0,a);
    std::cout << "Item at first position = " << a << std::endl;
    list_a.GetItem(100,a);
    std::cout << "Item at last position = " << a << std::endl;
    list_a.GetItem(1,a);
    std::cout << "Item at position 1 = " << a << std::endl;

    list_a.DeleteItem(2);

    list_a.Print2Console();

    LinkedList<int>* list_b;

    list_b = list_a.Clone();
    list_b->Print2Console();

    list_a.Clear();
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
    this->Clear();
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
        return;
    }
    this->count++;
    Node<List_ItemType>* newNode = new Node<List_ItemType>(value);
    Node<List_ItemType>* preNode = this->head;

    while (preNode->next != NULL)
    {
        preNode = preNode->next;
    }

    newNode->next = preNode->next;
    preNode->next = newNode;
}

template <typename List_ItemType> int LinkedList<List_ItemType>::InsertItem(List_ItemType value, int position){
    if(this->count <= 0){
        this->InsertFirst(value);
        return 1;
    }
    
    if (position <= 0)
    {
        this->InsertFirst(value);
        return 1;
    }

    if(position>= this->count-1){
        this->InsertLast(value);
        return 1;
    }

    this->count++;
    Node<List_ItemType>* newNode = new Node<List_ItemType>(value);
    Node<List_ItemType>* preNode = this->head;

    if(position == 1){
        newNode->next = preNode->next;
        preNode->next = newNode;
        return 1;
    }

    while (--position > 0) {
        preNode = preNode->next;
        std::cout << "In do While loop, position = "<< position << std::endl;
        std::cout << "In do While loop, count = "<< this->count << std::endl;
        std::cout << "In do While loop, current preNode's data = "<< preNode->data << std::endl;
    } 
    
    if(preNode==NULL) {
        this->count--;
        return 0;
    }
    newNode->next = preNode->next;
    preNode->next = newNode;
    return 1;
    
}

template <typename List_ItemType> List_ItemType LinkedList<List_ItemType>::DeleteFirst(){
    Node<List_ItemType>* pLoc = this->head;
    List_ItemType deletedValue= pLoc->data;
    this->head = pLoc->next;
    delete pLoc;
    this->count--;
    return deletedValue; 
}

template <typename List_ItemType> List_ItemType LinkedList<List_ItemType>::DeleteLast(){
    if(this->count == 1) return this->DeleteFirst();

    return this->DeleteItem(this->count-1);
    
}

template <typename List_ItemType> List_ItemType LinkedList<List_ItemType>::DeleteItem(int Position){
    if(this->count == 1) return DeleteFirst();
    if(Position <= 0) return DeleteFirst();
    if(Position > this->count -1 ) Position = this->count-1;

    Node<List_ItemType>* preNode = head;
    Node<List_ItemType>* locNode = preNode->next;

    --Position;

    while (Position)
    {
        Position--;
        preNode = locNode;
        locNode = locNode->next;
    }

    List_ItemType deletedValue = locNode->data;
    preNode->next = locNode->next;
    locNode->next =NULL;

    delete locNode;
    this->count--;
    return deletedValue;

}

template <typename List_ItemType> int LinkedList<List_ItemType>::GetItem(int Position, List_ItemType &dataOut){
    if(this->count == 1) {
        dataOut = this->head->data;
        return 1;
    }

    if(Position <= 0){
        dataOut = this->head->data;
        return 1;
    }
    if(Position > this->count -1 ) Position = this->count-1;
    Node<List_ItemType>* locNode=head;

    while (Position--)
    {
        locNode=locNode->next;
    }
    
    dataOut = locNode->data;
    return (locNode != NULL);

}

template <typename List_ItemType> void LinkedList<List_ItemType>::Print2Console(){

    std::cout << "Count = " << this->count << std::endl; 

    Node<List_ItemType>* tempNode = this->head;
    while(tempNode != NULL){
        std::cout << tempNode->data << " ";
        tempNode= tempNode->next;
    }
    std::cout << std::endl;
}

template <typename List_ItemType> void LinkedList<List_ItemType>::Clear(){
    Node<List_ItemType>* deleteNode;
    while (this->head !=NULL)
    {
        deleteNode = this->head;
        this->head = this->head->next;
        delete deleteNode;
    }
    this->count =0;
}

template <typename List_ItemType> LinkedList<List_ItemType>* LinkedList<List_ItemType>::Clone(){
    LinkedList<List_ItemType>* result = new LinkedList<List_ItemType>();
    Node<List_ItemType>* p = this->head;
    while(p!=NULL){
        result->InsertLast(p->data);
        p = p->next;
    }

    result->count = this->count;
    return result;
}


#pragma endregion 