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
 *         Author:youngthvg, 
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
	//std::unique_ptr<Node> newNode;
	//newNode->setCurrent(head);
	root = new Node(head); // set as the root.
}
//BTree::~BTree(){ delete root;} // garabge collected!
void BTree::setRoot(int head){ root->setCurrent(head);} // setting the root's value.
int BTree::getRootKey(){ return root->getCurrent();} // gets root value.
Node* BTree::getRoot(){ return root;} // returns root node.
void BTree::push(int key){
	push(key, root); // deualt starting point will be root.
}
void BTree::push(int key, Node* node){
	// inserts key into tree.
	// for now, we won't rotate, but a later
	// implementation might.
	if(key < node->getCurrent()){ // if key is less than current value of node.
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
		// key must be greater, if inside this else.
		if(node->hasRight()){ // check if there is room.
			// if not, keep traversing.
			push(key,node->getRight());
		}
		else{ // if there is space(no child of current node):
			Node* newNode = new Node(); // same procedure as above if statement.
			newNode->setCurrent(key);
			newNode->setParent(node);
			node->setRight(newNode);
		}
	}	
}
void BTree::preOrderTraverse(){ // default traversing method.
	preOrderTraverse(root); // root as starter.
}
void BTree::preOrderTraverse(Node* node){
	// we'll just print the keys in the tree.
	std::cout << node->getCurrent() << "\n"; // output current.
	if(node->hasLeft()) preOrderTraverse(node->getLeft());
	if(node->hasRight()) preOrderTraverse(node->getRight());

}

