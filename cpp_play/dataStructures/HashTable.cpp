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
    int length();
    bool contains(K key);
    V get(K key);
    void set(K key, V value);
    void deleteEntry(K key);
    void resize();
private:
    // !!!...not implemented...!!!
    int currentSize; // number of buckets with at least one entry.
    int maxSize; // max number of buckets
    LinkedList<HashTableEntry<K, V>*>* buckets[];
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
    struct HashTableEntry<K,V>* newEntry = new struct HashTableEntry<K,V>;
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
            resize();
            break;
        }
        node = node->getNext();
    }
    std::cout << "entry not found" << std::endl;
};
// IN PROGRESS...
template<class K, class V>
void HashTable<K,V>::resize(){
    // i don't think i need to cast both to floats to get a float...
    float loadSize = float(currentSize)/float(maxSize);
    if (loadSize > .75){
        
    } else if (loadSize < .25) {
        
    }
    
//    .75
//    if new_size is None:
//        new_size = len(self.buckets) * 2  # Double size
//    # Option to reduce size if buckets are sparsely filled (low load factor)
//    elif new_size is 0:
//        new_size = len(self.buckets) / 2  # Half size
//
//    temp_items = self.items()
//
//    self.buckets = [LinkedList() for i in range(new_size)]
//    for key, value in temp_items:
//        self.buckets[self._bucket_index(key)].append((key,value))
    
    
};
