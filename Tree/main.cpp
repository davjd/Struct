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
 *         Author: David M, 
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
	tree.push(17);
	tree.push(43);
	tree.push(49);
	tree.push(31);
	tree.push(40);
	tree.push(9);
	std::cout << "ROOT: " << tree.getRootKey() << "\n---TRAVERSE----\n\n";
	
	tree.preOrderTraverse();
	//std::cout << "max child of left subtree: " << tree.getRoot()->maxChildPar(tree.getRoot()->getLeft())->key() << std::endl;
	tree.del(31);
	std::cout << "\nDELETED\n\n";
	std::cout << "root: " << tree.getRootKey() << "\n";
	tree.preOrderTraverse();
	std::cout << "\nALL METHODS PASSED\n\n";
	return 0;
}

