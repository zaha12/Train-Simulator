#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include <stdexcept>
// forward declaration of LinkedList
template <typename T>
class LinkedList;


template <typename T>
class Node{
    public:
        
        T data;
        Node<T>* prev;
        Node<T>* next;

        //constructor initializes a node with the given data
        Node(const T& d){
            data =d;
            prev = nullptr;
            next =nullptr;
        }
        
        //getters 
        Node<T>* getPrev(){
            return prev;
        }
        Node<T>* getNext(){
            return next;
        }
        T& getData(){
            return data;
        }
        
};
//doubly linked list
template <typename T>
class LinkedList{
    private:
    Node<T>* head;
    Node<T>* tail;
    int size_;
    //returns pointer to node at given index
    Node<T>* getNode(int index){
        if(index < 0 ||index >=size_){
            throw std::out_of_range("Bad index");
        }

        Node<T>* cur;
        //start from head if index is in first half
        if(index < size_/2){
            cur = head;
            for(int i = 0; i< index; i++){
                cur = cur->next;
            }
        }
        // otherwise start from tail
        else{
            cur = tail;
            for(int i=size_ -1 ; i> index; i--){
                cur = cur->prev;
            }
        }
        return cur;
    }
     //deletes all node and resets list
    void clear(){
        Node<T>* cur = head;
        while (cur){
            Node<T>* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head =tail = nullptr;
        size_ = 0;
    }
    public:
    //constructor intializes empty list
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            size_ = 0;
        }
        //destructor
        ~LinkedList() {
            clear();
        }
        // insert new value at the head
        void insertAtHead(const T& value){
            Node<T>* n = new Node<T>(value);
            n->next =head;
            if(head) head->prev = n;
            head = n;
            if(!tail){
                tail=n;
            }
            size_++;
        }
        // insert new value at the tail
        void insertAtTail(const T& value) {
            Node<T>* n = new Node<T>(value);
            n->prev = tail;
            if(tail){
                tail->next = n;
            }
            tail=n;
            if(!head){
                head = n;
            }
            size_++;
        }
          //insert new value at the given index
        void insertAtIndex(const T& value, int index){
            if(index < 0 || index > size_){
                throw std::out_of_range("Bad index");
            }
            if(index == 0){
                return insertAtHead(value);
            }
            if(index == size_){
                return insertAtTail(value);
            }
            Node<T>* cur = getNode(index);
            Node<T>* prev = cur->prev;
            Node<T>* n = new Node<T>(value);

            n->prev = prev;
            n->next = cur;
            prev->next = n;
            cur->prev = n;
            size_++;
        }
         //retrieve value from the head
        T& retrieveHead(){
            if(!head){
                throw std::runtime_error("List empty");
            }
            return head->data;
            
        }
        //retrieve value from the tail
        T& retrieveTail(){
            if(!tail){
                throw std::runtime_error("List empty");
            }
            return tail->data;
            
        }
           // retrieve value from the given index
        T& retrieveIndex(int index){
            return getNode(index)->data;
        }
         //remove and return value from the head 
        T removeFromHead(){
            if(!head){
                throw std::runtime_error("List empty");
                
            }
            Node<T>* n = head;
            T val = n->data;
            head = head->next;
            if(head){
                head->prev = nullptr;
            }
            else{
                tail = nullptr;
            }

            delete n;
            size_--;
            return val;
        }
          // remove and return value from the tail
        T removeFromTail(){
            if(!tail){
                throw std::runtime_error("List empty");
            }
            Node<T>* n = tail;
            T val = n->data;
            tail = tail->prev;
            if(tail){
                tail->next = nullptr;

            }
            else{
                head = nullptr;
            }
            delete n;
            size_--;
            return val;
        }
        //remove and return the value from the given index 
        T removeFromIndex(int index){
            if (index < 0 || index >= size_){
                throw std::out_of_range("Bad index");
            }
            if (index == 0){
                return removeFromHead();
                
            }
            if(index == size_ -1){
                return removeFromTail();
            }

            Node<T>* n =getNode(index);
            T val = n->data;

            Node<T>* p = n->prev;
            Node<T>* nx = n->next;

            p->next = nx;
            nx->prev = p;
            delete n;
            size_--;
            return val;
        }
           //search for a given value . return index if found and -1 if not found
        int find(T& value){
            Node<T>* cur = head;
            int i = 0;
            while(cur){
                if (cur->data == value){
                    return i;
                }
                cur = cur->next;
                i++;
            }
            return -1;
        }
          //return number of elements
        int getSize(){
            return size_;
        }

        Node<T>* getHeadNode(){
            return head;
        }
        Node<T>* getTailNode(){
            return tail;
        }


};

typedef LinkedList<int> IntLinkedList;
typedef Node<int> IntNode;

#endif
