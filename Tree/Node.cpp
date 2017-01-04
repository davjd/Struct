/*
 *
 * =====================================================================================
 *
 *       Filename:  Node.cpp
 *
 *    Description:  Implementation of the Node header file.
 *
 *        Version:  1.0
 *        Created:  01/03/2017 11:33:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  youngthvg, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Node.h"

Node::Node() : current(1), left(nullptr), right(nullptr) {};
Node::Node(int c, Node* l, Node* r) : current(c), left(l), right(r) {};
bool Node::hasChild(){
	// checks if there are any childs.
	return (hasLeft() || hasRight());
}
bool Node::hasLeft(){
	// checks if there is a left child.
	return left != nullptr;
}
bool Node::hasRight(){
	// checks if there is a right child
	return right != nullptr;
}
Node* Node::getLeft(){
	// returns the left node.
	return left;
}
Node* Node::getRight(){
	// returns the right node.
	return right;
}
int Node::getCurrent(){
	// returns values of current node.
	return current;
}
// setters for private members.
void Node::setCurrent(int c){ current = c;}
void Node::setLeft(Node* l){ left = l;}
void Node::setRight(Node* r){ right = r;}
