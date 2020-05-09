//
//  codingProblem_findWordIn2DArray.cpp
//  cpp_play
//
//  Created by James McCrory on 5/7/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include "codingProblem_findWordIn2DArray.hpp"
#include<iostream>

/*
 https:leetcode.com/problems/word-search/
 
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 board =
 [
   ['A','B','C','E'],
   ['S','F','C','S'],
   ['A','D','E','E']
 ]

 Given word = "ABCCED", return true.
 Given word = "SEE", return true.
 Given word = "ABCB", return false.
 
 board and word consists only of lowercase and uppercase English letters.
 1 <= board.length <= 200
 1 <= board[i].length <= 200
 1 <= word.length <= 10^3
 
*/

struct charIndex{
    int rowIndex;
    int columnIndex;
};

//const char* word, int i
struct iterationRecord{
    const char* word;
    int index;
};


//const char* word, int i
struct endConditions{
    bool foundWord;
    bool arrayEnd;
};

struct charIndex* addNextCharToArrayAndReturnIndex(charIndex* );
iterationRecord* iterateOverWord(iterationRecord* );
void iterateWord(const char* word);

template<int numR, int numC>
void iterateOverArray(const char (&board)[numR][numC], const int numRow, const int numCol, char letter, endConditions* conditions);
//
//int main(){
//    
//    const int numRows = 3;
//    const int numColumns = 4;
//    
//    char board[numRows][numColumns] =
//    {
//        {'A','B','C','E'},
//        {'S','F','C','S'},
//        {'A','D','E','E'}
//    };
//    
//    const char* word1 = "ABCCED"; // true
//    const char* word2 = "SEE"; // true
//    const char* word3 = "ABCB"; // false
//    
////    Given a 2D board and a word,
////    find if the word exists in the grid.
//
////    The word can be constructed from
////    letters of sequentially adjacent
////    cell, where "adjacent" cells are
////    those horizontally or vertically
////    neighboring. The same letter cell
////    may not be used more than once.
//    
//    endConditions* conditions = new endConditions;
//    conditions->foundWord = false;
//    conditions->arrayEnd = false;
//    
//    iterationRecord* record = new iterationRecord;
//    record->word = word1;
//    record->index = 0;
//    
//    char letter = word1[0];
//    
//    bool foundLetter = false;
//    bool arrayEnd = false;
//
//    
//    while(!foundLetter && !arrayEnd){
//        while (letter != '\0'){
//            record = iterateOverWord(record);
//            letter = record->word[record->index];
//            iterateOverArray(board, numRows, numColumns, letter, conditions);
//            foundLetter = conditions->foundWord;
//            if(foundLetter)
//                break;
//            arrayEnd = conditions->arrayEnd;
//        }
//        record->word = word1;
//        record->index = 0;
//        letter = word1[0];
//    }
//    
//    std::cout << (foundLetter && !arrayEnd) << std::endl;
//};

//struct charIndex* addNextCharToArrayAndReturnIndex(charIndex* ){
//    struct charIndex* moveIndex = new charIndex;
//    moveIndex->rowIndex = 0;
//    moveIndex->columnIndex = 0;
//
//    return moveIndex;
//};

iterationRecord* iterateOverWord(iterationRecord* lastIteration){
    const char* word = lastIteration->word;
    const int currentIndex = lastIteration->index;
    const char* letter = &word[currentIndex];
    const int nextIndex = currentIndex + 1;
    
    std::cout << *letter << std::endl;
    
    iterationRecord* nextIteration = new iterationRecord;
    nextIteration->index = nextIndex;
    nextIteration->word = word;
    
    return nextIteration;
};

template<int numR, int numC>
void iterateOverArray(const char (&board)[numR][numC], const int numRow, const int numCol, char letter, endConditions* conditions){
    static int indexRow = 0;
    static int indexColumn = -1;
    indexColumn++;
    if (indexColumn > numCol){
        indexColumn = 0;
        indexRow++;
    }
    if (indexRow > numRow)
        conditions->arrayEnd = true;
    
//    text fourDirectionsAroundCurrIndexForLetter;
    
    std::cout << indexRow << indexColumn << std::endl;

}

//recursive function needs to test for 4 directions for the next desired letter,
//(make sure to test that the index for row / col are in range)
//(need to ensure that board indices are added to an array and not repeated)
//if it is there, recurse on that board space, test next desired letter (increment index into word)
//return true if null character has been reached or false if above conditions are not met.
void fourDirectionsAroundCurrIndexForLetter(const int numRow, const int numCol, endConditions* conditions){
    
    // take in a reference to a 2d board, const int numRow, const int numCol, endConditions* conditions
    //
    
}
