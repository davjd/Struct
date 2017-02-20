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


//class Queue<int>;


int main(){
	std::cout << "------ START ------" << std::endl;
	Queue<int> q(10);
	std::cout << "++++++ FINISHED ++++++" << std::endl;

	return 0;
}

