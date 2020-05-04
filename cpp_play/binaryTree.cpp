//
//  binaryTree.cpp
//  cpp_play
//
//  Created by James McCrory on 5/2/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include<iostream>
#include"helperFunctions.cpp"

class BinaryNode {
//    friend bool operator==(const BinaryNode&, const BinaryNode&);
    public:
        BinaryNode();
        BinaryNode(int);
        BinaryNode* operator=(const BinaryNode&);
        BinaryNode* getLeft();
        BinaryNode* getRight();
        int getData();
        void setLeft(BinaryNode*);
        void setRight(BinaryNode*);
        void setData(int);
    private:
        BinaryNode* left;
        BinaryNode* right;
        int data;
};
BinaryNode::BinaryNode(): data{0}, left{nullptr}, right{nullptr} {};
BinaryNode::BinaryNode(int data) : data{data}, left{nullptr}, right{nullptr} {};
// in case i want to do a multiple assignment. do i need to worry about memberwise assignment with the pointer member variables in this instance?
BinaryNode* BinaryNode::operator=(const BinaryNode&){return this;};
BinaryNode* BinaryNode::getLeft(){return left;};
BinaryNode* BinaryNode::getRight(){return right;};
void BinaryNode::setLeft(BinaryNode* node){left = node;};
void BinaryNode::setRight(BinaryNode* node){right = node;};
void BinaryNode::setData(int newData){data = newData;};
int BinaryNode::getData(){return data;};

//bool operator==(const BinaryNode& firstNode, const BinaryNode& secondNode){
//    if(firstNode == secondNode)
//        return true;
//    else
//        return false;
//};

class BinaryTree {
    public:
        void incrementCount();
        void decrementCount();
        BinaryTree();
        BinaryTree(int data);
        BinaryTree(BinaryNode*);
        BinaryNode* getRoot();
        void setRoot(int);
        void setRoot(BinaryNode*);
        int getCount();
        void addNode(BinaryNode*);
        void addNode(int);
        void inorderTraversal_Recur(BinaryNode* node);
        void inorderTraversal();
        BinaryNode* findNode(int targetData);
        BinaryNode* popNode(BinaryNode* nodeToPop);
    private:
        BinaryNode* root;
        int count;
};
void BinaryTree::incrementCount(){count++;};
void BinaryTree::decrementCount(){count--;};
BinaryTree::BinaryTree() : count{0} {root = new BinaryNode();};
BinaryTree::BinaryTree(BinaryNode* root) : root{root}, count{0} {};
BinaryTree::BinaryTree(int data){root = new BinaryNode(data);};
int BinaryTree::getCount(){return count;};
BinaryNode* BinaryTree::getRoot(){return root;};
void BinaryTree::setRoot(BinaryNode* node){if (!root)incrementCount(); root = node; };
void BinaryTree::setRoot(int data){if (!root)incrementCount(); root = new BinaryNode(data);};
void BinaryTree::addNode(BinaryNode* newNode){
    BinaryNode* node = root;
    while (node){
        if (node->getData() >= newNode->getData()){
            if (node->getLeft()){
                node = node->getLeft();
            }
            else{
                node->setLeft(newNode);
                break;
            }
        } else if (node->getData() < newNode->getData()) {
            if (node->getRight()){
                node = node->getRight();
            }
            else{
                node->setRight(newNode);
                break;
            }
        }
    }
    incrementCount();
};
void BinaryTree::addNode(int data){
    BinaryNode* newNode = new BinaryNode(data);
    addNode(newNode);
};
void BinaryTree::inorderTraversal(){
    BinaryNode* node = root;
    inorderTraversal_Recur(node);
};
void BinaryTree::inorderTraversal_Recur(BinaryNode* node){
    if (!node)
        return;
    inorderTraversal_Recur(node->getLeft());
    std::cout << node->getData() << std::endl;
    inorderTraversal_Recur(node->getRight());
};
BinaryNode* BinaryTree::findNode(int targetData){
    BinaryNode* node = root;
    while (node){
        if (node->getData() == targetData)
            return node;
        if (node->getData() > targetData){
            if (node->getLeft())
                node = node->getLeft();
            else
                return nullptr;
        } else if (node->getData() < targetData) {
            if (node->getRight())
                node = node->getRight();
            else
                return nullptr;
        }
    }
    return nullptr;
};

/*
     IN PROGRESS...
 */
BinaryNode* BinaryTree::popNode(BinaryNode* nodeToPop){
    BinaryNode *node, *previous = root;
//    while (node){
//        if (node == nodeToPop)
//            return node;
//        if (node->getData() > targetData){
//            if (node->getLeft())
//                node = node->getLeft();
//            else
//                return nullptr;
//        } else if (node->getData() < targetData) {
//            if (node->getRight())
//                node = node->getRight();
//            else
//                return nullptr;
//        }
//    }
    return nullptr;
//    if (nodeToPop->getLeft())
//
//    if (nodeToPop->getRight())
//
//    return nodeToPop;
}

//int main(){
//    BinaryTree tree = 0;
//    
//    BinaryNode one = BinaryNode(1);
//    BinaryNode two = BinaryNode(2);
//    BinaryNode three = 3;
//    tree.addNode(&one);
//    tree.addNode(&two);
//    tree.addNode(&three);
//    tree.addNode(4);
//    BinaryNode negOne = BinaryNode(-1);
//    BinaryNode negTwo = BinaryNode(-2);
//    BinaryNode negThree = -3;
//    BinaryNode dupNegTwo = BinaryNode(-2);
//    BinaryNode dupNegThree = -3;
//    tree.addNode(&negOne);
//    tree.addNode(&negTwo);
//    tree.addNode(&negThree);
//    tree.addNode(&dupNegTwo);
//    tree.addNode(&dupNegThree);
//    tree.inorderTraversal();
//    BinaryNode* node1 = tree.findNode(2);
//    BinaryNode* node2 = tree.findNode(18);
//    helpers::print(node1);
//    helpers::print(node2);
//
//    // this isn't working correctly. will fix.
//    tree.getCount();
//    
//    return 0;
//}
