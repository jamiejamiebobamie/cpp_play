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

int main() {

    std::hash<const char*> h;
    const char* hi = "hello";
    const char* bye = "bubye";

    const size_t value1 = h(hi);
    const size_t value2 = h(bye);
    std::cout << value1 << " " << value2 << std::endl;
    
    return 0;
}
