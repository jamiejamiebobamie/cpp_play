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

class BinaryTree {
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
        BinaryTree();
        BinaryTree(int data);
        BinaryTree(BinaryNode*);
        BinaryNode* getRoot();
        void setRoot(int);
        void setRoot(BinaryNode*);
        int getCount();
        BinaryTree(BinaryNode* nodes[], int len);
        BinaryTree(int items[], int len);
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
        int count;
};
void BinaryTree::incrementCount(){count++;};
void BinaryTree::decrementCount(){count--;};
bool BinaryTree::recurContainsHelper(BinaryNode* node, int item){
    if (node != nullptr){
        if (node->getData() == item)
            return true;
        recurContainsHelper(node->getLeft(), item);
        recurContainsHelper(node->getRight(), item);
    }
    return false;
};
bool BinaryTree::contains(int item){
    if (root != nullptr){
        return recurContainsHelper(root->getLeft(), item) || recurContainsHelper(root->getRight(), item);
    }
    return false;
};
bool BinaryTree::recurContainsHelper(BinaryNode* node, BinaryNode* newNode){
    if (node != nullptr){
        if (node->getData() == newNode->getData())
            return true;
        recurContainsHelper(node->getLeft(), newNode);
        recurContainsHelper(node->getRight(), newNode);
    }
    return false;
};
bool BinaryTree::contains(BinaryNode* newNode){
    if (root != nullptr){
        return recurContainsHelper(root->getLeft(), newNode) || recurContainsHelper(root->getRight(), newNode);
    }
    return false;
};
void BinaryTree::recurInsertHelper(BinaryNode* node, BinaryNode* newNode){
    if (node != nullptr){
        // if the current node's data is greater than the newNode's data
        // check if there is a node present to the left
        // if there is recur, if not add the new node as the left child
        if (node->getData() > newNode->getData())
            if (node->getLeft())
                recurInsertHelper(node->getLeft(), newNode);
            else
                node->setLeft(newNode);
        // the current node's data is less than the newNode's data
        // check if there is a node present to the right
        // if there is recur, if not add the new node as the right child
        else
            if (node->getRight())
                recurInsertHelper(node->getRight(), newNode);
            else
                node->setRight(newNode);
    }
};
bool BinaryTree::insert(int item){
    bool itemAlreadyPresent = contains(item);
    if (!itemAlreadyPresent){
        BinaryNode* newNode = new BinaryNode(item);
        recurInsertHelper(root, newNode);
    }
    return itemAlreadyPresent;
};
bool BinaryTree::insert(BinaryNode* newNode){
    bool itemAlreadyPresent = contains(newNode);
    if (!itemAlreadyPresent){
        recurInsertHelper(root, newNode);
    }
    return itemAlreadyPresent;
};
BinaryTree::BinaryTree(): count{0} {root = new BinaryNode();};
BinaryTree::BinaryTree(BinaryNode* root): root{root}, count{0} {};
int BinaryTree::getCount(){return count;};
BinaryNode* BinaryTree::getRoot(){return root;};
void BinaryTree::setRoot(BinaryNode* node){if (!root)incrementCount(); root = node; };
void BinaryTree::setRoot(int data){if (!root)incrementCount(); root = new BinaryNode(data);};
BinaryTree::BinaryTree(int data){root = new BinaryNode(data);};
BinaryTree::BinaryTree(BinaryNode* nodes[], int len){
    for (int i = 0; i < len; i++)
        insert(nodes[i]);
};
BinaryTree::BinaryTree(int items[], int len){
    for (int i = 0; i < len; i++)
        insert(items[i]);
};
bool BinaryTree::isEmpty(){
    return root == nullptr;
};
int BinaryTree::height(){
    return root->height();
};
BinaryNode* BinaryTree::findNodeIterative(int targetData){
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
BinaryNode* BinaryTree::recurFindHelper(BinaryNode* node, int item){
    if (node != nullptr){
        if (node->getData() == item)
            return node;
        recurFindHelper(node->getLeft(), item);
        recurFindHelper(node->getRight(), item);
    }
    return nullptr;
};
BinaryNode* BinaryTree::findNodeRecursive(int targetData){
    BinaryNode* targetNode = recurFindHelper(root, targetData);
    return targetNode;
};
BinaryNode* BinaryTree::recurFindParentHelper(BinaryNode* node, BinaryNode* parentNode, int item){
    if (node != nullptr)
        if (node->getData()){
            return parentNode;
        }
        recurFindParentHelper(node->getLeft(), node, item);
        recurFindParentHelper(node->getRight(), node, item);
    return nullptr;
};
BinaryNode* BinaryTree::findParent(int item){
    return recurFindParentHelper(root, nullptr, item);
};
BinaryNode* BinaryTree::popNode(int item){
    BinaryNode* targetNode = findNodeRecursive(item);
    remove(item);
    return targetNode;
};
// i really don't think this works. need to test.
BinaryNode* BinaryTree::recurRemoveHelper(BinaryNode* node, BinaryNode* minOrMaxNodeOfSubtree, bool right){
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
bool BinaryTree::remove(int item){
    bool itemIsInTree = contains(item);
    if (itemIsInTree){
        BinaryNode* targetNode = findNodeRecursive(item);
        BinaryNode* minNodeOfSubTree = nullptr;
        if (targetNode->isLeaf()) {
            BinaryNode* parentOfTargetNode = findParent(item);
            if (parentOfTargetNode->getLeft()->getData() == item)
                parentOfTargetNode->setLeft(nullptr);
            else
                parentOfTargetNode->setRight(nullptr);
        } else {
                if (targetNode->getRight())
                    BinaryNode* minNodeOfSubTree = recurRemoveHelper(targetNode, nullptr, true);
                else
                    BinaryNode* minNodeOfSubTree = recurRemoveHelper(targetNode, nullptr, false);
            }
        if (minNodeOfSubTree){
            BinaryNode* rootLeft = root->getLeft();
            BinaryNode* rootRight = root->getRight();
            minNodeOfSubTree->setLeft(rootLeft);
            minNodeOfSubTree->setRight(rootRight);
            root->setLeft(nullptr);
            root->setRight(nullptr);
        }
        // change the root if it was the targetNode for removal.
        if (targetNode == root){
            if (minNodeOfSubTree)
                root = minNodeOfSubTree;
            else
                root = nullptr;
        }
    }
    return itemIsInTree;
};
void BinaryTree::recurInorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    recurInorderTraversalHelper(node->getLeft());
    std::cout << node->getData() << std::endl;
    recurInorderTraversalHelper(node->getRight());
};
void BinaryTree::inorderTraversal(){
    BinaryNode* node = root;
    recurInorderTraversalHelper(node);
};
void BinaryTree::recurPostorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    recurPostorderTraversalHelper(node->getLeft());
    recurPostorderTraversalHelper(node->getRight());
    std::cout << node->getData() << std::endl;
};
void BinaryTree::postorderTraversal(){
    BinaryNode* node = root;
    recurPostorderTraversalHelper(node);
};
void BinaryTree::recurPreorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    std::cout << node->getData() << std::endl;
    recurPreorderTraversalHelper(node->getLeft());
    recurPreorderTraversalHelper(node->getRight());
};
void BinaryTree::preorderTraversal(){
    BinaryNode* node = root;
    recurPreorderTraversalHelper(node);
};
void BinaryTree::levelOrderTraversal(){
    // need to write a Queue class.
};
