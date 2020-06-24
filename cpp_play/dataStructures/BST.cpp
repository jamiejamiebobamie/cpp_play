//
//  BST.cpp
//  cpp_play
//
//  Created by James McCrory on 5/24/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include<iostream>
#include"LL.cpp"

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
BinaryNode::BinaryNode(): data(0), left(nullptr), right(nullptr) {};
BinaryNode::BinaryNode(int data) : data(data), left(nullptr), right(nullptr) {};
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
    if (node)
        // only increment the count if there is a node. root's height = 0.
        count = std::max(height_RecurHelper(count+1, node->left), height_RecurHelper(count+1, node->right));
    return count;
};
int BinaryNode::height(){
    return std::max(height_RecurHelper(0, left), height_RecurHelper(0, right));
}

class BST {
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
        BST();
        BST(int data);
        BST(BinaryNode*);
        BinaryNode* getRoot();
        int getCount();
        BST(BinaryNode* nodes[], int len);
        BST(int items[], int len);
        bool isEmpty();
        int height();
        BinaryNode* findNodeIterative(int targetData);
        BinaryNode* recurFindHelper(BinaryNode* node, int item);
        BinaryNode* findNodeRecursive(int targetData);
        BinaryNode* recurFindParentHelper(BinaryNode* node, BinaryNode* parentNode, int item);
        BinaryNode* findParent(int item);
        BinaryNode* popNode(int item);
        BinaryNode* recurRemoveHelper(BinaryNode* targetNode, BinaryNode* minNode, int item, bool swappingRight);
        bool remove(int item);
        void recurInorderTraversalHelper(BinaryNode* node);
        void inorderTraversal();
        void recurPostorderTraversalHelper(BinaryNode* node);
        void postorderTraversal();
        void recurPreorderTraversalHelper(BinaryNode* node);
        void preorderTraversal();
        void recurLevelOrderTraversalHelper(BinaryNode* node, LinkedList<int>* queue);
        void levelOrderTraversal();

