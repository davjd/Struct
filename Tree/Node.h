/*
 * =====================================================================================
 *
 *       Filename:  Node.h
 *
 *    Description:  Class for Node.
 *
 *        Version:  1.0
 *        Created:  01/03/2017 11:23:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  youngthvg, 
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once
class Node{
	// class for node, for now it'll only be for integers.
	// maybe i'll implement with templates later.
	// will be used for tree.
	private:
		Node *left; // pointer to the left node.
		Node *right; // pointer to the right node.
		Node *parent;
		int current; // holder for current node.
	public:
		Node(); // diffault constructor.
		Node(int c, Node *l = nullptr, Node *r = nullptr, Node* p = nullptr); // constructor for node
		//~Node(); // destructor.
		bool hasChild(); // will check if node has a child.
		bool hasParent(); // will check if it's a child.
		bool hasLeft(); // will check if node has left child.
		bool hasRight(); // will check if node has a right child.
		Node* getLeft(); // will return left child.
		Node* getRight(); // will return right child.
		int getCurrent(); // return value of current node.
		Node* getParent(); // returns the parent of current node.
		void setCurrent(int c); // setter for current value.
		void setLeft(Node* l); // setter for left node.
		void setRight(Node* r); // setter for right node.
		void setParent(Node* p); // setter for parent of node.
};
