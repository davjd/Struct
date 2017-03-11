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
void hello(int i){
    if(i == 0) return;
    else{
        for(int j = 0; j <= i; ++j){
            std::cout << "i: " << i << ", j: " << j << std::endl;
            if(i == j){
                return hello(i - 1);
                std::cout << "call after return." << std::endl;
            }
        }
    }
}

int main(){


    Trie t;
    t.insert("hello");
    return 0;
}
