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



class Trie{
    public:
        struct Node{
            char character; // current character.
            Node* next; // next letter after this character.
        }
        void Trie();
        void Trie(std::string word);
        void insert(std::string word);
        void remove(std::string word);
        T pop(std::string word);
    private:
        Node *root;
}
