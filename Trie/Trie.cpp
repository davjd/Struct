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
        for(; current->next[i] != nullptr; ++i){
            if(current->next[i]->letter == word[0]){
                return insert(word.substr(1), current->next[i]);
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
    print(root, root->next[0]->letter);
}
void Trie::print(Node* current, char parent){
    // prints all items in the trie.
    for(int i = 0; current->next[i] != nullptr; ++i){
        //std::cout << "i: " << i << std::endl;
        if(i > 0) std::cout << "parent: " << parent << std::endl;
        // deep search throught each valid letter.
        if(current->next[i]->letter != '\0'){
            std::cout << current->next[i]->letter << std::endl;
            // deep search.
            print(current->next[i], current->next[i]->letter);
        }
    } 
    std::cout << "word ended." << std::endl;
}
