//
//  HashTable.cpp
//  cpp_play
//
//  Created by James McCrory on 5/21/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

//https://github.com/jamiejamiebobamie/CS-1.3-Core-Data-Structures/blob/master/Lessons/source/hashtable.py

#include <iostream>
#include "LinkedList.cpp"

template<class K, class V>
struct HashTableEntry{
    K *key;
    V *value;
    int hashCode;
};

template<class K, class V>
class HashTable{
public:
    HashTable(int maxSize);
    const size_t hashKey(K key);
    int bucketIndex(K key);
    int loadFactor();
    void printAllKeys();
    void printAllValues();
    LinkedList<HashTableEntry<K,V>*>* getListOfItems();
    int length();
    bool contains(K key);
    V get(K key);
    void set(K key, V value);
    void deleteEntry(K key);
    void resize();
private:
    // !!!...not implemented...!!!
    int currentSize; // number of buckets with at least one entry in the linkedlist.
    int maxSize; // max number of buckets
    LinkedList<HashTableEntry<K, V>*>* buckets;
};
template<class K, class V>
HashTable<K,V>::HashTable(int maxSize): maxSize(maxSize), currentSize(0) {
    for (int i = 0; i < maxSize; i++ ){
        buckets[i] = new LinkedList<HashTableEntry<K, V>*>;
    }
};
template<class K, class V>
const size_t HashTable<K,V>::hashKey(K key){
    std::hash<K> h;
    const size_t value = h(key);
    return value;
};
template<class K, class V>
int HashTable<K,V>::bucketIndex(K key){
    return hashKey(key) % maxSize;
};
template<class K, class V>
int HashTable<K,V>::loadFactor(){
    if (!currentSize)
        return currentSize;
    else
        return float(currentSize)/float(maxSize);
}
template<class K, class V>
void HashTable<K,V>::printAllKeys(){
    if (!currentSize){
        std::cout << "No items in HashTable" << std::endl;
        return;
    }
    for (int i = 0; i < maxSize; i++ ){
        LinkedListNode<HashTableEntry<K, V>*>* node = buckets[i].getHead();
        while(node){
            std::cout << &(node->getData()->key) << std::endl;
            node = node->getNext();
        }
    }
}
template<class K, class V>
void HashTable<K,V>::printAllValues(){
    if (!currentSize){
        std::cout << "No items in HashTable" << std::endl;
        return;
    }
    for (int i = 0; i < maxSize; i++ ){
        LinkedListNode<HashTableEntry<K, V>*>* node = buckets[i].getHead();
        while(node){
            std::cout << &(node->getData()->value) << std::endl;
            node = node->getNext();
        }
    }
}
template<class K, class V>
LinkedList<HashTableEntry<K,V>*>* HashTable<K,V>::getListOfItems(){
    LinkedList<HashTableEntry<K,V>*>* storeItemsList = new LinkedList<HashTableEntry<K,V>*>();
    for (int i = 0; i < maxSize; i++ ){
        LinkedListNode<HashTableEntry<K, V>*>* node = buckets[i].getHead();
        while(node){
            storeItemsList->append(node);
            node = node->getNext();
        }
    }
    return storeItemsList;
}
template<class K, class V>
int HashTable<K,V>::length(){
    if (!currentSize){
        return 0;
    }
    int length = 0;
    for (int i = 0; i < maxSize; i++ ){
        LinkedListNode<HashTableEntry<K, V>*>* node = buckets[i].getHead();
        while(node){
            length++;
            node = node->getNext();
        }
    }
    return length;
}
template<class K, class V>
bool HashTable<K,V>::contains(K key){
    if (!currentSize){
        return false;
    }
    int index = bucketIndex(key);
    LinkedListNode<HashTableEntry<K, V>*>* node = buckets[index]->getHead();
    while(node){
        if (node->getData()->key == key)
            return true;
        node = node->getNext();
    }
    return false;
};
template<class K, class V>
V HashTable<K,V>::get(K key){
    if (!currentSize){
        return nullptr;
    }
    int index = bucketIndex(key);
    LinkedListNode<HashTableEntry< K, V>*>* node = buckets[index]->getHead();
    while(node){
        K nodeKey = &(node->getData()->key);
        if (nodeKey == key)
            return &(node->getData()->value);
        node = node->getNext();
    }
    return nullptr;
};
template<class K, class V>
void HashTable<K,V>::set(K key, V value){
    HashTableEntry<K,V>* newEntry = new struct HashTableEntry<K,V>; // do i need the 'struct' keyword before the type declaration?
    newEntry->key = key;
    newEntry->value = value;
    newEntry->hash = hashKey(key);
    int index = bucketIndex(key);
    LinkedListNode<HashTableEntry< K, V>*>* node = buckets[index]->getHead();
    while(node){
        K nodeKey = &(node->getData()->key);
        if (nodeKey == key){
            buckets[index]->removeNode(node);
            resize();
            break;
        }
        node = node->getNext();
    }
    // if the head is empty, the list is empty. increment the currentSize of the hashtable.
        // as a new bucket has been filled.
    if ( buckets[index]->getHead() == nullptr )
        currentSize++;
    buckets[index]->append(newEntry);
};
template<class K, class V>
void HashTable<K,V>::deleteEntry(K key){
    if (!currentSize){
        return;
    }
    int index = bucketIndex(key);
    LinkedListNode<HashTableEntry< K, V>*>* node = buckets[index]->getHead();
    while(node){
        K nodeKey = &(node->getData()->key);
        if (nodeKey == key){
            buckets[index]->removeNode(node);
            // if after removing the node the head is empty, the list is empty.
            // decrement the currentSize of the hashtable.
                // as a bucket has just been opened.
            if ( buckets[index]->getHead() == nullptr )
                currentSize--;
            resize();
            break;
        }
        node = node->getNext();
    }
    std::cout << "entry not found" << std::endl;
};
template<class K, class V>
void HashTable<K,V>::resize(){
    // i don't think i need to cast both to floats to get a float...
    int newSize;
    float loadSize = float(currentSize)/float(maxSize);
    LinkedList<HashTableEntry<K,V>*>* itemList = nullptr;
    
    if (loadSize < .25 || loadSize > .75)
        itemList = getListOfItems();
    else
        return;
    
    if (loadSize > .75){
        //double the size
        newSize = maxSize * 2;
    } else if (loadSize < .25) {
        // half the size
       newSize = maxSize / 2;
    }
    for (int i = 0; i < maxSize; i++ ){
        // a "starter" pointer to a series of linkedlist pointers
        // that contain nodes to hashTableEntry pointers that contain
        // fields of key and value pointers.
        // i definitely have some memory leaks.
        delete buckets[i];
    }
    maxSize = newSize;
    for (int i = 0; i < maxSize; i++ ){
        buckets[i] = new LinkedList<HashTableEntry<K, V>*>;
    }
    LinkedListNode<HashTableEntry<K,V>*>* node = itemList->getHead();
    
    while(node){
        K nodeKey = &(node->getData()->key);
        V nodeValue = &(node->getData()->value);
        set(nodeKey, nodeValue);
    }
};

