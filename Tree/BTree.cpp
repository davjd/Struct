/*
 * =====================================================================================
 *
 *       Filename:  BTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/04/2017 10:41:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once
#include <iostream>
#include "BTree.h"
#include "Node.h"
class Node;
BTree::BTree() : root(nullptr) {}; // default btree constructor.
BTree::BTree(int head){
	root = new Node(head); // set as the root.
}
BTree::~BTree(){ delete root;} // garabge collected!
void BTree::setRoot(int head){ root->setCurrent(head);} // setting the root's value.
Node* BTree::getRoot(){ return root;} // returns root node.
void BTree::push(int key){
	push(key, root); // deualt starting point will be root.
}
void BTree::push(int key, Node* node){
	// inserts key into tree.
	// for now, we won't rotate, but a later
	// implementation might.
	if(key < node->getCurrent()){ // if key is less than current value of node.
		std::cout << "key is less than " << node->getCurrent() << "\n";
		if(node->hasLeft()){ // if there is child already on the left:
			// we'll need to keep traversing, until there is an empty spot.
			push(key, node->getLeft()); // keep traversing.
		}	
		else{ // if no child exists there, we'll add it to the tree.
			Node* newNode = new Node(); // create the new node.
			newNode->setCurrent(key); // set value.
			newNode->setParent(node); // give the new node it's parent.
			node->setLeft(newNode); // add the new node, as the left child of the current node.
		}
	}
	else{
		std::cout << "key is greater than " << node->getCurrent() << "\n";
		// key must be greater, if inside this else.
		if(node->hasRight()){ // check if there is room.
			// if not, keep traversing.
			std::cout << "There is a child\n";
			push(key,node->getRight());
		}
		else{ // if there is space(no child of current node):
			std::cout << "There is no child\n";
			Node* newNode = new Node(); // same procedure as above if statement.
			newNode->setCurrent(key);
			newNode->setParent(node);
			node->setLeft(newNode);
		}
	}	
}
void BTree::preOrderTraverse(){ // default traversing method.
	preOrderTraverse(root); // root as starter.
}
void BTree::preOrderTraverse(Node* node){
	// we'll just print the keys in the tree.
	if(!node->hasChild()) std::cout << node->getCurrent() << "\n"; // base case: current node has no children.
	else{
		if(node->hasLeft()) preOrderTraverse(node->getLeft()); // theres more we have to traverse -> left.
		if(node->hasRight()) preOrderTraverse(node->getRight()); // theres more we have to traverse -> right.
	}
}

