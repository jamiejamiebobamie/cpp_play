//
//  lambdaFunctions.cpp
//  cpp_play
//
//  Created by James McCrory on 5/8/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include <iostream>
#include "lambdaFunctions.hpp"
#include "helperFunctions.cpp"
#include<string>

//int main() {
//
//    auto myFirstLambda = [](){std::cout << "heyo" << std::endl;};
//
//    auto returnSmaller = [](int num1, int num2){
//        if(num1<num2)
//            return num1;
//        else
//            return num2;
//    };
//
//    auto returnLarger = [](int num1, int num2){
//        if(num1>num2)
//            return num1;
//        else
//            return num2;
//    };
//
//    int num1 = 10;
//    int num2 = 11;
//    int smallerNum = compare(returnLarger, num1, num2);
//    helpers::print(smallerNum);
//    // capture [] '&' and '=' pass all values into the lambda function by value: '=' or by reference: '&'
//
//    std::cout << &num1 << std::endl;
//    auto lambda1 = [=](){std::cout << &num1 << std::endl;};
//    lambda1();
//    auto lambda2 = [&](){std::cout << &num1 << std::endl;};
//    lambda2();
//
//    // creates a new type that is a pointer to a function
//    // the function returns an int and accepts no parameters.
//    typedef int(*myFunc1)();
//    myFunc1 newFunctionVar1 = testFunc1;
//    int two = newFunctionVar1();
//    helpers::print(two);
//
//    // creates a new type that is a pointer to a function
//    // the function returns nothing and accepts two ints.
//    typedef void(*myFunc2)(int,int);
//    myFunc2 newFunctionVar2 = testFunc2;
//    newFunctionVar2(3,4);
//
//    // ^^ how to create pointer variables to functions w/o lambda functions. ^^
//
//    //    typdef allows you to create an alias for a type name.
//    //    typedef int myNumNum;
//    using myNumNum = int; // < -- ALSO.
//    myNumNum one = 1;
//    myNumNum three = 3;
//
//    typedef char letter;
//    letter k = 'k';
//    letter o ='o';
//    helpers::print(k!=o);
//
//    auto anotherLambda = [two](){std::cout << two << std::endl;};
//    anotherLambda();
//
//    return 0;
//}

template<typename Func>
int compare(Func condition, int num1, int num2){
    return condition(num1,num2);
};

int testFunc1(){
    return 2;
};

void testFunc2(int num1, int num2){
    std::cout << "you passed in " << num1 << " and " << num2 << std::endl;
};
