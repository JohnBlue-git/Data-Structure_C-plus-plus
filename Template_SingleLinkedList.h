
/*
Auther: John Blue
Time: 2021/10
Platform: ATOM with MinGw and g++compiler
Object: Template SingleLinkedList with copy constructer, assignment constructer, friend content, and simple exception class
Disclaimer: The std::string LinkedList haven't been consider throughly in this scope
*/

#include <iostream>// for basic i/o
#include <iomanip>// for fixed and setprecision
#include <stdexcept>// for exception
#include <string>// for string
#include <typeinfo>// for typeid
//#include <fstream>// for file

// set LinkedList as friend of ListNode
template<class T>
class LinkedList;

template<class T>
class ListNode {
private:// content
    T data;
    ListNode* next;

private:// prevent cilent from using these
    // constructor
    ListNode(const ListNode& copy) {}

    // operator
    ListNode& operator=(const ListNode& copy) { return *this; }

public:
	// constructor
	ListNode(): data(0), next(0) {}
	ListNode(T a): data(a), next(0) {}
	~ListNode() {
    data = 0;
    next = 0;
    // or you can use another method
    //https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
    //data = 0;
    //delete next;
    //caution the chain reaction when a node is deleted
    //for example: pop current->... then current->next = 0 then delete current (to prevent further delete)
    //and it will simplified deconstructor
    /*
    ~LinkedList() {
      delete first;
      end = 0;
      size = 0;
    }
    */
  }

  // !!! must be public for derived LinkedList
  // function
  T get_data() const { return data; }
  ListNode* get_next() const { return next; }

	// friend class
	friend class LinkedList<T>;
	template<class U> friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& print);
};

template<class T>
class LinkedList {
protected:
	// size
	int size;

	// head / end pointer
	ListNode<T>* first;
	ListNode<T>* end;

public:
	// constructor
	LinkedList(): first(0), end(0), size(0) {};
	LinkedList(const LinkedList& copy);
	virtual ~LinkedList();

	// operator
	LinkedList& operator=(const LinkedList& copy);
	T& operator[](const unsigned int x);
	//T& operator[](const unsigned int x) const;// the same even with const
	//T operator[](const unsigned int x) const;// not mutable
	template<class U> friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& print);
	//friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& print)// not work
	//friend std::ostream& operator<< <> (std::ostream& os, const LinkedList<T>& print)// not work

	// function
	bool isEmpty() const;// check empty
	int length() const;// size of list
	void PrintList() const;// print list
	void Clear();// clear list
	void Push_back(T x);// add entity
	void Push_front(T x);// add entity
	LinkedList transverse() const;// transverse
	LinkedList sorting() const;// sort from small to big

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

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy): first(0), end(0) {
	// copy content
	ListNode<T>* current = copy.first;
	while (current != 0) {
		this->Push_back(current->data);
		// increase size number
		size++;
		// iteration
		current = current->next;
	}
}

template<class T>
LinkedList<T>::~LinkedList() {
	this->Clear();
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& copy) {
	// check
	if (&copy == this) {
		return *this;
	}
	// clear
	this->Clear();
	// copy content
	ListNode<T>* current = copy.first;
	while (current != 0) {
		this->Push_back(current->data);
		// increase size number
		size++;
		// iteration
		current = current->next;
	}
	// return
	return *this;
}

template<class T>
//T& LinkedList<T>::operator[](const unsigned int x) const { // the same even with const
T& LinkedList<T>::operator[](const unsigned int x) {
	// check
	if (first == 0) {                     // id list list is empty
		throw bad_empty("[] operation");
	}
	if (size < x + 1) {                   // bad index
		throw bad_index(x, "[] operation");
	}
	// extract out the i th item
	ListNode<T>* current = first;         // point to first
	unsigned int i = 0;
	while (i < x) {
		current = current->next;            // point to ? th in the list
		i++;
	}
	return current->data;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
	if (first == 0) {                      // if list is empty
		return true;
	}
	else {
		return false;
	}
}

