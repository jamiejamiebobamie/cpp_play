//
//  linkedList.cpp
//  cpp_play
//
//  Created by James McCrory on 5/4/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include<iostream>
#include"helperFunctions.cpp"

template<class T>
class LinkedListNode {
//    friend int operator+(LinkedListNode<T>& nodeToAdd);
public:
    LinkedListNode();
    LinkedListNode(T newdata);
    T getData()const;
    void setData(T newdata);
    LinkedListNode<T>* getNext() const;
    LinkedListNode* operator++();
    void setNext(LinkedListNode<T>* newNext);
    
private:
    T data;
    LinkedListNode<T>* next;
};
template<class T>
LinkedListNode<T>::LinkedListNode():data{0}, next{nullptr} {};
template<class T>
LinkedListNode<T>::LinkedListNode(T newdata) : data{newdata}, next{nullptr} {};
template<class T>
T LinkedListNode<T>::getData()const {return data;};
template<class T>
void LinkedListNode<T>::setData(T newData) {data=newData;};
template<class T>
LinkedListNode<T>* LinkedListNode<T>::getNext()const {return next;};
template<class T>
void LinkedListNode<T>::setNext(LinkedListNode<T>* newNext){ next = newNext;};
template<class T>
LinkedListNode<T>* LinkedListNode<T>::operator++(){
    return next;
};
// // in progress friend function.
//template<int T>
//int operator+(LinkedListNode<T>& nodeToAdd){
//    auto type = decltype(nodeToAdd->getData())
//    auto anInt = decltype(3);
//    auto aChar = decltype('c');
//    auto aCharPointer = decltype("hello");
//    switch (type)
//    {
//        case typeof(0):
//        break;
//    }
//    return 0;
//};

