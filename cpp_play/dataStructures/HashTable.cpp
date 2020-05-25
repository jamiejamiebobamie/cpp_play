//
//  HashTable.cpp
//  cpp_play
//
//  Created by James McCrory on 5/21/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

//https://github.com/jamiejamiebobamie/CS-1.3-Core-Data-Structures/blob/master/Lessons/source/hashtable.py

#include <iostream>
#include "LL.cpp"

template<class K, class V>
struct HashTableEntry{
    K key;
    V value;
    int hashCode;
};

template<class K, class V>
class HashTable{
public:
    HashTable(int maxSize);
    const size_t hashKey(K key);
    int bucketIndex(K key);
    float loadFactor();
    void printAllKeys();
    void printAllValues();
    LinkedList<HashTableEntry<K,V>*>* getListOfItems();
    int length();
    bool contains(K key);
    V get(K key);
    void set(K key, V value);
    void _set(K key, V value);
    void deleteEntry(K key);
    void resize();
    int getCurrentSize()const;
    int getMaxSize()const;

private:
    int currentSize; // number of buckets with at least one entry in the linkedlist.
    int maxSize; // max number of buckets
    LinkedList<HashTableEntry<K, V>*>* buckets;
};
template<class K, class V>
HashTable<K,V>::HashTable(int maxSize): maxSize(maxSize), currentSize(0) {
    buckets = new LinkedList<HashTableEntry<K, V>*>[maxSize];
    for (int i = 0; i < maxSize; i++ ){
        buckets[i] = LinkedList<HashTableEntry<K, V>*>();
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
float HashTable<K,V>::loadFactor(){
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
            std::cout << node->getData()->key << std::endl;
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
            std::cout << node->getData()->value << std::endl;
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
    LinkedListNode<HashTableEntry<K, V>*>* node = buckets[index].getHead();
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
        return V();
    }
    int index = bucketIndex(key);
    LinkedListNode<HashTableEntry< K, V>*>* node = buckets[index].getHead();
    while(node){
        K nodeKey = node->getData()->key;
        if (nodeKey == key)
            return node->getData()->value;
        node = node->getNext();
    }
    return V();
};
template<class K, class V>
void HashTable<K,V>::set(K key, V value){
    HashTableEntry<K,V>* newEntry = new struct HashTableEntry<K,V>; // do i need the 'struct' keyword before the type declaration?
    newEntry->key = key;
    newEntry->value = value;
    newEntry->hashCode = hashKey(key);
    int index = bucketIndex(key);
    if (contains(key)){
        deleteEntry(key);
    }
//    LinkedListNode<HashTableEntry< K, V>*>* node = buckets[index].getHead();
//    while(node){
//        K nodeKey = node->getData()->key;
//        if (nodeKey == key){
//            buckets[index].removeNode(node);
//            break;
//        }
//        node = node->getNext();
//    }
//    // if the head is empty, the list is empty. increment the currentSize of the hashtable.
//        // as a new bucket has been filled.
    if ( buckets[index].getHead() == nullptr )
        currentSize++;
    buckets[index].append(newEntry);
    
    // for testing
//    std::cout << "setting " << key << std::endl;
//    std::cout << "current # of buckets with items " << getCurrentSize() << std::endl;
//    std::cout << "number of buckets " <<getMaxSize() << std::endl;
//    std::cout << "load factor " << loadFactor() << std::endl;
    
    resize();
};
template<class K, class V>
// internal set method triggered during a resize() that doesn't call resize()
void HashTable<K,V>::_set(K key, V value){
    HashTableEntry<K,V>* newEntry = new struct HashTableEntry<K,V>; // do i need the 'struct' keyword before the type declaration?
    newEntry->key = key;
    newEntry->value = value;
    newEntry->hashCode = hashKey(key);
    int index = bucketIndex(key);
    LinkedListNode<HashTableEntry< K, V>*>* node = buckets[index].getHead();
    while(node){
        K nodeKey = node->getData()->key;
        if (nodeKey == key){
            buckets[index].removeNode(node);
            break;
        }
        node = node->getNext();
    }
    // if the head is empty, the list is empty. increment the currentSize of the hashtable.
        // as a new bucket has been filled.
    if ( buckets[index].getHead() == nullptr )
        currentSize++;
    buckets[index].append(newEntry);
};
template<class K, class V>
void HashTable<K,V>::deleteEntry(K key){
    if (!currentSize){
        return;
    }
    int index = bucketIndex(key);
    LinkedListNode<HashTableEntry< K, V>*>* node = buckets[index].getHead();
    while(node){
        K nodeKey = node->getData()->key;
        if (nodeKey == key){
            buckets[index].removeNode(node);
            // if after removing the node the head is empty, the list is empty.
            // decrement the currentSize of the hashtable.
                // as a bucket has just been opened.
            if ( buckets[index].getHead() == nullptr )
                currentSize--;
            break;
        }
        node = node->getNext();
    }
    resize();
};
template<class K, class V>
void HashTable<K,V>::resize(){
    int newSize;
    float loadSize = loadFactor();
    LinkedList<HashTableEntry<K,V>*>* itemList = nullptr;
    if (loadSize <= .25 || loadSize >= .75){
//        std::cout << "resizing" << std::endl;
        itemList = getListOfItems();
    }
    else
        return;
    
    if (loadSize >= .75){
        //double the size
        newSize = maxSize * 2;
    } else if (loadSize <= .25) {
        // half the size
       newSize = maxSize / 2;
    }
    currentSize = 0;
    maxSize = newSize;
    // I definitely have memory leaks.
    buckets = new LinkedList<HashTableEntry<K, V>*>[maxSize];
    for (int i = 0; i < maxSize; i++ ){
        buckets[i] = LinkedList<HashTableEntry<K, V>*>();
    }
    LinkedListNode<HashTableEntry<K,V>*>* node = itemList->getHead();
    
    while(node){
        K nodeKey = node->getData()->key;
        V nodeValue = node->getData()->value;
        _set(nodeKey, nodeValue);
        node = node->getNext();
    }
};
template<class K, class V>
int HashTable<K,V>::getCurrentSize()const{
    return currentSize;
};
template<class K, class V>
int HashTable<K,V>::getMaxSize()const{
    return maxSize;
};

