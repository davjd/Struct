/*
 * =====================================================================================
 *
 *       Filename:  Queue.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/19/2017 04:00:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David M, 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "Queue.h"
template <class T>
Queue<T>::Queue(){}

template <class T>
Queue<T>::~Queue(){
	delete end;
	delete start;
}

template <class T>
Queue<T>::Queue(T itm){
	start = new typename Queue<T>::Node(itm);
	start->next = nullptr;
	end = start;
}

template <class T>
void Queue<T>::enqueue(T itm){

	end->next = new typename Queue<T>::Node(itm);
	end->next->next = nullptr;
	end = end->next;
}

template <class T>
T Queue<T>::dequeue(){
	// variable to hold the item to be dequeued.
	T item = start->itm;
	
	// shift the items.
	// first check if the there is more than one item in the queue.
	if(start->next != nullptr){
		//  reserve memory for the item that will be deleted.
		typename Queue<T>::Node *tmp = start->next;
		// shift the second item as the first.
		start->itm = start->next->itm;
		start->next = start->next->next;
		// we shifted the queue by copying the second item
		// so the second item isnt needed anymore.
		delete tmp;
	}
	else{ // if there is only one item in the queue.
		start->itm = 0;
	}


	return item;

}
