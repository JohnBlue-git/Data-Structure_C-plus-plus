
/*
Auther: John Blue
Time: 2022/1
Platform: ATOM with MinGw and g++compiler
Object: Testing Template Elementary Sort: Selection sort, Insertion sort, Merge sort
*/

#include <iostream>// for basic i/o
#include <exception>// for exception
#include "Sort_Array.h"

int main()
{
  // initial
  int ini[16];
  std::cout << "\ninitial:" << std::endl;
  int n = sizeof(ini) / sizeof(ini[0]);// get array size
  std::for_each(ini, ini + n, [](int& var) { static int i = 0; var = 5 - i; i++; std::cout << " " << var; });
  std::cout << "\n" <<  std::endl;

  ////// selection sort
  // count time period: start
  clock_t start = clock();
  // construct
  Sort<int> sort(ini, n);
  // selection sort
  std::cout << "Selection Sort:" << std::endl;
  sort.Selection_Sort();
  std::for_each(ini, ini + n, [](int& var) { std::cout << " " << var; });
  std::cout << std::endl;
  // count time period: end
  clock_t end = clock();
  std::cout << "Process Period: " << (end - start) / CLOCKS_PER_SEC << "\n" << std::endl;

  ////// insertion sort
  // count time period: start
  start = clock();
  // reset
  std::for_each(ini, ini + n, [](int& var) { static int i = 0; var = 5 - i; i++; });
  // insertion sort
  std::cout << "Insertion Sort:" << std::endl;
  sort.Insertion_Sort();
  std::for_each(ini, ini + n, [](int& var) { std::cout << " " << var; });
  std::cout << std::endl;
  // count time period: end
  end = clock();
  std::cout << "Process period: " << (end - start) / CLOCKS_PER_SEC << "\n" << std::endl;

  ////// merge sort
  // reset
  std::for_each(ini, ini + n, [](int& var) { static int i = 0; var = 5 - i; i++; });
  // sorting
  std::cout << "Merge Sort(tradition):" << std::endl;
  sort.Merge_Sort_tradition();
  std::for_each(ini, ini + n, [](int& var) { std::cout << " " << var; });
  std::cout << std::endl;
  // reset
  std::for_each(ini, ini + n, [](int& var) { static int i = 0; var = 5 - i; i++; });
  // sorting
  std::cout << "Merge Sort(button up):" << std::endl;
  sort.Merge_Sort_button_up();
  std::for_each(ini, ini + n, [](int& var) { std::cout << " " << var; });
  std::cout << std::endl;
}
