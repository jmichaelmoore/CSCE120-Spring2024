#include <iostream>

using std::cin, std::cout, std::endl;

// using column major ordering

void makeary();
void loadary();
void printary();
void releaseary();

int main() {
  srand(time(NULL));

  // could read in rows and columns, but I'll hard code for this example
  unsigned int rows = 4;
  unsigned int cols = 3;

  // allocate memory
  makeary();

  // initialize
  loadary();

  // use
  printary();

  // release memory
  releaseary();
}

void makeary() {
}

void loadary() {
  // can have col or row be the outer loop, it doesn't matter
  for (unsigned int col=0; col<cols; col++) {
    for (unsigned int row=0; row<rows; row++) {
      char val;
      if (rand()%2) { // uppercase
        val = rand()%26 + 'A';
      }
      else { // lowercase
        val = rand()%26 + 'a';
      }
      ary[col][row] = val;
    }
    cout << endl;
  }
}

void printary() {
  // must print with row in outer loop to match our mental model
  for (unsigned int row=0; row<rows; row++) {
    for (unsigned int col=0; col<cols; col++) {
      cout << ary[col][row] << " ";
    }
    cout << endl;
  }
}

void releaseary() {

}