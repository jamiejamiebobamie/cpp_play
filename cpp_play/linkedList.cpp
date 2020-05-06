//
//  linkedList.cpp
//  cpp_play
//
//  Created by James McCrory on 5/4/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include<iostream>
#include"helperFunctions.cpp"

class LinkedListNode {
public:
    LinkedListNode();
    LinkedListNode(int newdata);
    void setData(int newdata);
    int getData()const;
    LinkedListNode* getNode();
    LinkedListNode* getNext();
    // syntax "one++" does not work.
    // must use "objectVarName.operator++()"
    LinkedListNode* operator++();
    void setNext(LinkedListNode* newNext);
    
private:
    int data;
    LinkedListNode* next;
};
LinkedListNode::LinkedListNode():data{0}, next{nullptr} {};
LinkedListNode::LinkedListNode(int newdata) : data{newdata}, next{nullptr} {};
void LinkedListNode::setData(int newData) {data=newData;};
int LinkedListNode::getData()const {return data;};
LinkedListNode* LinkedListNode::getNode() {return this;};
LinkedListNode* LinkedListNode::getNext(){return next;}
void LinkedListNode::setNext(LinkedListNode* newNext){ next = newNext;};
LinkedListNode* LinkedListNode::operator++(){
    return next;
};

class LinkedList {
public:
    LinkedList();
    LinkedList(int data);
    LinkedListNode* getHead();
    void addNode(int data);
    void addNode(LinkedListNode* newNode);
    void removeNode(LinkedListNode* node);
    void removeNodes(int data);
    LinkedListNode* findOneNode(int data);
    LinkedList* findAllNodes(int data);
    void sort(bool ascending);
    void printList();
private:
    LinkedListNode* head;
    LinkedListNode* tail;
    int len;
};
LinkedList::LinkedList() : head{nullptr}, tail{nullptr} {};
LinkedList::LinkedList(int data) : head{new LinkedListNode(data)}, tail{nullptr} {};
LinkedListNode* LinkedList::getHead(){
    return head;
};
void LinkedList::addNode(int data){
    LinkedListNode* newNode = new LinkedListNode(data);
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
void LinkedList::addNode(LinkedListNode* newNode){
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
void LinkedList::removeNode(LinkedListNode* node){
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
                LinkedListNode* curr = head;
                LinkedListNode* prev = head;
                while (curr){
                    if (curr == node && curr != tail){
                        prev->setNext(curr->getNext());
                        break;
                    } else if (curr == node && curr == tail) {
                        prev->setNext(nullptr);
                        break;
                    }
                    prev = curr;
                    curr = curr->operator++(); // curr = curr->getNext(); // works too.
                }
            }
        }
    }
};
void LinkedList::removeNodes(int data){
    LinkedListNode* node = head;
    while (node){
        if (data == node->getData()){
            removeNode(node);
        }
        node = node->getNext();
    }
};
LinkedListNode* LinkedList::findOneNode(int data){
    if (head){
        if (data == head->getData())
            return head;
    }
    if (tail) {
        if (data == tail->getData())
            return tail;
    }
    LinkedListNode* node = head;
    while (node){
        if (data == node->getData())
            return node;
        else
            node = node->getNext();
    }
    return nullptr;
};
LinkedList* LinkedList::findAllNodes(int data){
    LinkedList* listOfNodesWithData = new LinkedList;
    LinkedListNode* node = head;
    while (node){
        if (data == node->getData())
            listOfNodesWithData->addNode(node);
        else
            node = node->getNext();
    }
    return listOfNodesWithData;
};
void LinkedList::sort(bool ascending){
    // check that a nullptr wasn't passed in.
    if (head){
        // initialize a bool to false to control sorting while loop.
        bool sorted = false;
        // initialize LinkedListNode pointers.
        LinkedListNode *prev, *curr, *prevPrev;
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
                    // switch prev with curr. sort is in place.
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
void LinkedList::printList(){
    LinkedListNode* node = head;
    while (node){
        std::cout << node->getData() << std::endl;
        node = node->getNext();
    }
    std::cout << " " << std::endl;
};


int main(){
    LinkedList myll = LinkedList(3);
    myll.addNode(1);
    myll.addNode(1);
    myll.addNode(1);
    myll.addNode(2);
    myll.addNode(3);
    myll.addNode(4);
    myll.addNode(5);
    LinkedListNode one = LinkedListNode(1);
    myll.addNode(&one);
    LinkedListNode two = LinkedListNode(2);
    myll.addNode(&two);
    myll.printList();

    myll.removeNode(&one);
    myll.printList();
    myll.removeNodes(1);
    myll.printList();
    
    bool ascending = true;
    myll.sort(ascending);
    myll.printList();
    ascending = false;
    myll.sort(ascending);
    myll.printList();
    
    return 0;
    
/*
 
need more testing:
        LinkedList* LinkedList::findAllNodes(int data); // new to C++...
                                                        // need to find appropriate storage
                                                        // and return type for a variable-sized
                                                        // list of addresses.
 */
}
