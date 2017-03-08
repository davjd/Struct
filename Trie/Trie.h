/*
 * =====================================================================================
 *
 *       Filename:  Trie.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/08/2017 12:01:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David M, 
 *   Organization:  
 *
 * =====================================================================================
 */

template <class T>
class Trie{
    public:
        struct Node{
            T character; // current character.
            T* next; // next letter after this character.
        }
        void Trie();
        void Trie(T word);
        void add(T word);
        void remove(T word);
        T pop(T word);
    private:
        Node *alphabet;
}
