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
#include <iostream>

Node::Node() : current(1), left(nullptr), right(nullptr), parent(nullptr) {};
Node::Node(int c, Node* l, Node* r, Node* p) : current(c), left(l), right(r), parent(p) {};
Node::~Node(){
	std::cout << "left: " << hasLeft() << "\n";
	if(hasLeft()) delete left;
	std::cout << "right: " << hasRight() << "\n";
	if(hasRight()) delete right;
	std::cout << "parent: " << hasParent() << "\n";
	if(hasParent()) delete parent;
}
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
void Node::setParent(Node* p){ parent = p;}
Node* Node::getParent(){ return parent;}
bool Node::hasParent(){
	// checks if it has a parent.
	return (parent != nullptr);
}
// setters for private members.
void Node::setCurrent(int c){ current = c;}
void Node::setLeft(Node* l){ left = l;}
void Node::setRight(Node* r){ right = r;}

