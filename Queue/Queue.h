/*
 * =====================================================================================
 *
 *       Filename:  Queue.h
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  02/19/2017 04:00:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  David M, 
 *   Organization:  
 *
 * =====================================================================================
 */
/*  
template <typename T>
struct Node{
	T* next;
	T itm;

	Node(T item){
		itm = item;
	}
	~Node(){
		delete next;
	}
};*/


template <class T>
class Queue{
	public:
		~Queue();
		Queue(T itm);
		Queue();
		void enqueue(T itm);
		T dequeue();
		bool isFull();

		struct Node{
			T* next;
			T itm;

			Node(T item){
				itm = item;
			}
			~Node(){
				delete next;
			}
		};
	private:
		typename Queue<T>::Node *start;
		typename Queue<T>::Node *end;

};
