#include <iostream>

using std::cin, std::cout, std::endl;

// using column major ordering

void loadary(char* ary, unsigned int rows, unsigned int cols);
void printary(const char* ary, unsigned int rows, unsigned int cols);

int main() {
  srand(time(NULL));

  // could read in rows and columns, but I'll hard code for this example
  unsigned int rows = 4;
  unsigned int cols = 3;

  // define a pointer to a pointer (char for this example)
  // allocate an array of pointers (column major)
  char* letters = new char[cols * rows];
  
  // initialize
  loadary(letters, rows, cols);

  // use
  printary(letters, rows, cols);

  // release memory
  delete [] letters;
  letters = nullptr;
  rows = 0;
  cols = 0;
}

void loadary(char* ary, unsigned int rows, unsigned int cols) {
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
      ary[row * cols + col] = val;
      // alternatively *(ary + row * cols + col) = val;
    }
    cout << endl;
  }
}

void printary(const char* ary, unsigned int rows, unsigned int cols) {
  // must print with row in outer loop to match our mental model
  for (unsigned int row=0; row<rows; row++) {
    for (unsigned int col=0; col<cols; col++) {
      cout << ary[row * cols + col] << " ";
      // alternatively cout << *(ary +row * cols + col) << " ";
    }
    cout << endl;
  }
}