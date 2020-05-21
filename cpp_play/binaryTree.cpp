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
        int getData() const;
        void setLeft(BinaryNode*);
        void setRight(BinaryNode*);
        void setData(int);
        bool isLeaf();
        bool isBranch();
        int height(); // not sure... needs testing.
        int height_RecurHelper(int count, BinaryNode *node); // not sure... needs testing.
    
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
int BinaryNode::getData()const{return data;};

bool BinaryNode::isLeaf(){
    return left == nullptr && right == nullptr;
};
bool BinaryNode::isBranch(){
    return left != nullptr || right != nullptr;
};
int BinaryNode::height_RecurHelper(int count, BinaryNode *node){
    if (node != nullptr){
        if (node->left)
            height_RecurHelper(count+1, node->left);
        if (node->right)
            height_RecurHelper(count+1, node->right);
    }
    return count;
};
int BinaryNode::height(){
    int count = 0;
    return std::max(height_RecurHelper(count, left), height_RecurHelper(count, right));
}

class BinarySearchTree {
    public:
        void incrementCount();
        void decrementCount();
    
        bool recurContainsHelper(BinaryNode* node, int data);
        bool contains(int item);
    
        bool recurContainsHelper(BinaryNode* node, BinaryNode* newNode);
        bool contains(BinaryNode* newNode);
    
        void recurInsertHelper(BinaryNode* node, BinaryNode* newNode);
        bool insert(int item);
    
        bool insert(BinaryNode* newNode);
        BinarySearchTree();
        BinarySearchTree(int data);
        BinarySearchTree(BinaryNode*);
        BinaryNode* getRoot();
        void setRoot(int);
        void setRoot(BinaryNode*);
        int getCount();
        BinarySearchTree(BinaryNode* nodes[], int len);
        BinarySearchTree(int items[], int len);
        bool isEmpty();
        int height();
        BinaryNode* findNodeIterative(int targetData);
        BinaryNode* recurFindHelper(BinaryNode* node, int item);
        BinaryNode* findNodeRecursive(int targetData);
        BinaryNode* recurFindParentHelper(BinaryNode* node, BinaryNode* parentNode, int item);
        BinaryNode* findParent(int item);
        BinaryNode* popNode(int item);
        BinaryNode* recurRemoveHelper(BinaryNode* targetNode, BinaryNode* minNode, bool right);
        bool remove(int item);
        void recurInorderTraversalHelper(BinaryNode* node);
        void inorderTraversal();
        void recurPostorderTraversalHelper(BinaryNode* node);
        void postorderTraversal();
        void recurPreorderTraversalHelper(BinaryNode* node);
        void preorderTraversal();
        void levelOrderTraversal();

