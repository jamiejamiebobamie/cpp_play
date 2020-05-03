//
//  helperFunctions.cpp
//  cpp_play
//
//  Created by James McCrory on 4/30/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include "helperFunctions.hpp"
#include <iostream>

namespace helpers{
    template<class T>
    void print(T item){
        std::cout << item << std::endl;
    }
}
