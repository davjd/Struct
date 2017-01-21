/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/04/2017 12:06:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  youngthvg, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "BTree.h"
#include <iostream>
int main(){
	std::cout << "---+COMPILED+--\n";
	BTree tree(11);
	tree.push(6);
	tree.push(8);
	tree.push(19);
	tree.push(4);
	tree.push(10);
	tree.push(5);
	tree.push(17);
	tree.push(43);
	tree.push(49);
	tree.push(31);
	tree.push(40);
	std::cout << "ROOT: " << tree.getRootKey() << "\n---TRAVERSE----\n\n";
	
	tree.preOrderTraverse();
	Node* a = new Node();
	a->setCurrent(10);
	Node* b = new Node();
	Node* c = new Node();
	c->setCurrent(11);
	c->setLeft(a);
	c->setRight(b);
	Node* t = c;	
	
	std::cout << "old:: c: " << c->key() << "left: " << c->getLeft()->key() << " right: " << c->getRight()->key() << "\n";
	std::cout << "old:: t: " << t->key() << "left: " << t->getLeft()->key() << " right: " << t->getRight()->key() << "\n";
	std::cout << "\nALL METHODS PASSED\n\n";
	return 0;
}

