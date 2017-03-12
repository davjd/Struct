/*
 * =====================================================================================
 *
 *       Filename:  Trie.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/10/2017 12:35:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David M, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Trie.h"
#include <iostream>


Trie::Trie(){
    root = new Node();
}

Trie::Trie(std::string word){
    root = new Node();
    insert(word, root);
}

void Trie::insert(std::string  word, Node* current){
    if(word.length() == 0){
        return;
    }
    else{
        int i = 0;
        std::cout << "i: 0: " << i << std::endl;
        for(; current->next[i] != nullptr; ++i){
            std::cout << "i: " << i << std::endl;
            if(current->next[i]->letter == word[0]){
                return insert(word.substr(1), current->next[i]);
                std::cout << "hello !" << std::endl;
                break;
            } 
        }
        // if the letter wasnt't found, add a new node,
        // with the next letter of the word.
        current->next[i] = new Node(word[0]);

        // continue adding the rest of the letters.
        insert(word.substr(1), current->next[i]);
    }
}
void Trie::insert(std::string word){
    insert(word, root);
}
void Trie::print(){
    // prints all items in the dictionary.
}
