/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/19/2017 04:23:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David M, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include "Queue.h"



int main(){
	std::cout << "------ START ------" << std::endl;
	Queue<int> q(10);
	q.enqueue(11);
	q.enqueue(12);
	q.print();
	std::cout << "First deque : " << q.dequeue() << std::endl;
	std::cout << "Second deque : " << q.dequeue() << std::endl;//" : " << q.dequeue() << std::endl;
	std::cout << "Third deque : " << q.dequeue() << std::endl;//" : " << q.dequeue() << std::endl;

	std::cout << "\ndequeing done." << std::endl;
	q.enqueue(10);
	q.print();
	std::cout << "Test dequeue: " << q.dequeue() << std::endl;
		
	std::cout << "++++++ FINISHED ++++++" << std::endl;

	return 0;
}

