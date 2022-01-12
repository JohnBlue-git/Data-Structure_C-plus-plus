
/*
Auther: John Blue
Time: 2022/1
Platform: ATOM with MinGw and g++compiler
Object: Template Partition Sort
Disclaimer: The std::string haven't been consider throughly in this scope

Note:
ppt ...
ppt 2.3 have 3 ~ 4 quick sorts
*/

#include <iostream>// for basic i/o
#include <iomanip>// for fixed and setprecision
#include <stdexcept>// for exception
#include <string>// for string
#include <typeinfo>// for typeid
//#include <fstream>// for file
#include <math.h>// floor()

template<class T>
class Partition {
private:
  // var
  T* data;
  int N;
  // constructor
  Partition(const Partition& copy) {}
  // operator
  Partition& operator=(const Partition& copy) { return *this; }

public:
  // costructor
  Partition(T* d, int n): data(d), N(n) {}
  ~Partition() {}

  // function
  void exch(int i, int j);
  //
  void part(int lo, int hi);
  void Quick_Sort();
  //
  void three_way(int lo, int hi);
  void D_Sort();// Dijkstra
  //
  //void ...();
  //void Dual_pivot();
};

template<class T>
void Partition<T>::exch(int i, int j) {
  if (i == j) {
    return;
  }
  T tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

// Method: Quick sort
//
// set a[lo] as v
// repeat until i,j cross
//  scan ... so long as a[i] < v
//  scan ... so long as a[j] > v
//  exch(i,j)
//  if i,j cross
//    exch(lo,j)
//
// on average ~ 1.39 N log N
// best       ~ N log N
// worst      ~ N^2 / 2
template<class T>
void Partition<T>::part(int lo, int hi) {
  // end
  if (hi <= lo) { return; }
  // part
  int i = lo; int j = hi;
  while(1) {
    while(data[++i] < data[lo]) {// until data[i] > data[0]
      if (i == hi) { break; }
    }
    while(data[--j] > data[lo]) {// until data[j] < data[0]
      if (j == lo) { break; }
    }
    if (i >= j) { break; }// cross
    exch(i, j);
  }
  exch(lo, j);
  // recusive sub loop
  part(lo, j);// since --j ... so that ... j is more proper
  part(j + 1, hi);
}

template<class T>
void Partition<T>::Quick_Sort() {
  part(0, N);// since --j ... so that ... N is more proper
}

// Method: Three Way
//
// set a[lo] as v
// repeat until i, gt cross
//  if a[i] < v
//    exch(lt++, i++)
//  if a[i] > v
//    exch(i, gt--)
//  if a[i] == v
//    i++;
//
// on average ~ 2 N log N
// best       ~ N
// worst      ~ N^2 / 2
template<class T>
void Partition<T>::three_way(int lo, int hi) {
  // end
  if (hi <= lo) { return; }
  // three way
  int lt = lo; int gt = hi;
  int i = lo;
  while(i <= gt) {
    if (data[i] < data[lo]) {
      exch(lt++, i++);
    }
    else if (data[i] > data[lo]) {
      exch(i, gt--);
    }
    else {
      i++;
    }
  }
  // recusive sub loop
  three_way(lo, lt - 1);
  three_way(gt + 1, hi);
}

template<class T>
void Partition<T>::D_Sort() {
  three_way(0, N - 1);
}
