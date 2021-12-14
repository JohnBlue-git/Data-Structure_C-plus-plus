
/*
Auther: John Blue
Time: 2021/12
Platform: ATOM with MinGw and g++compiler
Object: Template Stack by Array with copy constructer, assignment constructer, friend content, and simple exception class
Disclaimer: The std::string LinkedList haven't been consider throughly in this scope
*/

#include <iostream>// for basic i/o
#include <iomanip>// for fixed and setprecision
#include <stdexcept>// for exception
#include <string>// for string
#include <typeinfo>// for typeid
//#include <fstream>// for file

template<class T, int N>
class Stack_Array {
protected:
	// size
	int size;
  T data[N];

public:
	// constructor
	Stack_Array(): size(0) { for(int i = 0; i < N; i++) data[i] = 0; };
	Stack_Array(const Stack_Array& copy): size(copy.size) { for(int i = 0; i < N; i++) data[i] = copy.data[i]; };
	virtual ~Stack_Array() {};

	// operator
	Stack_Array& operator=(const Stack_Array& copy);
	template<class U, int W> friend std::ostream& operator<<(std::ostream& os, const Stack_Array<U, W>& print);

	// function
	bool isEmpty() const;// check empty
  bool isFull() const;// check full
	int length() const;// size of array
	void PrintList() const;// print array
	void Clear();// clear list
	void Push(T x);// add entity (Push to back)
	T Pop();// add entity (Pop from back)

	// exception class
	class bad_empty : public std::logic_error
	{
	public:
		explicit bad_empty(const std::string & s = " "): std::logic_error(s + ", Empty error in List object\n") {};
		virtual ~bad_empty() throw() {}
	};
	class bad_index : public std::logic_error
	{
	private:
		int index;
	public:
		explicit bad_index(int ix = 0, const std::string & s = " "): index(ix), std::logic_error(s + ", Index error in List object\n") {};
		int get_index() const { return index; }
		virtual ~bad_index() throw() {}
	};
};

template<class T, int N>
Stack_Array<T, N>& Stack_Array<T, N>::operator=(const Stack_Array<T, N>& copy) {
	// check
	if (&copy == this) {
		return *this;
	}
	// clear
	this->Clear();
	// copy content
	size = copy.size;
  	for (int i = 0; i < size; i++) {
		this->Push(copy.data);
	}
	// return
	return *this;
}

template<class T, int N>
bool Stack_Array<T, N>::isEmpty() const {
  return size == 0;
}

template<class T, int N>
bool Stack_Array<T, N>::isFull() const {
  return size > N;
}

template<class T, int N>
int Stack_Array<T, N>::length() const {
	return size;
}

template<class T, int N>
void Stack_Array<T, N>::PrintList() const {
  if (size == 0) {                         // if list is empty
		throw bad_empty("PrintList()");
	}
	std::cout << "List: ";
	for (int i = 0; i < size; i++) {                    // execute to last NULL
		if (typeid(T) == typeid(double)) {
			std::cout << std::fixed << std::setprecision(3) << data[i] << " ";
		}
		else if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(std::string)) {
			std::cout << data[i] << " ";
		}
	}
	std::cout << std::endl;
}

template<class T, int N>
std::ostream& operator<<(std::ostream& os, const Stack_Array<T, N>& print) {
	// check
	if (print.size == 0) {                         // if list is empty
		// not yet know what to implment exception for operator
		//return os << print.bad_empty("operator<<");
	}
	// print out
	os << "List: ";
  for (int i = 0; i < print.size; i++) {                    // execute to last NULL
		if (typeid(T) == typeid(double)) {
			os << std::fixed << std::setprecision(3) << print.data[i] << " ";
		}
		else if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(std::string)) {
			os << print.data[i] << " ";
		}
	}
	// return
	return os;
}

template<class T, int N>
void Stack_Array<T, N>::Clear() {
  // clear
	for (int i = 0; i < N; i++) {
    data[i] = 0;
	}
	// !!! reset size
	size = 0;
}

template<class T, int N>
void Stack_Array<T, N>::Push(T x) {
  // check
  if (size == N) {                   // bad index(full)
		throw bad_index(x, "Overflow Push");
	}
  // add
  data[size++] = x;
  //data[N - size++ - 1] = x;// ??? push front
}

template<class T, int N>
T Stack_Array<T, N>::Pop() {
  // check
  if (size == 0) {                   // bad empty
		throw bad_empty("Pop");
	}
	// return
	return data[size-- - 1];
}