    private:
        BinaryNode* root;
        int count; // NOT IMPLEMENTED.
};
void BinarySearchTree::incrementCount(){count++;};
void BinarySearchTree::decrementCount(){count--;};
bool BinarySearchTree::recurContainsHelper(BinaryNode* node, int item){
    if (node != nullptr){
        if (node->getData() == item)
            return true;
        recurContainsHelper(node->getLeft(), item);
        recurContainsHelper(node->getRight(), item);
    }
    return false;
};
bool BinarySearchTree::contains(int item){
    if (root != nullptr){
        return recurContainsHelper(root->getLeft(), item) || recurContainsHelper(root->getRight(), item);
    }
    return false;
};
bool BinarySearchTree::recurContainsHelper(BinaryNode* node, BinaryNode* newNode){
    if (node != nullptr){
        if (node->getData() == newNode->getData())
            return true;
        recurContainsHelper(node->getLeft(), newNode);
        recurContainsHelper(node->getRight(), newNode);
    }
    return false;
};
bool BinarySearchTree::contains(BinaryNode* newNode){
    if (root != nullptr){
        return recurContainsHelper(root->getLeft(), newNode) || recurContainsHelper(root->getRight(), newNode);
    }
    return false;
};
void BinarySearchTree::recurInsertHelper(BinaryNode* node, BinaryNode* newNode){
    if (node != nullptr){
        if (node->getData() > newNode->getData())
            if (node->getLeft())
                recurInsertHelper(node->getLeft(), newNode);
            else
                node->setLeft(newNode);
        else
            if (node->getRight())
                recurInsertHelper(node->getRight(), newNode);
            else
                node->setRight(newNode);
    }
};
bool BinarySearchTree::insert(int item){
    bool itemAlreadyPresent = contains(item);
    if (!itemAlreadyPresent){
        BinaryNode* newNode = new BinaryNode(item);
        recurInsertHelper(root, newNode);
    }
    return itemAlreadyPresent;
};
bool BinarySearchTree::insert(BinaryNode* newNode){
    bool itemAlreadyPresent = contains(newNode);
    if (!itemAlreadyPresent){
        recurInsertHelper(root, newNode);
    }
    return itemAlreadyPresent;
};
BinarySearchTree::BinarySearchTree(): count{0} {root = new BinaryNode();};
BinarySearchTree::BinarySearchTree(BinaryNode* root): root{root}, count{0} {};
int BinarySearchTree::getCount(){return count;};
BinaryNode* BinarySearchTree::getRoot(){return root;};
void BinarySearchTree::setRoot(BinaryNode* node){if (!root)incrementCount(); root = node; };
void BinarySearchTree::setRoot(int data){if (!root)incrementCount(); root = new BinaryNode(data);};
BinarySearchTree::BinarySearchTree(int data){root = new BinaryNode(data);};
BinarySearchTree::BinarySearchTree(BinaryNode* nodes[], int len){
    for (int i = 0; i < len; i++)
        insert(nodes[i]);
};
BinarySearchTree::BinarySearchTree(int items[], int len){
    for (int i = 0; i < len; i++)
        insert(items[i]);
};
bool BinarySearchTree::isEmpty(){
    return root == nullptr;
};
int BinarySearchTree::height(){
    return root->height();
};
BinaryNode* BinarySearchTree::findNodeIterative(int targetData){
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
BinaryNode* BinarySearchTree::recurFindHelper(BinaryNode* node, int item){
    if (node != nullptr){
        if (node->getData() == item)
            return node;
        recurFindHelper(node->getLeft(), item);
        recurFindHelper(node->getRight(), item);
    }
    return nullptr;
};
BinaryNode* BinarySearchTree::findNodeRecursive(int targetData){
    BinaryNode* targetNode = recurFindHelper(root, targetData);
    return targetNode;
};
BinaryNode* BinarySearchTree::recurFindParentHelper(BinaryNode* node, BinaryNode* parentNode, int item){
    if (node != nullptr)
        if (node->getData()){
            return parentNode;
        }
        recurFindParentHelper(node->getLeft(), node, item);
        recurFindParentHelper(node->getRight(), node, item);
    return nullptr;
};
BinaryNode* BinarySearchTree::findParent(int item){
    return recurFindParentHelper(root, nullptr, item);
};
BinaryNode* BinarySearchTree::popNode(int item){
    bool itemIsInTree = contains(item);
    BinaryNode* targetNode = nullptr;
    if (itemIsInTree){
        targetNode = findNodeRecursive(item);
        remove(item);
    }
    return targetNode;
};
BinaryNode* BinarySearchTree::recurRemoveHelper(BinaryNode* node, BinaryNode* minOrMaxNodeOfSubtree, bool right){
    if (node){
        bool condition;
        if (right)
            condition = node->getData() < minOrMaxNodeOfSubtree->getData();
        else
            condition = node->getData() > minOrMaxNodeOfSubtree->getData();
        if (condition)
            minOrMaxNodeOfSubtree = node;
        recurRemoveHelper(node->getLeft(), minOrMaxNodeOfSubtree, right);
        recurRemoveHelper(node->getRight(), minOrMaxNodeOfSubtree, right);
    }
    return minOrMaxNodeOfSubtree;
};
// i really don't think this works. need to test.
bool BinarySearchTree::remove(int item){
    bool itemIsInTree = contains(item);
    if (itemIsInTree){
        BinaryNode* targetNode = findNodeRecursive(item);
        BinaryNode* minOrMaxNodeOfSubtree = nullptr;
        if (targetNode->isLeaf()) {
            BinaryNode* parentOfTargetNode = findParent(item);
            if (parentOfTargetNode->getLeft()->getData() == item)
                parentOfTargetNode->setLeft(nullptr);
            else
                parentOfTargetNode->setRight(nullptr);
        } else {
                if (targetNode->getRight())
                    minOrMaxNodeOfSubtree = recurRemoveHelper(targetNode, nullptr, true);
                else
                    minOrMaxNodeOfSubtree = recurRemoveHelper(targetNode, nullptr, false);
            }
        if (minOrMaxNodeOfSubtree){
            BinaryNode* rootLeft = root->getLeft();
            BinaryNode* rootRight = root->getRight();
            minOrMaxNodeOfSubtree->setLeft(rootLeft);
            minOrMaxNodeOfSubtree->setRight(rootRight);
            root->setLeft(nullptr);
            root->setRight(nullptr);
        }
        if (targetNode == root){
            if (minOrMaxNodeOfSubtree)
                root = minOrMaxNodeOfSubtree;
            else
                root = nullptr;
        }
    }
    return itemIsInTree;
};
void BinarySearchTree::recurInorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    recurInorderTraversalHelper(node->getLeft());
    std::cout << node->getData() << std::endl;
    recurInorderTraversalHelper(node->getRight());
};
void BinarySearchTree::inorderTraversal(){
    BinaryNode* node = root;
    recurInorderTraversalHelper(node);
};
void BinarySearchTree::recurPostorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    recurPostorderTraversalHelper(node->getLeft());
    recurPostorderTraversalHelper(node->getRight());
    std::cout << node->getData() << std::endl;
};
void BinarySearchTree::postorderTraversal(){
    BinaryNode* node = root;
    recurPostorderTraversalHelper(node);
};
void BinarySearchTree::recurPreorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    std::cout << node->getData() << std::endl;
    recurPreorderTraversalHelper(node->getLeft());
    recurPreorderTraversalHelper(node->getRight());
};
void BinarySearchTree::preorderTraversal(){
    BinaryNode* node = root;
    recurPreorderTraversalHelper(node);
};
void BinarySearchTree::levelOrderTraversal(){
    // need to write a Queue class.
};
