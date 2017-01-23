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
BTree::~BTree(){
	// to delete grabage, we need to delete all nodes
	// meaning, all children and parents, not just the root.
	std::cout << "BINARY DESTRUCTOR\n";
	if(root->hasLeft()){
		delete root->getLeft();
		root->setLeft(nullptr);
	}
	if(root->getRight()){
		delete root->getRight();
		root->setRight(nullptr);
	}
	if(root != nullptr){
		delete root;
		root = nullptr;
	}
	std::cout << "DECOSTRUCTOR DONE\n";
} // garabge collected!
void BTree::setRoot(int head){ 
	if(root != nullptr) delete root;
	root->setCurrent(head);
} // setting the root's value.
int BTree::getRootKey(){ return root->key();} // gets root value.
Node* BTree::getRoot(){ return root;} // returns root node.
void BTree::push(int k){
	push(k, root); // deualt starting point will be root.
}
void BTree::push(int k, Node* node){
	// inserts key into tree.
	// for now, we won't rotate, but a later
	// implementation might.
	if(k < node->key()){ // if key is less than current value of node.
		if(node->hasLeft()){ // if there is child already on the left:
			// we'll need to keep traversing, until there is an empty spot.
			push(k, node->getLeft()); // keep traversing.
		}	
		else{ // if no child exists there, we'll add it to the tree.
			Node* newNode = new Node(); // create the new node.
			newNode->setCurrent(k); // set value.
			//newNode->setParent(node); // give the new node it's parent.
			node->setLeft(newNode); // add the new node, as the left child of the current node.
		}
	}
	else{
		// key must be greater, if inside this else.
		if(node->hasRight()){ // check if there is room.
			// if not, keep traversing.
			push(k,node->getRight());
		}
		else{ // if there is space(no child of current node):
			Node* newNode = new Node(); // same procedure as above if statement.
			newNode->setCurrent(k);
			//newNode->setParent(node);
			node->setRight(newNode);
		}
	}	
}
void BTree::preOrderTraverse(){ // default traversing method.
	preOrderTraverse(root); // root as starter.
}
void BTree::preOrderTraverse(Node* node){
	// we'll just print the keys in the tree.
	std::cout << node->key() << "\n"; // output current.
	if(node->hasLeft()) preOrderTraverse(node->getLeft());
	if(node->hasRight()) preOrderTraverse(node->getRight());

}
Node* BTree::find(int k, Node* node){
	if(k == node->key()) return node; // found key.
	else if(k < node->key() && node->hasLeft()){ // check if the key is on the left side.
		return find(k, node->getLeft());
	}
	else if(k > node->key() && node->getRight()){
		return find(k, node->getRight());
	}
	else return nullptr; // not found.
}
Node* BTree::find(int k){ 
	return find(k, root);
} // start search.
Node* BTree::maxChild(Node* node){ // finds largest child of node.
	if(!node->hasRight()) return node; // if no more larger children, return node.
	else return maxChild(node->getRight()); // if there's larger children.
}
void BTree::del(int k, Node* node){
	/* 
	 * CASES:
	 * 	a) key is not in tree.
	 * 	b) key is a leaf (no children).
	 * 	c) key node has one child.
	 * 	d) key node has two children.
	 *
	 * 	a - exit function.
	 * 	b - just delete the key node from the parent.
	 * 	c - replace the the parent node's child with the current
	 * 		node's child, then delete the current node as if it were
	 * 		a leaf.
	 * 	d - get the largest key smaller than the current key.
	 * 		we do this, by traversing through the current key's
	 * 		right subtrees. Replace that key with the key to be deleted. 
	 *
	 *
	 * */
	// first find the key in the tree.
   	if(key == node->getCurrent()){ // found key.
		
   	}
   	else if(key < node->getCurrent() && node->hasLeft()){ // we need to go to the left.
      		if(node->getLeft() == node){ // the child on left is the key to be deleted.
         		if(node->getLeft()->hasLeft() && node->getLeft()->hasRight()){ // CASE D (two children). 
		
        		 }
         		else if(node->getLeft()->hasChildren()){ // CASE C(one child -(left child)-)
            			// point the key node's parent child to key node's only child.
            			node->setLeft(node->getLeft()->child()); // replace key node's position with key node's child.
            			resetChildren(node->getLeft()); // set key node's child to null before deleting it.
            			delete node->getLeft(); // delete garbage.         
         		}
         		else{ // CASE B(No children)
            			// just delete key node from it's parent.
            			delete node->getLeft(); // delete key node.
            			node->setLeft(nullptr); // reset the pointer.
         		}
      		}
      		else{

      		}
   	}
   	else if(key > node->getCurrent() && node->hasRight()){ // we need to go the right.
      		if(node->getRight() == node){

      		}
      		else{

      		}
   	}
   	else return; // key not found, just exit.
}