template<class T>
class LinkedList {
public:
    LinkedList();
    LinkedList(T data);
    LinkedList(LinkedListNode<T>* newNode);
    LinkedListNode<T>* getHead()const;
    void setHead(LinkedListNode<T>* newHead);
    void setTail(LinkedListNode<T>* newTail);
    void append(T data);
    void append(LinkedListNode<T>* newNode);
    void prepend(T data);
    void prepend(LinkedListNode<T>* newNode);
    void removeNode(T data);
    void removeNode(LinkedListNode<T>* node);
    void removeNodes(T data);
    LinkedListNode<T>* findOneNode(T data);
    LinkedList<LinkedListNode<T>*>* findAllNodes(T data);
    bool replace(T newItem, T oldItem);
    void sort(bool ascending);
    LinkedListNode<T>* operator[](int index);
    bool insertAtIndex(int index, T data);
    void rotateCounterClockwiseByK(int k);
    LinkedListNode<T>* getMiddle();
    void reverse();
    LinkedList<LinkedListNode<T>*>* operator()(int indicesCount...);
    void printList();
private:
    LinkedListNode<T>* head;
    LinkedListNode<T>* tail;
    // NEED TO IMPLEMENT.
    int len;
};
template<class T>
LinkedList<T>::LinkedList() : head{nullptr}, tail{nullptr} {};
template<class T>
LinkedList<T>::LinkedList(T data) : head{new LinkedListNode<T>(data)}, tail{nullptr} {};
template<class T>
LinkedList<T>::LinkedList(LinkedListNode<T>* node) : head{node}, tail{nullptr} {};
template<class T>
LinkedListNode<T>*  LinkedList<T>::getHead()const{
    return head;
};
template<class T>
void LinkedList<T>::setHead(LinkedListNode<T>* newHead){ head = newHead;};
template<class T>
void LinkedList<T>::setTail(LinkedListNode<T>* newTail){tail = newTail;}
template<class T>
void LinkedList<T>::append(T data){
    LinkedListNode<T>* newNode = new LinkedListNode<T>(data);
    if (!head)
        head = newNode;
    else if (!tail){
        tail = newNode;
        head->setNext(tail);
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }
};
template<class T>
void LinkedList<T>::append(LinkedListNode<T>* newNode){
    if (!head)
        head = newNode;
    else if (!tail){
        tail = newNode;
        head->setNext(tail);
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }
};
template<class T>
void LinkedList<T>::prepend(T data){
    LinkedListNode<T>* newNode = new LinkedListNode<T>(data);
    prepend(newNode);
};
template<class T>
void LinkedList<T>::prepend(LinkedListNode<T>* newNode){
    if (!head)
        head = newNode;
    else if (!tail){
        tail = head;
        head = newNode;
        head->setNext(tail);
    }
    else{
        newNode->setNext(head);
        head = newNode;
    }
};
template<class T>
void LinkedList<T>::removeNode(T data){
    // check to make sure the list is not empty.
    if (head){
        // check to see if the passed-in node is the same as the head.
        if (data == head->getData())
            // if the node is the same as the head
            // set the head to the head's next node.
            head = head->getNext();
        else{
            // if the desired node to be removed is not the head
            // we need to iterate through the whole list
            // (even if the desired node is the tail).
            
            // set an iterator node pointer and a previous node pointer
            // that points to the last iterator node
            LinkedListNode<T>* curr = head;
            LinkedListNode<T>* prev = head;
            while (curr){
                if (curr->getData() == data && curr != tail){
                    prev->setNext(curr->getNext());
                    break;
                } else if (curr->getData() == data && curr == tail) {
                    prev->setNext(nullptr);
                    break;
                }
                prev = curr;
                // "curr = curr->getNext()" works too.
                curr = curr->operator++();
            }
        }
    }
};
template<class T>
void LinkedList<T>::removeNode(LinkedListNode<T>* node){
    // check to make sure the list is not empty.
    if (head){
        // check to see that a nullptr hasn't been passed-in.
        if (node){
            // check to see if the passed-in node is the same as the head.
            if (node == head)
                // if the node is the same as the head
                // set the head to the head's next node.
                head = head->getNext();
            else{
                // if the desired node to be removed is not the head
                // we need to iterate through the whole list
                // (even if the desired node is the tail).
                
                // set an iterator node pointer and a previous node pointer
                // that points to the last iterator node
                LinkedListNode<T>* curr = head;
                LinkedListNode<T>* prev = head;
                while (curr){
                    if (curr == node && curr != tail){
                        prev->setNext(curr->getNext());
                        break;
                    } else if (curr == node && curr == tail) {
                        prev->setNext(nullptr);
                        break;
                    }
                    prev = curr;
                    // "curr = curr->getNext()" works too.
                    curr = curr->operator++();
                }
            }
        }
    }
};
template<class T>
void LinkedList<T>::removeNodes(T data){
    LinkedListNode<T>* node = head;
    while (node){
        if (data == node->getData()){
            removeNode(node);
        }
        node = node->getNext();
    }
};
template<class T>
LinkedListNode<T>* LinkedList<T>::findOneNode(T data){
    if (head){
        if (data == head->getData())
            return head;
    }
    if (tail) {
        if (data == tail->getData())
            return tail;
    }
    LinkedListNode<T>* node = head;
    while (node){
        if (data == node->getData())
            return node;
        else
            node = node->getNext();
    }
    return nullptr;
};
template<class T>
LinkedList<LinkedListNode<T>*>* LinkedList<T>::findAllNodes(T data){
    // i want to create a linked list with data that are references of the nodes.
    LinkedList<LinkedListNode<T>*>* listOfNodesWithDataPointers = new LinkedList<LinkedListNode<T>*>;
    // if i make a new linked list and pass in llnodes with addNode method
        // the nodes being passed in will have their next data members changed.
    LinkedListNode<T>* node = head;
    while (node){
        if (data == node->getData()){
            LinkedListNode<LinkedListNode<T>*>* newNode = new LinkedListNode<LinkedListNode<T>*>;
            newNode->setData(node);
            listOfNodesWithDataPointers->append(newNode);
        }
        node = node->getNext();
    }
    return listOfNodesWithDataPointers;
};
template<class T>
bool LinkedList<T>::replace(T newData, T oldData){
    LinkedList<LinkedListNode<T>*>* listOfNodesWithDataPointers = findAllNodes(oldData);
    LinkedListNode<LinkedListNode<T>*>* curr = listOfNodesWithDataPointers->getHead();
    if (curr){
        while(curr){
            // this a linked list with data = a pointer to a linkedlist node.
            LinkedListNode<T>* node = curr->getData();
            node->setData(newData);
            curr = curr->getNext();
        }
        return true;
    } else
        return false;
}
template<class T>
void LinkedList<T>::sort(bool ascending){
    // check that a nullptr wasn't passed in.
    if (head){
        // initialize a bool to false to control sorting while loop.
        bool sorted = false;
        // initialize LinkedListNode pointers.
        LinkedListNode<T> *prev, *curr, *prevPrev;
        while(!sorted){
            // breaks  the sordid "sorted" loop
            bool editedOrder = false;
            // prev == prevPrev pointing to the same node controls whether or not to update the head.
            prevPrev = head;
            prev = head;
            curr = head->getNext();
            // the condition to check whether or not we want the list in ascendign order or descending order.
            bool condition;
            while (curr){
                // update condition based on "ascending" parameter bool and the new node pointers.
                    // switches prev with curr. sort is stable.
                if (ascending)
                    condition = prev->getData() > curr->getData();
                else
                    condition = prev->getData() < curr->getData();
                if (condition){
                    // set prev.next to curr.next
                    prev->setNext(curr->getNext());
                    // set curr.next to prev
                    curr->setNext(prev);
                    // if prevPrev != prev
                    if (prevPrev != prev)
                        // set prevPrev.next to curr
                        prevPrev->setNext(curr);
                    else
                        // set the curr to the head.
                        head = curr;
                    editedOrder = true;
                }
                prevPrev = prev;
                prev = curr;
                curr = curr->getNext();
            }
            if (!editedOrder)
                sorted = true;
        }
    }
};
template<class T>
LinkedListNode<T>* LinkedList<T>::operator[](int index){
    int count = 0;
    LinkedListNode<T>* node = head;
    while (node){
        if (count == index)
            return node;
        else
            node = node->getNext();
        count++;
    }
    return nullptr;
};
// method does not allow items to be inserted at the end of the list.
// (the last index becomes the second to last index after insertion.)
template<class T>
bool LinkedList<T>::insertAtIndex(int index, T data){
    LinkedListNode<T>* currNodeAtIndex = operator[](index);
    if (!currNodeAtIndex)
        return false;
    
    LinkedListNode<T>* newNode = new LinkedListNode<T>(data);
    
    if (index != 0){
        LinkedListNode<T>* prev = operator[](index-1);
        prev->setNext(newNode);
    } else {
        setHead(newNode);
    }
    newNode->setNext(currNodeAtIndex);
    return true;
};
template<class T>
void LinkedList<T>::rotateCounterClockwiseByK(int k){
    for (int i = 0; i < k; i++){
        tail->setNext(head);
        LinkedListNode<T>* newHead = head->getNext();
        head->setNext(nullptr);
        tail = head;
        head = newHead;
    };
};
template<class T>
LinkedListNode<T>* LinkedList<T>::getMiddle(){
    if (!head)
        return nullptr;
    if (!tail)
        return head;
    LinkedListNode<T>* curr = head;
    int count = 0;
    while (curr){
        count++;
        curr = curr->getNext();
    }
    // division by ints in C++ truncates the decimal: 4/2 = 2, 5/2 = 2
    // would add one when odd to get the correct index,
    // but a starting index of 0 already adds one.
    int index;
    if (count%2){
        index = count/2;
    }
    else
         // when even, the index needs to be shifted down one
         // to account for the a starting index of 0.
        index = count/2 - 1;
    return operator[](index);
};
// 12345 - > 54321
template<class T>
void LinkedList<T>::reverse(){
    LinkedListNode<T>* newHead = tail;
    
    LinkedListNode<T>* curr = head;
    LinkedListNode<T>* prev = head;
    LinkedListNode<T>* next = head->getNext();
    while(next){
        if (curr == prev){
            curr->setNext(nullptr);
            tail = curr;
        }
        else
            curr->setNext(prev);
        prev = curr;
        curr = next;
        next = next->getNext();
    };
    head = newHead;
    head->setNext(prev);
};
/*
    Variadic, overloaded () operator member function.
    First argument is the number of indices passed to the function
    All following arguments are the indices to return from the function.
 */
