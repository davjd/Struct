/*
 * :
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
#include <iostream>

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<std::string>;
template class Queue<char>;
template <class T>
Queue<T>::Queue(){
	start = nullptr;
	end = nullptr;
}

template <class T>
Queue<T>::~Queue(){
	if(start != nullptr) {
		delete start;
		start = nullptr;
		end = nullptr;
	}
}
template<class T>
Queue<T>::Queue(T itm){
	init(itm);
}

template<class T>
void Queue<T>::init(T itm){
	start = new typename Queue<T>::Node(itm);
	start->next = nullptr;
	end = start;
}

template <class T>
void Queue<T>::enqueue(T itm){
	if(start == nullptr){
		init(itm);
	}
	else{

		end->next = new typename Queue<T>::Node(itm);
		end->next->next = nullptr;
		end = end->next;
	}
}

template <class T>
void Queue<T>::print(Node* node){
	if(node == nullptr) return;
	else{
		std::cout << node->itm << std::endl;
		print(node->next);
	}	
}

template <class T>
void Queue<T>::print(){
	if(start == nullptr) std::cout << "Queue is empty." << std::endl;
	else print(start);
}

template <class T>
T Queue<T>::dequeue(){
	// variable to hold the item to be dequeued.
	if(start == nullptr) return 0; // if queue is empty.i
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
		tmp->next = nullptr;
		delete tmp;
	}
	else{ // if there is only one item in the queue.
		delete start;
		start = nullptr;
	}
	return item;

}

template <class T>
T Queue<T>::peek(){
	return end->itm;
}

template <class T>
T Queue<T>::get(int idx){
	return get(idx, start);
}

template <class T>
T Queue<T>::get(int idx, Node* node){
	if(idx == -1 ||  node == nullptr) return 0;
	else return get(--idx, node->next);
}
