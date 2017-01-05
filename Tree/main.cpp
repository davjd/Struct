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
	BTree tree(10);
	tree.push(13);
//	tree.push(8);
	//std::cout << "root: " << tree.getRoot()->getCurrent() << "\n";
	//tree.preOrderTraverse();
	return 0;
}

