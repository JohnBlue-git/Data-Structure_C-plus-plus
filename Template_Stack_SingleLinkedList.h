
/*
Auther: John Blue
Time: 2021/11
Platform: ATOM with MinGw and g++compiler
Object: Template Stack with LinkedList
Disclaimer: The std::string LinkedList haven't been consider throughly in this scope
*/

#include <iostream>// for basic i/o
#include "Template_SingleLinkedList.h"
//#include <fstream>// for file

template<class T>
class Stack_LinkedList: public LinkedList<T> {
public:
	// constructor
	Stack_LinkedList(): LinkedList<T>::LinkedList() {};
	Stack_LinkedList(const Stack_LinkedList& copy): LinkedList<T>::LinkedList(copy) {};
	Stack_LinkedList(const LinkedList<T>& copy): LinkedList<T>::LinkedList(copy) {};
	virtual ~Stack_LinkedList() {};

	// operator
	Stack_LinkedList& operator=(const Stack_LinkedList& copy);

	// function
	void Push(T x) { this->Push_front(x); };// push entity
	T Pop();// pop entity
};

template<class T>
Stack_LinkedList<T>& Stack_LinkedList<T>::operator=(const Stack_LinkedList<T>& copy) {
	LinkedList<T>* pt = this;
	pt->operator=();
	return *this;
}

template<class T>
T Stack_LinkedList<T>::Pop() {
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
