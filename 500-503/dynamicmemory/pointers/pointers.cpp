#include <iostream>

using std::cout, std::endl;

void printAry(int ary[], size_t size) {
  // side effect to fix
  ary[0] = -1;

  for (size_t i=0; i<size; ++i) {
    cout << ary[i] << endl;
  }
}


int main() {
  int i = 4;
  // declare pointer variable k based on i
  int* k = &i;

  // replace ??? with the address of the variable i
  cout << "address of i: " << ??? << endl;
  cout << "value in i:   " << i << endl;
  // replace ??? with the address of the varaible k
  cout << "address of k: " << ??? << endl;
  cout << "value in k:   " << k << endl;
  // replace ??? with dereference of k
  cout << "value in *k:  " << ??? << endl;

  int ary[] = {5, 7, 9};
  size_t size = 3;

  printAry(ary, size);

}