template<class T>
int LinkedList<T>::length() const {
	return size;
}

template<class T>
void LinkedList<T>::PrintList() const {
	if (first == 0) {                         // if list is empty
		throw bad_empty("PrintList()");
	}
	ListNode<T>* current = first;             // point to first
	std::cout << "List: ";
	while (current != 0) {                    // execute to last NULL
		if (typeid(T) == typeid(double)) {
			std::cout << std::fixed << std::setprecision(3) << current->data << " ";
		}
		else if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(std::string)) {
			std::cout << current->data << " ";
		}
		current = current->next;
	}
	std::cout << std::endl;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& print) {
	// check
	if (print.first == 0) {                         // if list is empty
		// not yet know what to implment exception for operator
		//return os << print.bad_empty("operator<<");
    os << "operator<<, Empty error in List object\n";
    return os;
	}
	// print out
	ListNode<T>* current = print.first;             // point to first
	os << "List: ";
	while (current != 0) {                          // execute to last NULL
		if (typeid(T) == typeid(double)) {
			os << std::fixed << std::setprecision(3) << current->data << " ";
		}
		else if (typeid(T) == typeid(int) || typeid(T) == typeid(float) || typeid(T) == typeid(std::string)) {
			os << current->data << " ";
		}
		current = current->next;
	}
	// return
	return os;
}

template<class T>
void LinkedList<T>::Clear() {
	ListNode<T>* current;
	while (first != 0) {
		current = first;
		first = first->next;
		// !!! delete and prevent bug
    current->next = 0;
		delete current;
		current = 0;
	}
	// !!! remembr to 0 pointer
	end = 0;
	// !!! reset size
	size = 0;
}

template<class T>
void LinkedList<T>::Push_back(T x) {
	// add new node
	ListNode<T>* newNode = new ListNode<T>(x);
	// connection
	if (first == 0 && end == 0) {              // indicate list is empty now
		first = newNode;                         // fist and end are all point to new node
		end = newNode;
	}
	else {                                     // link new node to end pointer
		end->next = newNode;
		end = newNode;
	}
	// increase size number
	size++;
}

template<class T>
void LinkedList<T>::Push_front(T x) {
	// add new node
	ListNode<T>* newNode = new ListNode<T>(x);
	// connection
	if (first == 0 && end == 0) {              // indicate list is empty now
		first = newNode;                         // fist and end are all point to new node
		end = newNode;
	}
	else {                                     // link new node to end pointer
		newNode->next = first;
		first = newNode;
	}
	// increase size number
	size++;
}

template<class T>
LinkedList<T> LinkedList<T>::transverse() const {
	// list for retrun
	LinkedList<T> RT;
	// copy content
	ListNode<T>* current = first;
	while (current != 0) {
		RT.Push_front(current->data);
		// iteration
		current = current->next;
	}
	// return
	return RT;
}

template<class T>
LinkedList<T> LinkedList<T>::sorting() const {
	// list for retrun
	LinkedList<T> RT;
	// sorting
	ListNode<T>* current = first;
	ListNode<T>* current_RT;
	while (current != 0) {
		// point to RT first
		current_RT = RT.first;
		// the first round
		if (current_RT == 0) {
			RT.Push_front(current->data);
		}
		// second ... rounds
		else {
			// compare value
			// condition 1: bigger than the whole RT list
			if (current->data >= RT.end->data) {
				RT.Push_back(current->data);
			}
			// condition 2: smaller than the whole RT list
			else if (current->data <= RT.first->data) {
				RT.Push_front(current->data);
			}
			// condition 3: compare though loop
			else {
				// new node
				ListNode<T>* newNode = new ListNode<T>(current->data);
				while (current->data > current_RT->next->data) {
					current_RT = current_RT->next;
				}
				newNode->next = current_RT->next;
				current_RT->next = newNode;
				// increase size
				RT.size++;
			}
		}
		// iteration
		current = current->next;
	}
	// return
	return RT;
}