    private:
        BinaryNode* root;
        int count;
};
void BST::incrementCount(){count++;};
void BST::decrementCount(){count--;};
bool BST::recurContainsHelper(BinaryNode* node, int item){
    if (node){
        if (node->getData() == item)
            return true;
        return recurContainsHelper(node->getLeft(), item) || recurContainsHelper(node->getRight(), item);
    }
    return false;
};
bool BST::contains(int item){
    if (root){
        if (root->getData() == item)
            return true;
        return recurContainsHelper(root->getLeft(), item) || recurContainsHelper(root->getRight(), item);
    }
    return false;
};
bool BST::recurContainsHelper(BinaryNode* node, BinaryNode* newNode){
    if (node != nullptr){
        if (node == newNode)
            return true;
        return recurContainsHelper(node->getLeft(), newNode) || recurContainsHelper(node->getRight(), newNode);
    }
    return false;
};
bool BST::contains(BinaryNode* newNode){
    if (root != nullptr){
        if (root == newNode)
            return true;
        return recurContainsHelper(root->getLeft(), newNode) || recurContainsHelper(root->getRight(), newNode);
    }
    return false;
};
void BST::recurInsertHelper(BinaryNode* node, BinaryNode* newNode){
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
bool BST::insert(int item){
    if (!root){
        BinaryNode* newNode = new BinaryNode(item);
        root = newNode;
        incrementCount();
        return true;
    }
    bool itemAlreadyPresent = contains(item);
    if (!itemAlreadyPresent){
        BinaryNode* newNode = new BinaryNode(item);
        incrementCount();
        recurInsertHelper(root, newNode);
    }
    return itemAlreadyPresent;
};
bool BST::insert(BinaryNode* newNode){
    if (!root){
        root = newNode;
        incrementCount();
        return true;
    }
    bool itemAlreadyPresent = contains(newNode);
    if (!itemAlreadyPresent){
        incrementCount();
        recurInsertHelper(root, newNode);
    }
    return itemAlreadyPresent;
};
BST::BST(): count(0) {root = nullptr;};
BST::BST(BinaryNode* root): root{root}, count(0) {incrementCount();};
int BST::getCount(){return count;};
BinaryNode* BST::getRoot(){return root;};
BST::BST(int data): count(0) {root = new BinaryNode(data);incrementCount();};
BST::BST(BinaryNode* nodes[], int len): count(0){
    for (int i = 0; i < len; i++){
        insert(nodes[i]);
    }
};
BST::BST(int items[], int len): count(0){
    for (int i = 0; i < len; i++){
        insert(items[i]);
    }
};
bool BST::isEmpty(){
    return root == nullptr;
};
int BST::height(){
    if (root)
        return root->height();
    return 0;
};
BinaryNode* BST::findNodeIterative(int targetData){
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
// this works but needs to be refactored.
BinaryNode* BST::recurFindHelper(BinaryNode* node, int item){
    BinaryNode* possibleP = nullptr;
    if (node != nullptr){
        if (node->getData() == item)
            return node;
        possibleP = recurFindHelper(node->getLeft(), item);
        if (!possibleP)
            possibleP = recurFindHelper(node->getRight(), item);
    }
    return possibleP;
};
BinaryNode* BST::findNodeRecursive(int targetData){
    BinaryNode* targetNode = recurFindHelper(root, targetData);
    return targetNode;
};
// this works but needs to be refactored.
BinaryNode* BST::recurFindParentHelper(BinaryNode* node, BinaryNode* parentNode, int item){
    BinaryNode* possibleP = nullptr;
    if (node != nullptr){
        if (node->getData() == item){
            return parentNode;
        }
        possibleP = recurFindParentHelper(node->getLeft(), node, item);
        if (!possibleP)
            possibleP = recurFindParentHelper(node->getRight(), node, item);
    }
    return possibleP;
};
BinaryNode* BST::findParent(int item){
    return recurFindParentHelper(root, nullptr, item);
};
BinaryNode* BST::popNode(int item){
    bool itemIsInTree = contains(item);
    BinaryNode* targetNode = nullptr;

    if (itemIsInTree){
        targetNode = new BinaryNode(item);
        remove(item);
    }
    return targetNode;
};
BinaryNode* BST::recurRemoveHelper(BinaryNode* currNode, BinaryNode* currMaxOrMin, int item, bool swappingRight){
        if (currNode){
            bool condition;
            // looking for the minimum in the right tree
            if (swappingRight)
                condition = currNode->getData() > currMaxOrMin->getData();
            // looking for the maximum in the left tree
            else
                condition = currNode->getData() < currMaxOrMin->getData();
            if (condition){
//                    std::cout << "currNode: " << currNode->getData() << " currMaxOrMin: " << currMaxOrMin->getData() <<" swappingRight: "<<swappingRight<< std::endl;
                    currMaxOrMin = currNode;
                }
            currMaxOrMin = recurRemoveHelper(currNode->getLeft(), currMaxOrMin, item, swappingRight);
            }
    return currMaxOrMin;
};
// working except for when the node to remove is the root.
    // also need to test for other edge cases.
bool BST::remove(int item){
    bool itemIsInTree = contains(item);
    if (itemIsInTree){
        BinaryNode* nodeToRemove = findNodeRecursive(item);
        BinaryNode* parentOfNodeToRemove = findParent(item);
        BinaryNode* minOrMaxNodeOfSubtree = nullptr;

        if (nodeToRemove->isLeaf()) {
            if (parentOfNodeToRemove->getLeft()->getData() == item){
                parentOfNodeToRemove->setLeft(nullptr);
            } else{
                parentOfNodeToRemove->setRight(nullptr);
            }
        } else {
            // if node is not a leaf, find the minimum node on of the right side or the maximum node of the left side
                // and swap that node with the nodeToRemove
            if (nodeToRemove->getRight()){
                minOrMaxNodeOfSubtree = recurRemoveHelper(nodeToRemove, nodeToRemove->getRight(), item, true);
            } else{
                minOrMaxNodeOfSubtree = recurRemoveHelper(nodeToRemove, nodeToRemove->getLeft(), item, false);
            }

            int minOrMaxValue = minOrMaxNodeOfSubtree->getData();
            BinaryNode* parentOfMinOrMaxNodeOfSubtree = findParent(minOrMaxValue);
            
            if(parentOfNodeToRemove)
                std::cout<<"parentOfNodeToRemove: " <<parentOfNodeToRemove->getData()<<std::endl;
            if(nodeToRemove)
                std::cout<<"nodeToRemove: " << nodeToRemove->getData() <<std::endl;
            if(minOrMaxNodeOfSubtree)
                std::cout<<"minOrMaxNodeOfSubtree: "<<minOrMaxNodeOfSubtree->getData() <<std::endl;
            if(parentOfMinOrMaxNodeOfSubtree)
                std::cout<<"parentOfMinOrMaxNodeOfSubtree: " << parentOfMinOrMaxNodeOfSubtree->getData()<<std::endl;
            
            if (parentOfMinOrMaxNodeOfSubtree->getRight()){
                if (parentOfMinOrMaxNodeOfSubtree->getRight()->getData() == minOrMaxValue){
                    parentOfMinOrMaxNodeOfSubtree->setRight(nullptr);
                }
            } else if (parentOfMinOrMaxNodeOfSubtree->getLeft()) {
                if (parentOfMinOrMaxNodeOfSubtree->getLeft()->getData() == minOrMaxValue){
                parentOfMinOrMaxNodeOfSubtree->setLeft(nullptr);
            }
            }
            // swap the data of the minOrMaxNodeOfSubtree node with its parent.
            nodeToRemove->setData(minOrMaxValue);

            if (nodeToRemove == root){
                if (minOrMaxNodeOfSubtree)
                    root = minOrMaxNodeOfSubtree;
                else
                    root = nullptr;
            }
            decrementCount();
        }
    }
    return itemIsInTree;
};
void BST::recurInorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    recurInorderTraversalHelper(node->getLeft());
    std::cout << node->getData() << std::endl;
    recurInorderTraversalHelper(node->getRight());
};
void BST::inorderTraversal(){
    BinaryNode* node = root;
    recurInorderTraversalHelper(node);
};
void BST::recurPostorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    recurPostorderTraversalHelper(node->getLeft());
    recurPostorderTraversalHelper(node->getRight());
    std::cout << node->getData() << std::endl;
};
void BST::postorderTraversal(){
    BinaryNode* node = root;
    recurPostorderTraversalHelper(node);
};
void BST::recurPreorderTraversalHelper(BinaryNode* node){
    if (!node)
        return;
    std::cout << node->getData() << std::endl;
    recurPreorderTraversalHelper(node->getLeft());
    recurPreorderTraversalHelper(node->getRight());
};
void BST::preorderTraversal(){
    BinaryNode* node = root;
    recurPreorderTraversalHelper(node);
};
 void BST::recurLevelOrderTraversalHelper(BinaryNode* node, LinkedList<int>* queue){
     if (node){
         if (node->getLeft())
             queue->append(node->getLeft()->getData());
        if (node->getRight())
             queue->append(node->getRight()->getData());
         recurLevelOrderTraversalHelper(node->getLeft(),queue);
         recurLevelOrderTraversalHelper(node->getRight(),queue);
     }
}
// this prints off a blank newline at the end. need to fix.
void BST::levelOrderTraversal(){
    if (root){
        LinkedList<int> queue = LinkedList<int>();
        queue.append(root->getData());
        recurLevelOrderTraversalHelper(root,&queue);
        queue.printList();
    }
};


//int main() {
    
    //    IN PROGRESS METHODS...
    
    //    BST(BinaryNode* nodes[], int len);
    //    BST(int items[], int len);
    
    //    BinaryNode* recurRemoveHelper(BinaryNode* targetNode, BinaryNode* minNode, bool right);
    //    bool remove(int item);
//
//    BST bst = BST();
//
//    bst.insert(2);
//    bst.insert(-3);
//    bst.insert(5);
//    bst.insert(-5);
//    bst.insert(-4);
//    bst.insert(-9);
//    bst.insert(-1);
//    bst.insert(-2);
//    bst.insert(0);
//    bst.insert(4);
//
//    bst.postorderTraversal();
//
//    bst.remove(2);
//
//    std::cout << " " << std::endl;



    /*
                    2
                -3      5
             -5   -1   4
           -9 -4 -2 0
            
     */
//    bst.remove(-2); // doesn't work on the root
//    bst.postorderTraversal();

//    return 0;
//}
