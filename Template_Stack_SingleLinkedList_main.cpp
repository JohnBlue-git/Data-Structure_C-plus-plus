
/*
Auther: John Blue
Time: 2021/11
Platform: ATOM with MinGw and g++compiler
Object: Testing template Stack with LinkedList
*/

#include <iostream>// for basic i/o
#include <exception>// for exception
#include "Template_Stack_SingleLinkedList.h"
using namespace std;

int main() {
  Stack_LinkedList<int> test;
  cout << "Push" << endl;
  for(int i = 0; i < 6; i++) {
    test.Push(i);
  }
  cout << "is empty? 1 true 0 false: " << test.isEmpty() << endl;
  cout << "Print" << endl;
  test.PrintList();
  cout << test << endl;
  cout << "Size" << endl;
  cout << test.length() << endl;
  cout << endl;

  cout << "Copy" << endl;
  Stack_LinkedList<int> copy(test);
  cout << "Print" << endl;
  copy.PrintList();
  cout << endl;

  cout << "Assign" << endl;
  Stack_LinkedList<int> assign = test;
  cout << "Print" << endl;
  assign.PrintList();
  cout << endl;

  cout << "Transeverse" << endl;
  Stack_LinkedList<int> transe(test.transverse());
  cout << "Print" << endl;
  transe.PrintList();
  cout << endl;

  cout << "Sorting" << endl;
  Stack_LinkedList<int> sort(test.insertion_sort());
  cout << "Print" << endl;
  sort.PrintList();
  cout << "Size" << endl;
  cout << test.length() << endl;
  cout << endl;

  //cout << "Clear" << endl;
  //test.Clear();
  cout << "Pop" << endl;
  for(int i = 0; i < 6; i++) {
    cout << test.Pop() << endl;
  }
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
