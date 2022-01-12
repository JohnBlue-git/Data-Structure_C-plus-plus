
/*
Auther: John Blue
Time: 2022/1
Platform: ATOM with MinGw and g++compiler
Object: Testing Template Partition Sort
*/

#include <iostream>// for basic i/o
#include <exception>// for exception
#include "Partition_Array.h"

int main()
{
  // initial
  int ini[16];
  std::cout << "\ninitial:" << std::endl;
  int n = sizeof(ini) / sizeof(ini[0]);// get array size
  std::for_each(ini, ini + n, [](int& var) { static int i = 0; var = 5 - i; i++; std::cout << " " << var; });
  std::cout << "\n" <<  std::endl;

  ////// quick sort (partiion sort)
  // count time period: start
  clock_t start = clock();
  // construct
  Partition<int> part(ini, n);
  // sort
  std::cout << "Partition Sort:" << std::endl;
  part.Quick_Sort();
  std::for_each(ini, ini + n, [](int& var) { std::cout << " " << var; });
  std::cout << std::endl;
  // count time period: end
  clock_t end = clock();
  std::cout << "Process Period: " << (end - start) / CLOCKS_PER_SEC << "\n" << std::endl;

  // count time period: start
  start = clock();
  // reset
  std::for_each(ini, ini + n, [](int& var) { static int i = 0; var = 5 - i; i++; });
  // sort
  std::cout << "Three Way:" << std::endl;
  part.D_Sort();
  std::for_each(ini, ini + n, [](int& var) { std::cout << " " << var; });
  std::cout << std::endl;
  // count time period: end
  end = clock();
  std::cout << "Process Period: " << (end - start) / CLOCKS_PER_SEC << "\n" << std::endl;
}
