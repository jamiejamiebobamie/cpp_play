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
        
        // implement________
        bool isLeaf();
        bool isBranch();
        int height();
        int height_RecurHelper();
        // _________________
    
    private:
        BinaryNode* left;
        BinaryNode* right;
        int data;
};
BinaryNode::BinaryNode(): data{0}, left{nullptr}, right{nullptr} {};
BinaryNode::BinaryNode(int data) : data{data}, left{nullptr}, right{nullptr} {};
BinaryNode* BinaryNode::operator=(const BinaryNode&){return this;};
BinaryNode* BinaryNode::getLeft(){return left;};
BinaryNode* BinaryNode::getRight(){return right;};
void BinaryNode::setLeft(BinaryNode* node){left = node;};
void BinaryNode::setRight(BinaryNode* node){right = node;};
void BinaryNode::setData(int newData){data = newData;};
int BinaryNode::getData(){return data;};

class BinaryTree {
    public:
        void incrementCount();
        void decrementCount();
        BinaryTree();
        BinaryTree(int data);
        BinaryTree(BinaryNode*);
    
        // implement________
        BinaryTree(BinaryNode*[]);
        BinaryTree(int[]);
        // _________________
    
        BinaryNode* getRoot();
        void setRoot(int);
        void setRoot(BinaryNode*);
        int getCount();

    
    // implement________
        bool isEmpty();
        int height();
        BinaryNode* findNode(int targetData);
    //        BinaryNode* findNode(int item);
        BinaryNode* findNode_Recur(int item);
        BinaryNode* findParent(int targetData);
    //        BinaryNode* findNode(int item);
        BinaryNode* findParent_Recur(int item, BinaryNode* parentNode);
        bool contains(int item);
        BinaryNode* getNode(int item);
        bool insert(int item);
        void inorderTraversal_Recur(BinaryNode* node);
        void inorderTraversal();
    //        void inorderTraversal();
        void postorderTraversal_Recur(BinaryNode* node);
        void postorderTraversal();
        void preorderTraversal_Recur(BinaryNode* node);
        void preorderTraversal();
        void levelOrderTraversal();
        void printInorder();
        void printPostorder();
        void printPreorder();
        void printLevelOrder();
        BinaryNode* popNode(BinaryNode* nodeToPop);
        bool remove(int item);
    // _________________

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
int main(){
    BinaryTree tree = 0;
    
    BinaryNode one = BinaryNode(1);
    BinaryNode two = BinaryNode(2);
    BinaryNode three = 3;
    BinaryNode negOne = BinaryNode(-1);
    BinaryNode negTwo = BinaryNode(-2);
    BinaryNode negThree = -3;
    BinaryNode dupNegTwo = BinaryNode(-2);
    BinaryNode dupNegThree = -3;
    
    
    return 0;
}

