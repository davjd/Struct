/*
 * =====================================================================================
 *
 *       Filename:  Queue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/05/2016 11:35:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  youngthvg, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

class Queue{
	// interface for Queue.
	private:
		int* values;
		int size;
		int tail;
	public:
		Queue(int size){
			this->size = size;
			this->values = new int[size];
			this->tail = -1;
		}
		bool isEmpty();
		bool isFull();
		void enqueue(int itm);
		int getSize();
		int dequeue();
		void resize(int newSize);
};
Queue::isEmpty(){
	return (size == 0);
}
Queue::isFull(){
	// check if the tail index is greater, if so return 
	return (this->tail >= (this->size - 1));
}
Queue::enqueue(int itm){
	++this->tail; // update size.
	//check if there is enough space:
	if(isFull()){
		// if its full, use table-doubling.
		resize((this->size * 2));
	}
	values[this->tail] = itm; // add itm.
}
Queue::getSize(){
	return this->size;
}
Queue::dequeue(){
	// might need to change data structure ..
}

int main(){

	return 0;
}
