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
        // if end of letter:
        // set the end to true.
        current->end = true;
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
    print(root);
}

void Trie::printWords(){
    printWords(root, "");
}
void Trie::printWords(Node* current, std::string word){
    // prints all words in the trie.
    for(int i = 0; current->next[i] != nullptr; ++i){
        if(current->next[i]->end) { 
            std::cout << word << current->next[i]->letter 
                << std::endl;
        }
        
        /*  There might be times when a complete word
         *  is a prefix of another.
         *   ex. try and trying.
         *  So we need to keep traversing through the trie
         *  until we find the last child node.
         * */

        if(current->next[i]->letter != '\0'){
            // deep search.
            printWords(current->next[i], (word + current->next[i]->letter));
        }
    } 
}

void Trie::print(Node* current){
    // prints all characters in the trie.
    for(int i = 0; current->next[i] != nullptr; ++i){
        // deep search throught each valid letter.
        if(current->next[i]->letter != '\0'){
            std::cout << current->next[i]->letter << std::endl;
            // deep search.
            print(current->next[i]);
        }
    } 
}
