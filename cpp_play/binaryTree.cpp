//
//  binaryTree.cpp
//  cpp_play
//
//  Created by James McCrory on 5/2/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include "binaryTree.hpp"
#include<iostream>
#include"helperFunctions.cpp"

class BinaryNode {
    public:
        BinaryNode();
        BinaryNode(int);
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
BinaryNode* BinaryNode::getLeft(){return left;};
BinaryNode* BinaryNode::getRight(){return right;};
void BinaryNode::setLeft(BinaryNode* node){left = node;};
void BinaryNode::setRight(BinaryNode* node){right = node;};
void BinaryNode::setData(int data){data = data;};
int BinaryNode::getData(){return data;};

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

int main(){
    BinaryTree tree = 0;
    
    BinaryNode one = BinaryNode(1);
    BinaryNode two = BinaryNode(2);
    BinaryNode three = 3;
    tree.addNode(&one);
    tree.addNode(&two);
    tree.addNode(&three);
    tree.addNode(4);
    BinaryNode negOne = BinaryNode(-1);
    BinaryNode negTwo = BinaryNode(-2);
    BinaryNode negThree = -3;
    BinaryNode dupNegTwo = BinaryNode(-2);
    BinaryNode dupNegThree = -3;
    tree.addNode(&negOne);
    tree.addNode(&negTwo);
    tree.addNode(&negThree);
    tree.addNode(&dupNegTwo);
    tree.addNode(&dupNegThree);
    tree.inorderTraversal();
    
    // this isn't working correctly. will fix.
    tree.getCount();
    
    return 0;
}