template<class T>
LinkedList<LinkedListNode<T>*>* LinkedList<T>::operator()(int indicesCount...){
    // the first parameter passed-in is held
        // in 'indicesCount', the number of parameters to follow.
    // initializes the list to hold
        // the arguements of the variadic function.
    va_list args;
    // enables access to the arguments.
    va_start(args, indicesCount);
    // return linkedlist of linkedlistnode addresses
    LinkedList<LinkedListNode<T>*>* listOfNodesByIndex = new
    LinkedList<LinkedListNode<T>*>;
    
    // gets the next item from the list of parameters (in this case the second)
    int nextIndex = va_arg(args, int);
    for (int i = 0; i < indicesCount; i++){
        LinkedListNode<T>* node = head;
        int count = 0;
        while (node){
            if (nextIndex == count){
                LinkedListNode<LinkedListNode<T>*>* newNode = new LinkedListNode<LinkedListNode<T>*>;
                newNode->setData(node);
                listOfNodesByIndex->append(newNode);
            }
            node = node->getNext();
            count++;
        }
        nextIndex = va_arg(args, int);
    }
    // "ends traversal of the variadic function arguments "
    va_end(args);
    return listOfNodesByIndex;
};
template<class T>
void LinkedList<T>::printList(){
    LinkedListNode<T>* node = head;
    while (node){
        std::cout << node->getData() << std::endl;
        node = node->getNext();
    }
    std::cout << " " << std::endl;
};

