
/*
Auther: John Blue
Time: 2022/1
Platform: ATOM with MinGw and g++compiler
Object: Priority_Queue
*/

#include <iostream> // i/o
#include <stdlib.h> // include rand function
#include <time.h>   // time function

class MaxPQ {
private:
  // data
  int N;
  int size;
  int* data;

  // constructor and operator
  MaxPQ(const MaxPQ& copy);
  MaxPQ& operator=(const MaxPQ& copy);

public:
  // constructor
  MaxPQ(int L): N(1), size(1) {
    for (int i = - 1; i < L; i++) { N *= 2; }
    data = new int[N];
    for (int i = 0; i < N; i++) { data[i] = 0; }
  }
  ~MaxPQ() { delete[] data; }

  // function
  bool isEmpty() const { return size == 1; };
  bool isFull() const { return size >= N; };
  void print();
  void exch(int i, int j);
  void EnQue(int x);
	int DeMax();
};

void MaxPQ::print() {
  // check
  if (isEmpty()) {
    std::cout << "empty\n" << std::endl;
    return;
  }
  // print
  int k = 1;
  while (k < (N / 2)) {
    for (int i = k; i < k * 2; i++) {
      std::cout << " " << data[i];
    }
    std::cout << "\n";
    k *= 2;
  }
}

void MaxPQ::exch(int i, int j) {
  if (i == j) {
    return;
  }
  int tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

// Method: Priority_Queue
// by using bunary heap
// 1
// 2 3
// 4 5 6 7
// 8 9 ...
// pop out max value instead of dequeue
//
// note: position[0] is not used
//
// enqueue ~ log N
// dequeue ~ log N
void MaxPQ::EnQue(int x) {
  // check
  if (isFull()) {
    std::cout << "full\n" << std::endl;
    return;
  }
  // en
  data[size] = x;
  int ck = size++;// child id
  int pk = (ck - (ck % 2)) / 2;// parent id
  while(ck > 1 && data[ck] > data[pk]) {// we want data[pk] larger
    exch(ck, pk);
    ck /= 2;
    pk = (ck - (ck % 2)) / 2;
  }
}

// note: have some problem ... @@
int MaxPQ::DeMax() {
  // check
  if (isEmpty()) {
    //std::cout << "empty\n" << std::endl;
    return - 1;
  }
  // copy
  int rt = data[1];
  // exch root and last
  exch(1, size);
  // sink root
  int pk = 1;// parent id
  int ck = 2 * pk;// child id
  while (ck <= N) {
    // left or right node is larger
    if (ck < N && data[ck] < data[ck + 1]) {
      ck++;
    }
    // sorted and break
    if (data[ck] < data[pk]) {
      break;
    }
    // exchange
    exch(pk, ck);
    // itertation
    pk = ck;
    ck = 2 * pk;
  }
  // null last
  data[size--] = 0;
  // return
  return rt;
}

int main()
{
  int L = 3;// 2^3
  int dt[7] = {11, 13, 16, 15, 14, 17, 12};
  MaxPQ pq(L);
  // enq
  for (int i = 0; i < 7; i++) {
    pq.EnQue(dt[i]);
  }
  std::cout << "MaxPQ:\n";
  pq.print();
  std::cout << "\n";
  // del
  // note: have some problem ... @@
  std::cout << "Del: " << pq.DeMax() << "\n";
  std::cout << "Del: " << pq.DeMax() << "\n";
  pq.print();
  std::cout << "\n";
}
