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
    const char word[] = "Cherno";
    const int size = sizeof(word)/sizeof(char);
    const char* newWord = garble(word,size);
    print(newWord);
    delete newWord;

    const char* newestWord = reverse(word);
    print(newestWord);
    delete newestWord;
    
    const char* s = "Cherno";
    const char* fisherYates = garble(s);
    print(fisherYates);
    delete fisherYates;
    
    const char* source = ":)";
    char destination[] = "i like pens";
    copy(destination,source);
    print(destination);
    
//    std::cin.get();
   return 0;
}

const char* garble(const char* inputString, const int wordLength){
    // garbles the word without maintaining the same frequency of characters
    char* newWord = new char[wordLength];
    int count = 0;
    srand(time(NULL));
    while(count < wordLength){
        int index = rand() % (wordLength-1);
        newWord[count] = inputString[index];
        count++;
    }
    newWord[wordLength-1] = 0;
    return newWord;
}

const char* garble(const char* inputString){
    // fisher-yates shuffle
    const int wordLength = strlen(inputString);
    char* newWord = new char[wordLength];
    newWord = strcpy(newWord, inputString);
    int count = wordLength - 1;
    srand(time(NULL));
    int randomIndex;
    while(count){
        randomIndex = rand() % count;
        char temp = newWord[count];
        newWord[count] = newWord[randomIndex];
        newWord[randomIndex] = temp;
        count--;
    }
    return newWord;
}

const char* reverse(const char* inputString){
    // reverses the word.
    const int len = strlen(inputString);
    int index = len - 1;
    char* returnString = new char[len];
    while(index > -1){
        returnString[index] = inputString[len - index - 1];
        index--;
    };
    return returnString;
}

const char* copy(char destination[], const char* source){
    int i = 0;
    while(destination[i] && source[i]){
        destination[i] = source[i];
        i++;
    }
    destination[i] = 0;
    return destination;
}

template<class T>
void print(T item){
    std::cout << item << std::endl;
}
