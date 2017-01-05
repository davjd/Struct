/*
 * =====================================================================================
 *
 *       Filename:  BTree.h
 *
 *    Description:  Binary Tree implementation.
 *
 *        Version:  1.0
 *        Created:  01/03/2017 11:12:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  youngthvg,
 *   Organization:  
 *
 * =====================================================================================
 */
class Node;
class BTree{
	// interface for BTree.
	private:

	public:
		BTree(); // default constructor
		void push_back(int n); // adds node to the tree.
		void preOrderTraverse(); // traverses preorder.
		void inOrderTraverse(); // traverses in order.
		void postOrderTraverse(); // traverses in post order.
		void levelOrderTraverse(); // traverses in depth priority.
}
