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
        void setLeft(BinaryNode*);
        void setRight(BinaryNode*);
        void setData(int);
        int getData();
    private:
        BinaryNode* left;
        BinaryNode* right;
        int data;
};
BinaryNode::BinaryNode(){};
BinaryNode::BinaryNode(int data) : data{data} {};
BinaryNode* BinaryNode::getLeft(){return left;};
BinaryNode* BinaryNode::getRight(){return right;};
void BinaryNode::setLeft(BinaryNode* node){left = node;};
void BinaryNode::setRight(BinaryNode* node){right = node;};
void BinaryNode::setData(int data){data = data;};
int BinaryNode::getData(){return data;};

class BinaryTree {
    public:
        BinaryTree();
        BinaryTree(int data);
        BinaryTree(BinaryNode*);
        BinaryNode* getRoot();
        void setRoot(int);
        void setRoot(BinaryNode*);
        int getCount();
        void incrementCount();
        void decrementCount();
        void addNode(int);
        void addNode(BinaryNode*);
        void inorderTraversal();
    private:
        BinaryNode* root;
        int count;
};
BinaryTree::BinaryTree(){root = new BinaryNode();};
BinaryTree::BinaryTree(BinaryNode* root) : root{root} {};
BinaryTree::BinaryTree(int data){root = new BinaryNode(data);};
int BinaryTree::getCount(){return count;};
void BinaryTree::incrementCount(){count++;};
void BinaryTree::decrementCount(){count--;};
BinaryNode* BinaryTree::getRoot(){return root;};
void BinaryTree::setRoot(BinaryNode* root){root = root; incrementCount();};
void BinaryTree::setRoot(int data){root = new BinaryNode(data); incrementCount();};
void BinaryTree::addNode(BinaryNode* newNode){
        BinaryNode* node = root;
        int i = 0;
        while (node){
            // this tree sets equal nodes to the left side of the tree.
            if (node->getData() == newNode->getData()){
                // check if node->left is empty
                // if it is, set the current node's left to newNode
                // if it's not, go left
                if (node->getLeft()){
                    node = node->getLeft();
                    std::cout << node->getData() << "hi" << node->getLeft() << std::endl;
                    break;
                }
                else
                    node->setLeft(newNode);
            } else if (node->getData() < newNode->getData()) {
                // check if node->right is empty
                // if it is, set the current node's right to newNode
                // if it's not, go right
                if (node->getRight()){
                    node = node->getRight();
                    std::cout << node->getData() << "hi" << std::endl;
                    break;
                }
                else{
                    node->setRight(newNode);
                    std::cout << node->getRight()->getData() << "hello" << std::endl;
                }
            } else if (node->getData() > newNode->getData()) {
                // check if node->left is empty
                // if it is, set the current node's left to newNode
                // if it's not, go left
                if (node->getLeft()){
                    node = node->getLeft();
                    std::cout << node->getData() << "hi" << std::endl;
                    break;
                }
                else
                    node->setLeft(newNode);
            }
            i++;
            if (i>100)
                break;
        }
  
        incrementCount();
};
void BinaryTree::addNode(int data){
    BinaryNode* newNode = new BinaryNode(data);
    addNode(newNode);
};
void BinaryTree::inorderTraversal(){
    //    left
    //    data
    //    right
    BinaryNode* node = root;
    while(node){
        if (node->getLeft()){
           node = node->getLeft();
        } else if (node->getData()){
            std::cout << node->getData() << std::endl;
        } else if (node->getRight()) {
            node = node->getRight();
        }
    }
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
    
//    tree.inorderTraversal();
    
    return 0;
}
