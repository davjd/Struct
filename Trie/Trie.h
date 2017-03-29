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
            bool end; // wether its final letter of word.
            Node *next[26]; // possible letters after this character.
            Node(char l){
                end = false;
                letter = l;
                for(int i = 0; i < 26; ++i){
                    next[i] = nullptr;
                }
            }
            Node(){
                end = false;
                letter = '\0';
                for(int i = 0; i < 26; ++i){
                    next[i] == nullptr;
                }
            }
        };
        Trie();
        Trie(std::string word);
        void insert(std::string word);
        void remove(std::string word);
        std::string pop(std::string word);
        void print();
        void printWords();
    private:
        Node *root;
        void printWords(Node *current, std::string word);
        void print(Node* current);
        void insert(std::string word, Node* current);
};
