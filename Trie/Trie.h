/*
 * =====================================================================================
 *
 *       Filename:  Trie.h
 *
 *    Description:  Trie header.
 *
 *        Version:  1.0
 *        Created:  03/08/2017 12:01:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David M, 
 *   Organization:  
 *
 *
 *  The name trie comes from its use for retrieval.
 *
 * =====================================================================================
 */

#include <string>


class Trie{
    public:
        struct Node{
            char letter; // current character.
            Node *next[26]; // possible letters after this character.
            Node(char l){
                letter = l;
                for(int i = 0; i < 26; ++i){
                    next[i] = nullptr;
                }
            }
            Node(){
                letter = '\0';
                for(int i = 0; i < 26; ++i){
                    next[i] == nullptr;
                }
            }
        };
        Trie();
        Trie(std::string word);
        void insert(std::string word);
        void insert(std::string word, Node* current);
        void remove(std::string word);
        std::string pop(std::string word);
        void print();
    private:
        Node *root;
};
