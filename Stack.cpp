/*
 * =====================================================================================
 *
 *       Filename:  stack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/04/2016 09:33:57 PM
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

class Stack{
	// implementing a stack, using an array.
	// for now we'll implement a stack of integers.
	private:
		int size; //  keep track of the size of the stack.
		int top; // keep track of the first item in the stack(head).
		int* values; // pointer to the array.
	public:
		Stack(int size){
			this->size = size; // keep track of size
			this->values = new int[size]; // allocate
			this->top = -1; // no top in the beginning.
		}
		bool isFull(){
			// will check if the array is full.
			return (!(top > (this->size - 1))); // subtracting one because of how arrays are indexed.
		}
		bool isEmpty(){
			// will check if the stack is empty.
			return(this->top == -1);
		}
		void resize(int newSize){
			// will copy old items to the new sized array.
			// will help in amoritized analysis.
			int copySize = this->size; // use the current size to copy later.
			if(newSize < this->size){ // unless the array will be shrinking.
				// if we're shrinking the array, we'll use the new size to copy to avoid segmentation faults.
				copySize = newSize;
			}
			this->size = newSize; // give new size.
			int* newValues = new int[this->size]; // allocate new space with new size.
			for(int i = 0; i < copySize; ++i){ // copy all old items.
				newValues[i] = this->values[i]; // copy old item to new array.
			}
			this->values = newValues; // assign the new array as the original values attribute.
		}
		void push(int itm){
			// method to push an item to the stack.
			// first check if there is enough space.
			if(this->isFull()){
				// if there's not enough space:
				// resize and copy stack.
				resize((this->size * 2)); // resize by doubling size.
			}
			// add new item.
			++this->top; // update the top index.
			this->values[top] = itm; // add the new item to the array.
		}
		int peek(){
			// this method will return the element thats at the top of the stack.
			// check if it's empty.
			if(!isEmpty()) return (this->values[top]); // if not empty, return top item.
			return -1; // if empty, return arbitray number;
		}
		int pop(){
			// this method will return and delete the top item.
			// create variable to return later.
			int itm = -1;
			// check if empty.
			if(!isEmpty()){
				// if not empty:
				// save old top item.
				itm = this->values[this->top];
				--this->top; // decrease the index for the top item.
				// resize if necessary
				if(size > top) resize((this->size / 2)); // resize to half of current size.
			}
			return itm; // return item.
		}
		
};

int main(){
	Stack *myStack = new Stack(4); // create new stack.
	myStack->push(5);
	myStack->push(88);
	myStack->push(10);
	myStack->push(11);
	myStack->push(15);
	int old = myStack->pop();
	int neww = myStack->peek();
	cout << "old: " << old << ", new: " << neww << endl;
}






