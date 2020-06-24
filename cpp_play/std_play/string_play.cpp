//
//  string_play.cpp
//  cpp_play
//
//  Created by James McCrory on 6/23/20.
//  Copyright © 2020 James McCrory. All rights reserved.
//

#include <stdio.h>
#include "../helperFunctions.cpp"
#include <string>
#include <iterator>

//class TestString {
//public:
//    void _test();
//};
//void TestString::_test(){
//    std::string new_string = std::string("this is a new string");
//}

int main (){
    
    //begin
    //Return iterator to beginning (public member function )
    // intialize a new string.
    //end
    //Return iterator to end (public member function )
    std::string str1 ("Test string");
    for ( std::string::iterator it=str1.begin(); it!=str1.end(); ++it)
    {
        std::cout << *it;
        std::cout << " ";
    }
    std::cout << '\n';
    // testing for empty strings
    std::string str2 ("");
    bool equal = str2.begin() == str2.end();
    std::cout << equal << std::endl;
    
    //rbegin
    //Return reverse iterator to reverse beginning (public member function )
    //rend
    //Return reverse iterator to reverse end (public member function )
    std::string str3 ("hello");
    for (std::string::reverse_iterator rit=str3.rbegin(); rit!=str3.rend(); ++rit)
      std::cout << *rit;
    std::cout << '\n';
    
    //cbegin
    //Return const_iterator to beginning (public member function )
    //cend
    //Return const_iterator to end (public member function )
    //crbegin
    //Return const_reverse_iterator to reverse beginning (public member function )
    //crend
    //Return const_reverse_iterator to reverse end (public member function )
    std::string str4 ("Lorem ipsum");
    for (auto it=str4.cbegin(); it!=str4.cend(); ++it)
      std::cout << *it;
    std::cout << '\n';
    
    //size
    //Return length of string (public member function )
    //length
    //Return length of string (public member function )
    std::cout << (str4.size() == str4.length()) << std::endl;
    std::cout << str4.size() << std::endl;
    
    //max_size
    //Return maximum size [possible] of string (public member function )
     std::cout << str4.max_size() << std::endl;
    
    //resize
    //Resize string (public member function )
//    void resize (size_t n);
//    void resize (size_t n, char c);
    str4.resize(3);
    std::cout << str4 << std::endl;
    str4.resize(5,'h');
    std::cout << str4 << std::endl;
    
    //capacity
    //Return size of allocated storage (public member function )
    std::cout << str4.capacity() << std::endl;
    
    //reserve
    //Request a change in capacity (public member function )
    str4.reserve(25);
    std::cout << str4.capacity() << std::endl;
    
    //empty
    //Test if string is empty (public member function )
    std::cout << str4.empty() << std::endl;
    
    //clear
    //Clear string (public member function )
    str4.clear();
    std::cout << str4 << " hola" << std::endl;
    std::cout << str4.empty() << std::endl;
    
    std::cout << str3.capacity() << std::endl;
    str3.reserve(50);
    std::cout << str3.capacity() << std::endl;
    //shrink_to_fit
    //Shrink to fit (public member function )
    str3.shrink_to_fit();
    std::cout << str3.capacity() << std::endl;


    std::string str5 ("hello there");
    //operator[]
    //Get character of string (public member function )
    std::cout << str5[0] << std::endl;
    str5[0] = 'p'; // can do assignment.
    std::cout << str5[0] << std::endl;
    //at
    //Get character in string (public member function )
    std::cout << str5.at(0) << std::endl;
    str5.at(0) = 'h';// can do assignment.
    std::cout << str5.at(0) << std::endl;
    //back
    //Access last character (public member function )
    str5.back() = 's';// can do assignment.
    std::cout << str5 << std::endl;
    //front
    //Access first character (public member function )
    str5.front() = 's';// can do assignment.
    std::cout << str5 << std::endl;
    str5 = "hello there";
    std::cout << str5 << std::endl;
    //operator+=
    //Append to string (public member function )
    str5 += "hello there";
    std::cout << str5 << std::endl;
    //append
    //Append to string (public member function )
//    (1) string
//    Appends a copy of str.
//    (2) substring
//    Appends a copy of a substring of str. The substring is the portion of str that begins at the character position subpos and spans sublen characters (or until the end of str, if either str is too short or if sublen is string::npos).
//    (3) c-string
//    Appends a copy of the string formed by the null-terminated character sequence (C-string) pointed by s.
//    (4) buffer
//    Appends a copy of the first n characters in the array of characters pointed by s.
//    (5) fill
//    Appends n consecutive copies of character c.
//    (6) range
//    Appends a copy of the sequence of characters in the range [first,last), in the same order.
//    (7) initializer list
//    Appends a copy of each of the characters in il, in the same order.
    str5.append("hello there");
    std::cout << str5 << std::endl;
    //push_back
    //Append character to string (public member function )
    str5.push_back('k');
    std::cout << str5 << std::endl;
    //assign
    //Assign content to string (public member function )
    str5.assign("what");
    std::cout << str5 << std::endl;
    //insert
    //Insert into string (public member function )
//    (1) string
//    Inserts a copy of str.
//    (2) substring
//    Inserts a copy of a substring of str. The substring is the portion of str that begins at the character position subpos and spans sublen characters (or until the end of str, if either str is too short or if sublen is npos).
//    (3) c-string
//    Inserts a copy of the string formed by the null-terminated character sequence (C-string) pointed by s.
//    (4) buffer
//    Inserts a copy of the first n characters in the array of characters pointed by s.
//    (5) fill
//    Inserts n consecutive copies of character c.
//    (6) single character
//    Inserts character c.
//    (7) range
//    Inserts a copy of the sequence of characters in the range [first,last), in the same order.
//    (8) initializer list
//    Inserts a copy of each of the characters in il, in the same order.
    str1.insert(6,str2);
    str1.insert(6,str3,3,4);
    str1.insert(10,"that is cool",8);
    str1.insert(10,"to be ");
    str1.insert(15,1,':');
    std::cout << str1 << std::endl;
    //erase
    //Erase characters from string (public member function )
//    (1) sequence
//    Erases the portion of the string value that begins at the character position pos and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.
//    Notice that the default argument erases all characters in the string (like member function clear).
//    (2) character
//    Erases the character pointed by p.
//    (3) range
//    Erases the sequence of characters in the range [first,last).
    str1.erase(0,1);
    std::cout << str1 << " hello"<< std::endl;

    return 0;
}

//replace
//Replace portion of string (public member function )
//swap
//Swap string values (public member function )
//pop_back
//Delete last character (public member function )
//
//String operations:
//c_str
//Get C string equivalent (public member function )
//data
//Get string data (public member function )
//get_allocator
//Get allocator (public member function )
//copy
//Copy sequence of characters from string (public member function )
//find
//Find content in string (public member function )
//rfind
//Find last occurrence of content in string (public member function )
//find_first_of
//Find character in string (public member function )
//find_last_of
//Find character in string from the end (public member function )
//find_first_not_of
//Find absence of character in string (public member function )
//find_last_not_of
//Find non-matching character in string from the end (public member function )
//substr
//Generate substring (public member function )
//compare
//Compare strings (public member function )
//
//Member constants
//npos
//Maximum value for size_t (public static member constant )
//
//Non-member function overloads
//operator+
//Concatenate strings (function )
//relational operators
//Relational operators for string (function )
//swap
//Exchanges the values of two strings (function )
//operator>>
//Extract string from stream (function )
//operator<<
//Insert string into stream (function )
//getline
//Get line from stream into string (function )
