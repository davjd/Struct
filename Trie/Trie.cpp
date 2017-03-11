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

Trie::Trie(){
    root = nullptr;
}

Trie::Trie(T word){
    root = nullptr;
}

void Trie::insert(std::string  word, Node* current){
    if(word.length() == 0){
        return;
    }
    else if(current->letter == word[0]){
        return insert(word.substr(1), current);
    }
}
