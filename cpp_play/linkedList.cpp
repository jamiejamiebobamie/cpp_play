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
    void sortAscending();
    void sortDescending();
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
                    it = it->operator++();
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
void LinkedList::sortAscending(){
    if (head){
        bool sorted = false;
        LinkedListNode *node, *prev, *prevPrev;
        while(!sorted){
            bool editedOrder = false;
            node = head;
            prev = head;
            prevPrev = head;
            while (node){
                // bubble sort?
                if (prev->getData() > node->getData()){
                    // prev.next = node.next
                    prev->setNext(node->getNext());
                    // node.next = prev
                    node->setNext(prev);
                    // prevPrev.next = node
                    prevPrev->setNext(node);
                    editedOrder = true;
                }
                prevPrev = prev;
                prev = node;
                node = node->getNext();
            }
            if (!editedOrder)
                sorted = true;
        }
    }
};
// IN PROGRESS...
void LinkedList::sortDescending(){
    if (head){
        bool sorted = false;
        LinkedListNode *node, *prev, *prevPrev;
        while(!sorted){
            bool editedOrder = false;
            node = head;
            prev = head;
            prevPrev = head;
            while (node){
                // bubble sort?
                if (prev->getData() < node->getData()){
                    // 45322
                    // prev.next = node.next // 4 points to 3
                    // node.next = prev // 5 points to 4
//                    if (prevPrev != prev)
                        // prevPrev.next = node // 4 points to ..
                    editedOrder = true;
                }
                prevPrev = prev;
                prev = node;
                node = node->getNext();
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
    LinkedList myll = LinkedList(1);
    myll.addNode(2);
    myll.addNode(3);
    myll.addNode(4);
    myll.addNode(5);
    myll.addNode(1);
    myll.addNode(1);
    myll.addNode(1);
    LinkedListNode one = LinkedListNode(1);
    myll.addNode(&one);
    LinkedListNode two = LinkedListNode(2);
    myll.addNode(&two);
    myll.printList();
    myll.removeNode(&one);
    myll.printList();
    LinkedListNode* found1 = myll.findOneNode(3);
    helpers::print(found1->getData());
    LinkedListNode* found2 = myll.findOneNode(45);
    helpers::print(found2);
    myll.removeNodes(1);
    myll.printList();
    myll.sortAscending();
    myll.printList();

//  IN PROGRESS...
//    myll.sortDescending();
//    myll.printList();
    
    return 0;
    
/*
 
need more testing:
        LinkedList* LinkedList::findAllNodes(int data); // new to C++...
                                                        // need to find appropriate storage
                                                        // and return type for a variable-sized
                                                        // list of addresses.
 */
}
