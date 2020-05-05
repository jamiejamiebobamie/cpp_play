//
//  linkedList.cpp
//  cpp_play
//
//  Created by James McCrory on 5/4/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

//class LinkedListNode {};

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
    LinkedList* removeNodes(LinkedList* nodes);
    LinkedListNode* findOneNode(int data);
    LinkedList* findAllNodes(int data);
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
                LinkedListNode* it = head;
                LinkedListNode* prev = head;
                while (it){
                    if (it == node && it != tail){
                        prev->setNext(it->getNext());
                        break;
                    } else if (it == node && it == tail) {
                        prev->setNext(nullptr);
                        break;
                    }
                    prev = it;
                    it = it->getNext();
                }
            }
        }
    }
};
// pass in a linkedlist*
// iterate through this* linkedlist and compare each node with the passed-in list.
// remove nodes from this* linkedlist and passed-in linkedlist* if comparison = true.
// return empty passed-in linkedlist* or list with remaining, unfound nodes.

// making the assumption that passed-in linkedlist has been generated
// by the findAllNodes method and is thus in the same order as this*.
// PROBLEM: the findAllNodes method generates a new Linkedlist, but uses the same nodes
// from the old one so you ruin the list that you are operating on, because the nodes' next variables
// are being changed. need to use and return a different data structure (like an array / vector).
LinkedList* LinkedList::removeNodes(LinkedList* nodes){
    if (nodes){
        LinkedListNode* it_passedIn = nodes->getHead();
        LinkedListNode* it = head;
            while (it_passedIn and it){
                if (it == it_passedIn){
                    removeNode(it);
                    nodes->removeNode(it);
                }
                it++;
                it_passedIn++;
            }
    }
    return nodes;
};
LinkedListNode* LinkedList::findOneNode(int data){
    if (head){
        if (data == head->getData())
            return head;
    } else if (tail) {
        if (data == tail->getData())
            return tail;
    } else{
        LinkedListNode* node = head;
        while (node){
            if (data == node->getData())
                return node;
            else
                node = node->getNext();
        }
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
void LinkedList::printList(){
    LinkedListNode* node = head;
    int i = 0;
    while (node){
        std::cout << node->getData() << std::endl;
        node = node->getNext();
//        if (i > 100){
//            std::cout << node << std::endl;
//            break;
//        }

    }
        std::cout << " " << std::endl;
};


int main(){
    LinkedList myll = LinkedList(1);
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
    LinkedListNode* heyo = one.operator++(); // this syntax: "one++" does not work...
    helpers::print(heyo->getData());

//    myll.removeNode(&one);
//    myll.printList();
    //    BROKEN!
//    LinkedListNode* found = myll.findOneNode(3);
//    helpers::print(found);
   
    
    
/*
 
need more testing:
        LinkedList* LinkedList::removeNodes(LinkedList* nodes);
        LinkedListNode* LinkedList::findOneNode(int data);
        LinkedList* LinkedList::findAllNodes(int data);
 */
    
    return 0;
}
