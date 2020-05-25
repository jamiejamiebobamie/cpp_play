//
//  main.cpp
//  cpp_play
//
//  Created by James McCrory on 4/29/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include <iostream>
//#include "lambdaFunctions.cpp"
//#include "helperFunctions.cpp"
//#include<string>
#include "dataStructures/HashTable.cpp"

int main() {
    
//    HashTable(int maxSize);
//    const size_t hashKey(K key);
//    int bucketIndex(K key);
//    int loadFactor();
//    void printAllKeys();
//    void printAllValues();
//    LinkedList<HashTableEntry<K,V>*>* getListOfItems();
//    int length();
//    bool contains(K key);
//    V get(K key);
//    void set(K key, V value);
//    void deleteEntry(K key);
//    void resize();
    
    HashTable<int,char> ht = HashTable<int,char>(10);
    
    ht.set(3,'f');
    ht.set(13,'e');
    ht.set(2,'q');
    ht.set(12,'g');
    ht.set(22,'g');
    ht.set(5,'g');
    ht.set(7,'g');
    std::cout << ht.get(3) << std::endl;
    ht.set(3,'g');
    std::cout << ht.get(3) << std::endl;
    ht.deleteEntry(3);
    std::cout << ht.get(3) << std::endl;
    ht.deleteEntry(13);
    ht.deleteEntry(2);
    ht.deleteEntry(12);
    ht.deleteEntry(22);

    std::cout << ht.getCurrentSize() << std::endl;
    std::cout << ht.getMaxSize() << std::endl;
    std::cout << ht.loadFactor() << std::endl;
    
    return 0;
}
