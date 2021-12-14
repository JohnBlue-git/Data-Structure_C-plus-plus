
/*
Auther: John Blue
Time: 2021/12
Platform: ATOM with MinGw and g++compiler
Object: Testing template Queue with LinkedList
*/

#include <iostream>// for basic i/o
#include <exception>// for exception
#include "Template_Queue_SingleLinkedList.h"
using namespace std;

int main() {
  Queue_LinkedList<int> test;
  cout << "Push" << endl;
  for(int i = 0; i < 6; i++) {
    test.Enqueue(i);
  }
  cout << "is empty? 1 true 0 false: " << test.isEmpty() << endl;
  cout << "Print" << endl;
  test.PrintList();
  cout << test << endl;
  cout << "Size" << endl;
  cout << test.length() << endl;
  cout << endl;

  cout << "Copy" << endl;
  Queue_LinkedList<int> copy(test);
  cout << "Print" << endl;
  copy.PrintList();
  cout << endl;

  cout << "Assign" << endl;
  Queue_LinkedList<int> assign = test;
  cout << "Print" << endl;
  assign.PrintList();
  cout << endl;

  cout << "Transeverse" << endl;
  Queue_LinkedList<int> transe(test.transverse());
  cout << "Print" << endl;
  transe.PrintList();
  cout << endl;

  cout << "Sorting" << endl;
  Queue_LinkedList<int> sort(test.sorting());
  cout << "Print" << endl;
  sort.PrintList();
  cout << "Size" << endl;
  cout << test.length() << endl;
  cout << endl;

  //cout << "Clear" << endl;
  //test.Clear();
  cout << "Pop" << endl;
  for(int i = 0; i < 6; i++) {
    cout << test.Dequeue() << endl;
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
