#include <iostream>
#include "functions.h"

using namespace std;

int main() {
  // declare/define image 2d array of Pixels
  // would be too big for the stack, so 'static' puts it somewhere else but scope is still in main
  Pixel** image = nullptr;
  unsigned int width = 0;
  unsigned int height = 0;
  
  char menuChoice = ' '; // selected menu option
  cout << "Welcome to CSCE 120 Image Processing..." << endl << endl;
  do {
    printMenu();
    cin >> menuChoice;
    try {
      switch (toupper(menuChoice)) { // use toupper so user can input upper or lower case choices
        case 'L':
          processLoad(image, width, height);
          break;
        case 'S':
          processSave(image, width, height);
          break;
        case 'G':
          grayscaleFilter(image, width, height);
          break;
        case 'D':
          doubleImage(image, width, height);
          break;
        case 'H':
          halveImage(image, width, height);
          break;
        case 'C':
          processCrop(image, width, height);
          break;
        case 'F':
          processFilter(image, width, height);
          break;
        case 'Q': // does nothing but needed or default will execute
          break;
        default:
          cout << endl << "'" << menuChoice << "' is not a valid option'" << endl << endl;
      }
    }
    catch (std::exception &e) {
      cout << e.what() << endl;
    }
  } while (toupper(menuChoice) != 'Q'); // use toupper so user can input upper or lower case choices
  releaseImage(image, width, height);
}