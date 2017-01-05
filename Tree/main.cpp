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
#include "Node.h"
#include <iostream>
int main(){
	std::cout << "---+COMPILED+--\n";
	Node* a = new Node();
	Node* b = new Node();
	Node* c = new Node();
	a->setCurrent(9);
	c->setCurrent(11);
	b->setCurrent(10);
	b->setRight(c);
	b->setLeft(a);
	std::cout << "current: " << b->getCurrent() << "\nleft: " << b->getLeft()->getCurrent() << "\nright: " << b->getRight()->getCurrent() << "\n";

	return 0;
}

