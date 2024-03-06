#include <iostream>

using std::cin, std::cout, std::endl;

// char using column major ordering

void makeary(char**&, unsigned int rows, unsigned int cols);
void loadary(char**, unsigned int rows, unsigned int cols);
void printary(const char*const*, unsigned int rows, unsigned int cols);
void releaseary(char**&, unsigned int& rows, unsigned int& cols);

int main() {
  srand(time(NULL));

  // could read in rows and columns, but I'll hard code for this example
  unsigned int rows = 4;
  unsigned int cols = 3;
  char** ary = nullptr;

  // allocate memory
  makeary(ary, rows, cols);

  // initialize
  loadary(ary, rows, cols);

  // use
  printary(ary, rows, cols);

  // release memory
  releaseary(ary, rows, cols);
}

void makeary(char**& ary, unsigned int rows, unsigned int cols) {
  // declare variable (done in function signature)
  ary = nullptr;

  // create array of pointers for cols
  ary = new char*[cols];

  for (unsigned int col = 0; col < cols; ++col) {
    ary[col] = new char[rows];
  }
}

void loadary(char** ary, unsigned int rows, unsigned int cols) {
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
  }
}

void printary(const char*const* ary, unsigned int rows, unsigned int cols) {
  // must print with row in outer loop to match our mental model
  for (unsigned int row=0; row<rows; row++) {
    for (unsigned int col=0; col<cols; col++) {
      cout << ary[col][row] << " ";
    }
    cout << endl;
  }
}

void releaseary(char**& ary, unsigned int& rows, unsigned int& cols) {
  for (unsigned int col=0; col<cols; ++col) {
    delete [] ary[col];
    ary[col] = nullptr; // probably not needed but good practice
  }

  delete [] ary;

  ary = nullptr;
  rows = 0;
  cols = 0;
}