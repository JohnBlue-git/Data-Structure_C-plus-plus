
/*
Auther: John Blue
Time: 2022/1
Platform: ATOM with MinGw and g++compiler
Object: Template Elementary Sort
Disclaimer: The std::string haven't been consider throughly in this scope
*/

#include <iostream>// for basic i/o
#include <iomanip>// for fixed and setprecision
#include <stdexcept>// for exception
#include <string>// for string
#include <typeinfo>// for typeid
//#include <fstream>// for file
#include <math.h>// floor()

template<class T>
class Sort {
private:
  // var
  T* data;
  int N;
  // constructor
  Sort(const Sort& copy) {}
  // operator
  Sort& operator=(const Sort& copy) { return *this; }

public:
  // costructor
  Sort(T* d, int n): data(d), N(n) {}
  ~Sort() {}

  // function
  void exch(int i, int j);
  void Selection_Sort();
  void Insertion_Sort();
  //void Shell_Sort();

  // merge sort
  void halve(int p_l, int SP);
  //void merge(int p_l, int spl, int SP);
  void merge(int p_l, int spl, int p_r, int spr, int SP);
  void Merge_Sort_tradition();
  void Merge_Sort_button_up();
};

template<class T>
void Sort<T>::exch(int i, int j) {
  if (i == j) {
    return;
  }
  T tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

// Method: selection sort
// find the minmum var in array each time
// compares   ~ N^2 / 2
// exchanges  N
template<class T>
void Sort<T>::Selection_Sort() {
  T min;
  int min_i;
  for (int i = 0; i < N; i++) {
    min = data[i];
    min_i = i;
    for (int j = i + 1; j < N; j++) {
      if (data[j] < min) {
        min = data[j];
        min_i = j;
      }
    }
    exch(i, min_i);
  }
}

// Method: insertion sort
// insert to left one by one, sort in left each time
// on average
// compares   ~ N^2 / 4
// exchanges  ~ N^2 / 4
// worst (up side down order)
// compares   ~ N^2 / 2
// exchanges  ~ N^2 / 2
template<class T>
void Sort<T>::Insertion_Sort() {
  for (int i = 0; i < N; i++) {
    for (int j = i; j > 0; j--) {
      if (data[j] < data[j - 1]) {
        exch(j, j - 1);
      }
      else {
        break;
      }
    }
  }
}

// Method: shell sort (h sort)
// move entries more than on position(by h interval) each time
// best
// ~ N log N
// worst (...)
// ~ N^(3 / 2)
//template<class T>
//void Sort<T>::Shell_Sort()

// floor() or ceil()
// ceil(3 / 2) = ceil(1.5) = 2 // not really @@

//// Method: merge sort
// recursivly divide into two halves, sort, merge
// ~ N log N
//// tradition version is recursive
// revised traditional version have these optimizations
// # memory
// (1) 1/2 dt
// (2) in place merge(hard)
// # insertion merge for small subarray(cutoff length)
// # stop if subarray already sorted
//// button-up is non-recursive (but 10% slower than tradtional ???)
template<class T>
void Sort<T>::halve(int p_l, int SP) {
  if (SP == 1) {
    return;
  }
  else if (SP == 2) {
    exch(p_l, p_l + 1);
    return;
  }
  int spl = SP / 2; if ((SP % 2) != 0) { spl++; }
  int spr = SP - spl;
  int p_r = p_l + spl;
  halve(p_l, spl);
  halve(p_r, spr);//halve(p_l + spl, SP - spl);
  merge(p_l, spl, p_r, spr, SP);//merge(p_l, spl, SP);
}
//
template<class T>
void Sort<T>::merge(int p_l, int spl, int p_r, int spr, int SP) {
//void Sort<T>::merge(int p_l, int spl, int SP) {
  // copy
  T* dt = new T[SP];
  for (int i = 0; i < SP; i++) { dt[i] = data[p_l + i]; }
  // merge
  int i = 0;
  int j = spl;
  for (int k = p_l; k < (p_l + SP); k++) {
    if (i > (spl - 1)) {
      data[k] = dt[j++];
    }
    else if (j > (SP - 1)) {//else if (j > (p_l + SP - 1)) {
      data[k] = dt[i++];
    }
    else {
      if (dt[i] <= dt[j]) {
        data[k] = dt[i++];
      }
      else {
        data[k] = dt[j++];
      }
    }
    // check tool
    //std::cout << k << "\n";
    //std::for_each(data, data + N, [](int& var) { std::cout << " " << var; });
    //std::cout << "\n";
  }
  // delete
  delete[] dt;
}
//
template<class T>
void Sort<T>::Merge_Sort_tradition() {
  halve(0, N);
}
//
template<class T>
void Sort<T>::Merge_Sort_button_up() {
  if ((N % 2) == 0) {
    for (int sp = 1; sp < N; sp *= 2) {
      for (int p_l = 0; p_l < (N - sp); p_l += (sp * 2)) {
        merge(p_l, sp, p_l + sp, sp, sp * 2);
      }
    }
  }
  else {
    for (int sp = 1; sp < (N - 1); sp *= 2) {
      for (int p_l = 1; p_l < (N - sp); p_l += (sp * 2)) {
        if (p_l == 1) {
          merge(0, sp + 1, p_l + sp, sp, sp * 2);
          continue;
        }
        merge(p_l, sp, p_l + sp, sp, sp * 2);
      }
    }
  }
}
