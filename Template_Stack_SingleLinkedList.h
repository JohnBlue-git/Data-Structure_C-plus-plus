
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
	void Push(T x) { this->Push_front(x); };// push entity; push to front
	T Pop();// pop entity                                 ; pop from front

	// exception class
	class n_bad_empty : public LinkedList<T>::bad_empty
	{
	public:
		explicit n_bad_empty(const std::string & s = " "): LinkedList<T>::bad_empty(s + ", Empty error in Stack object\n") {};
		virtual ~n_bad_empty() throw() {}
	};
	/*
	class n_bad_index : public LinkedList<T>::bad_index
	{
	private:
		int index;
	public:
		explicit n_bad_index(int ix = 0, const std::string & s = " "): LinkedList<T>::bad_index(ix , s + ", Index error in Stack object\n") {};
		int get_index() const { return index; }
		virtual ~n_bad_index() throw() {}
	};
	*/
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
	if (this->first == 0) {                         // if list is empty
		throw n_bad_empty("Pop()");
	}
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
