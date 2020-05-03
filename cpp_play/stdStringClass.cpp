//
//  stdStringClass.cpp
//  cpp_play
//
//  Created by James McCrory on 4/30/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include "stdStringClass.hpp"
#include<iostream>
#include "helperFunctions.cpp"

int main(){
    std::string myString = "hello";
    helpers::print(myString);
    std::string* reversedWord = reverse(myString);
    helpers::print(*reversedWord);
    reverse(reversedWord);
    helpers::print(*reversedWord);
    return 0;
}

std::string* reverse(std::string word){
    std::string* newString = new std::string("");
    for (int i = word.length()-1; i < word.length(); i--){
        *newString += word[i];
    }
    return newString;
}

void reverse(std::string* word){
//    std::string* newString = new std::string("");
    int i = 0;
    int j = (*word).length();
    helpers::print(j);
    while (i < j){
//        std::string lower = (*(*word)+i);
////        std::string upper = word[j];
        std::string maybeAString = (std::string)(*(word+i));
        helpers::print(maybeAString);
//        helpers::print(lower);

//        word[i] = upper;
//        word[j] = lower;
        i++;
        j--;
    }
}
