/*
 * =====================================================================================
 *
 *       Filename:  BTree.h
 *
 *    Description:  Binary Tree implementation.
 *
 *        Version:  1.0
 *        Created:  01/03/2017 11:12:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  youngthvg,
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Node.h"
class Node;
class BTree{
	// interface for Binary Tree.
	private:
		Node* root; // root of the binary tree.
	public:
		BTree(); // default constructor
		BTree(int head); // constructor with root value parameter.
		~BTree(); // deconstructor.
		void setRoot(int head); // setter for root value.
		Node* getRoot(); // returns root of tree.
		void push(int key, Node* node); // adds node to the tree (w/o rotations).
		void push(int key); // defualt insert method.
		void preOrderTraverse(); // traverses preorder.
		void preOrderTraverse(Node* node); // start at node traverse.
		void inOrderTraverse(); // traverses in order.
		void postOrderTraverse(); // traverses in post order.
		void levelOrderTraverse(); // traverses in depth priority.
		Node* search(int key); // finds the key in the tree.
		void del(int key); // deletes key in tree.
};
