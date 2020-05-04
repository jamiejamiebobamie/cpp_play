//
//  codingProblem_tripleStep.cpp
//  cpp_play
//
//  Created by James McCrory on 5/3/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include <stdio.h>
#include "./cpp_play/helperFunctions.cpp"
#include<list>
/*
    # Triple Step: A child is running up a staircase with n steps
    # and can hop either 1 step, 2 steps, or 3 steps at a time.
    # Implement a method to count how many possible ways the child can run up the
    # stairs.
    # Example
    # Input : 3
    # [1, 1, 1], [1, 2], [3]
    # Output: 3
 
    # Input: 4
    # [1,1,1,1], [1, 1, 2], [1, 2, 1], [2, 2], [1, 3]
    # Output: 5
 
*/

int countSteps(int numSteps);
int recurSteps(int numSteps, bool first);

//int main(){
////    helpers::print(countSteps(0));
////    helpers::print(countSteps(1));
////    helpers::print(countSteps(2));
//    helpers::print(countSteps(3));
//    helpers::print(countSteps(4));
////    helpers::print(countSteps(5));
////    helpers::print(countSteps(6));
//
//    return 0;
//}


int countSteps(int numSteps){
    int count = recurSteps(numSteps, true);
    return count;
};

int recurSteps(int numSteps, bool first){
    if ((numSteps == 0 || numSteps == 1) and !first){
        return 1;
    }
    else if (numSteps < 0 || (numSteps == 0 and first))
        return 0;
    else
        return recurSteps(numSteps - 1, false) + recurSteps(numSteps - 2, false) + recurSteps(numSteps - 3, false);
    return numSteps;
};
