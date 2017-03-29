/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/07/2017 11:58:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David M., 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include "Trie.h"

int main(){

    std::cout << "+++++COMPILED+++++" << std::endl;

    Trie t;
    t.insert("hello");
    t.insert("trie");
    t.insert("hi"); 
    t.insert("hey");

    std::cout << "------print chars-------" << std::endl;
    t.print();

    std::cout << "-------print words------" << std::endl;
    t.printWords();

    std::cout << "-----COMPLETE----" << std::endl;
    return 0;
}
