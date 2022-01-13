
/*
Auther: John Blue
Time: 2022/1
Platform: ATOM with MinGw and g++compiler
Object: Binary Search Tree
*/

#include <iostream> // i/o
#include <stdlib.h> // include rand function
#include <time.h>   // time function

// Method: Binary Search Tree
// left < root < right
//
// on average
// put 1.39 log N
// get 1.39 log N
// gaurantee
// put N
// get N
//
// note:
// sequential search: unsorted linked list
//                    one by one
//     binary search: sorted array
//                    half by half
//                    smaller? |find| larger? | ...
class BST {
private:
  // content
  int key;
  int data;
  BST* left;
  BST* right;
  // operator
  BST& operator=(const BST& copy);

protected:
  // function
  int get_key() const { return key; }
	int get_data() const { return data; }
	BST* get_left() const { return left; }
  BST* get_right() const { return right; }

public:
  // constructor
  //BST(): key(0), data(0), left(0), right(0) {}
  BST(int k, int d): key(k), data(d), left(0), right(0) {}
  BST(const BST& copy);
  ~BST();

  // function
  void print();
  void put(int ky, int dt);
  int get(int ky);
  int MinK();
  int MaxK();
  //int floor(int ky);
  //int ceil(int ky);
  //void delete(); yet understand ppt 3.2 p29
};

BST::BST(const BST& copy): key(copy.key), data(copy.data), left(0), right(0) {
  // left
  if (copy.left != 0) {
    left = new BST(*copy.left);
  }
  // right
  if (copy.right != 0) {
    right = new BST(*copy.right);
  }
}

BST::~BST() {
  // data
  key = 0;
  data = 0;
  // left
  if (left != 0) {
    (*left).BST::~BST();
  }
  //else if (left == 0) {
    //delete left;
  //}
  // right
  if (right != 0) {
    (*right).BST::~BST();
  }
  //else if (right == 0) {
    //delete right;
  //}
}

void BST::print() {
  BST* current = this;
  // checks
  if (current->key == 0) {
    return;
  }
  // middle
  std::cout << "key" << current->key << ": " << current->data << "\n";
  // left
  if (left != 0) {
    current->left->print();
  }
  // right
  if (right != 0) {
    current->right->print();
  }
}

void BST::put(int ky, int dt) {
  BST* current = this;
  if (ky < key) {
    if (current->left == 0) {
      current->left = new BST(ky, dt);
    }
    else {
      current = current->left;
      current->put(ky, dt);
    }
  }
  else if (ky > key) {
    if (current->right == 0) {
      current->right = new BST(ky, dt);
    }
    else {
      current = current->right;
      current->put(ky, dt);
    }
  }
  else if (ky == key) {
    data = dt;
  }
}

int BST::get(int ky) {
  BST* current = this;
  while (current != 0) {
    if (ky < current->key) {
      current = current->left;
    }
    else if (ky > current->key) {
      current = current->right;
    }
    else if (ky == current->key) {
      return current->data;
    }
  }
  return - 1;
}

int BST::MinK() {
  BST* current = this;
  while(current->left != 0) {
    current = current->left;
  }
  return current->data;
}

int BST::MaxK() {
  BST* current = this;
  while(current->right != 0) {
    current = current->right;
  }
  return current->data;
}

// no kid
// one kid
// two kids
// ... yet understand
//int BST::delete(int ky) {}

int main()
{
  //
  //                        8(0)
  //           4(10)                     12(20)
  //     2(30)       6(40)        10(50)         14(60)
  // 1(70) 3(80) 5(90) 7(100) 9(110) 11(120) 13(130) 15(140)
  int dt[15] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
  BST bt(dt[0], 0);
  // put
  for (int i = 1; i < 15; i++) {
    bt.put(dt[i], i * 10);
  }
  // print
  std::cout << "BST:\n";
  bt.print();
  std::cout << "\n";
  // get
  std::cout << "key(8):" << bt.get(8) << "\n";
  std::cout << "key(9):" << bt.get(9) << "\n";
  // max key vale
  std::cout << "Max Key(15):" << bt.MaxK() << "\n";
  // delete
}
