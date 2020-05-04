//
//  stdStringClass.cpp
//  cpp_play
//
//  Created by James McCrory on 4/30/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include "stdStringClass.hpp"
#include<iostream>
#include<string_view>
#include "helperFunctions.cpp"

//int main(){
//    std::string myString = "hello";
//    helpers::print(1);
//    helpers::print(myString);
//    std::string* reversedWord = reverse(myString);
//    helpers::print(2);
//    helpers::print(*reversedWord);
//    reverse(reversedWord);
//    helpers::print(3);
//    helpers::print(*reversedWord);
//    return 0;
//}

void reverse(std::string* word){
    int i = 0;
    int j = (*word).length()-1;
    
    while (i < j){
        std::swap(word[i], word[j]);
        i++;
        j--;
    }
}


std::string* reverse(std::string word){
    std::string* newString = new std::string("");
    for (int i = word.length()-1; i < word.length(); i--){
        *newString += word[i];
    }
    return newString;
}
