//
//  c_string.cpp
//  cpp_play
//
//  Created by James McCrory on 4/29/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//
#include <iostream>
#include <time.h>
#include <random>
#include <cstring>
#include "c_string.hpp"

int main(){
    const char* s = "Cherno";
    const char* nope = garble(s);
    const int wordLength = 6;
    const std::string t = "test";
    const char word[] = "Cherno";
    const int size = sizeof(word)/sizeof(char);
    const char* newerWord = garble(word,size);
    std::string nw = (std::string)newerWord;
    std::cout << nw << std::endl;

    const char* newestWord = reverse(word);
    std::string nsw = (std::string)newestWord;
    std::cout << nsw << std::endl;
    
//    std::cin.get();
   return 0;
}


const char* garble(const char* inputString, const int wordLength){
    // iterate through the string and choose random indices to swap
    char* newWord = new char[wordLength-1];
    int count = 0;
    srand(time(NULL));
    while(count < wordLength){
        int index = rand() % (wordLength-1);
        newWord[count] = inputString[index];
        count++;
    }
    return newWord;
}

const char* garble(const char* inputString){
    // implementing fisher-yates shuffle
    int wordLength = strlen(inputString)-1;
    char* returnString = new char[wordLength];
    srand(time(NULL));
    while(wordLength){
        int index = rand() % wordLength;
        std::cout << wordLength << index << std::endl;
        returnString[5-wordLength] = inputString[index];
        wordLength--;

    }
    return returnString;
}

const char* reverse(const char* inputString){
    int wordLength = strlen(inputString);
    const int len = wordLength-1;
    char* returnString = new char[len];
    while(wordLength > -1){
        returnString[5-wordLength] = inputString[wordLength];
        wordLength--;
    };
    return returnString;
}
