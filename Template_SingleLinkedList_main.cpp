
/*
Auther: John Blue
Time: 2021/10
Platform: ATOM with MinGw and g++compiler
Object: Testing template LinkedList
*/

#include <iostream>// for basic i/o
#include <exception>// for exception
#include "Template_SingleLinkedList.h"
using namespace std;

int main() {
  LinkedList<int> test;
  cout << "Push" << endl;
  for(int i = 0; i < 6; i++) {
    test.Push_front(i);
    test.Push_back(i);
  }
  test.Push_back(6);
  //test[3] = 33;// mutate
  cout << "is empty? 1 true 0 false: " << test.isEmpty() << endl;
  cout << "Print" << endl;
  test.PrintList();
  cout << test << endl;
  cout << "Size" << endl;
  cout << test.length() << endl;
  cout << endl;

  cout << "Copy" << endl;
  LinkedList<int> copy(test);
  cout << "Print" << endl;
  copy.PrintList();
  cout << endl;

  cout << "Assign" << endl;
  LinkedList<int> assign = test;
  cout << "Print" << endl;
  assign.PrintList();
  cout << endl;

  cout << "Transeverse" << endl;
  LinkedList<int> transe = test.transverse();
  cout << "Print" << endl;
  transe.PrintList();
  cout << endl;

  cout << "Sorting" << endl;
  //LinkedList<int> sort = test.insertion_sort();
  LinkedList<int> sort = test.merge_sort();//??? not right
  cout << "Print" << endl;
  sort.PrintList();
  //test.PrintList();
  cout << "Size" << endl;
  cout << sort.length() << endl;
  cout << endl;

  cout << "Clear" << endl;
  test.Clear();
  cout << "is empty? 1 true 0 false: " << test.isEmpty() << endl;
  cout << "Print" << endl;
  try {
    test.PrintList();
  }
  catch(exception& e) {
    cout << e.what() << endl;
  }
  cout << endl;
}
