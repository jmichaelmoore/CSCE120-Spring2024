#include <iostream>

using std::cout, std::endl;

int main(int argc, char *argv[]) { // sometimes you'll see (int argc, char** argv)
  // argc: number of cstrings, argv: array of cstrings
  cout << "executable: " << argv[0] << endl;
  // print remaining parameters in reverse order
  for (unsigned int i=argc-1; i>0; --i) {
    cout << argv[i] << " ";
  }
  cout << endl;
}