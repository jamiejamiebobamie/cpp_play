//
//  pointers.cpp
//  cpp_play
//
//  Created by James McCrory on 5/2/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include "pointers.hpp"
#include<string>
#include"helperFunctions.cpp"
#include <iostream>
#include<random>

//int main(){
//    
//    std::string first = "hey";
//    std::string second = "bye";
//    helpers::print(first);
//    helpers::print(second);
//    swap(first, second);
//    helpers::print(first);
//    helpers::print(second);
//    
//    int f = 1;
//    int s = 2;
//    helpers::print(f);
//    helpers::print(s);
//    swap(f, s);
//    helpers::print(f);
//    helpers::print(s);
//    
//    int* ad = &f;
//    
//    randomAddress(ad);
//    
//    return 0;
//}

template<class T>
void swap(T &first, T &second){
    T temp = first;
    first = second;
    second = temp;
}

// ignore
template<class T>
void randomAddress(T *address){
    srandom(time(NULL));
    unsigned long int rand = random() % 2147483647L;
    helpers::print(rand);
//    address;
}