int main(){
    LinkedListNode<int> test = LinkedListNode<int>(7);
    LinkedList<int> myll = LinkedList<int>(&test);
    myll.append(1);
    myll.append(1);
    myll.append(1);
    myll.append(1);
    myll.append(3);
    myll.append(4);
    myll.append(5);
    myll.append(1);
    
    LinkedListNode<int> firstTwo = LinkedListNode<int>(2);
    myll.append(&firstTwo);
    LinkedListNode<int> secondTwo = LinkedListNode<int>(2);
    myll.append(&secondTwo);
    
    myll.printList();
    myll.removeNodes(1);
    myll.printList();
    
    bool ascending = true;
    myll.sort(ascending);
    myll.printList();
    ascending = false;
    myll.sort(ascending);
    myll.printList();

    std::cout << "finding nodes" << std::endl;

    LinkedList<LinkedListNode<int>*>* allNodesTwo = myll.findAllNodes(2);
    allNodesTwo->printList();
    myll.printList();
    helpers::print(&firstTwo);
    helpers::print(&secondTwo);

    LinkedList<LinkedListNode<int>*>* nodesByIndex = myll(2,0,5);
    nodesByIndex->printList();
    helpers::print(myll[2]);
    
    myll.replace(2,5);
    myll.printList();

    myll.insertAtIndex(5,5);
    myll.printList();
    myll.prepend(30);
    myll.printList();
    
    myll.rotateCounterClockwiseByK(1);
    myll.prepend(30);
    myll.append(30);
    myll.append(30);

    helpers::print("");
    helpers::print(myll.getMiddle()->getData());
    helpers::print("");
    myll.printList();
    
    myll.reverse();
    myll.printList();
    
    ascending = true;
    myll.sort(ascending);
    
    myll.printList();

    return 0;
}
