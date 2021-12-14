
/*
Auther: John Blue
Time: 2021/12
Platform: ATOM with MinGw and g++compiler
Object: Template Queue with LinkedList
Disclaimer: The std::string LinkedList haven't been consider throughly in this scope
*/

#include <iostream>// for basic i/o
#include "Template_SingleLinkedList.h"
//#include <fstream>// for file

template<class T>
class Queue_LinkedList: public LinkedList<T> {
public:
	// constructor
	Queue_LinkedList(): LinkedList<T>::LinkedList() {};
	Queue_LinkedList(const Queue_LinkedList& copy): LinkedList<T>::LinkedList(copy) {};
	Queue_LinkedList(const LinkedList<T>& copy): LinkedList<T>::LinkedList(copy) {};
	virtual ~Queue_LinkedList() {};

	// operator
	Queue_LinkedList& operator=(const Queue_LinkedList& copy);

	// function
	void Enqueue(T x) { this->Push_back(x); };// enqueue entity
	T Dequeue();// dequeue entity
};

template<class T>
Queue_LinkedList<T>& Queue_LinkedList<T>::operator=(const Queue_LinkedList<T>& copy) {
	LinkedList<T>* pt = this;
	pt->operator=();
	return *this;
}

template<class T>
T Queue_LinkedList<T>::Dequeue() {
	// check
	//if (first == 0) {                         // if list is empty
		//throw ???bad_empty("Pop()");
	//}
	// pop
	T rt;
	ListNode<T>* current = this->first;
	//rt = current->data; it is protected data from Node (not parent class)
	rt = current->get_data();
	this->first = current->get_next();
	delete current;
	// decrese size
	this->size--;
	// return
	return rt;
}
