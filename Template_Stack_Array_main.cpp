
/*
Auther: John Blue
Time: 2021/12
Platform: ATOM with MinGw and g++compiler
Object: Testing template Stack by Array
*/

#include <iostream>// for basic i/o
#include <exception>// for exception
#include "Template_Stack_Array.h"
using namespace std;

int main() {
  Stack_Array<int, 6> test;
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
  Stack_Array<int, 6> copy(test);
  cout << "Print" << endl;
  copy.PrintList();
  cout << endl;

  cout << "Assign" << endl;
  Stack_Array<int, 6> assign = test;
  cout << "Print" << endl;
  assign.PrintList();
  cout << endl;

  cout << "Pop" << endl;
  for(int i = 0; i < 3; i++) {
    cout << test.Pop() << endl;
  }
  test.PrintList();
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
