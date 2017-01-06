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
	//tree.push(40);
	std::cout << "ROOT: " << tree.getRootKey() << "\n---TRAVERSE----\n\n";
	
	//std::cout << "root: " << tree.getRoot()->getCurrent() << "\n";
	tree.preOrderTraverse();
	return 0;
}

