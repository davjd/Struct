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
#include "BTree.h"
BTree::BTree() : root(nullptr) {}; // default btree constructor.
BTree::BTree(int head){
	Node* r = new Node(); // create new node.
	r->setCurrent(head); // set value.
	root = r; // set as the root.
	delete r; // delete garbage.
}
void BTree::push(int key, Node* node = root){
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
			delete newNode; // delete garbage.
		}
	}
	else{

	}	
}

