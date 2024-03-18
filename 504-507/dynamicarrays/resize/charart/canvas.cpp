#include <iostream>
#include <stdexcept>
#include <sstream>
#include "canvas.h"

using std::cin, std::cout, std::endl;

void addCharacter(char c, unsigned int row, unsigned int col, char**& canvas, unsigned int& width, unsigned int& height) {
  cout << "addCharacter" << endl;
  if (!isprint(c)) {
    throw std::invalid_argument("Character must be printable");
  }
  if (row >= MAX_HEIGHT) {
    std::ostringstream oss;
    oss << "row must be less than " << MAX_HEIGHT <<", you entered " << row;
    throw std::invalid_argument(oss.str());
  }
  if (col >= MAX_WIDTH) {
    std::ostringstream oss;
    oss << "col must be less than " << MAX_WIDTH <<", you entered " << col;
    throw std::invalid_argument(oss.str());
  }
  // if we make it this far we know that row and col are valid values and c is printable

  // check if location is available in current size
  unsigned int newWidth = width;
  unsigned int newHeight = height;
  bool resize = false;
  if (row >= height) {
    newHeight = row + 1;
    resize = true;
  }
  if (col >= width) {
    newWidth = col + 1;
    resize = true;
  }
  // if it isn't resize
  if (resize) {
    resizeCanvas(canvas, width, height, newWidth, newHeight);
  }
  // regardless, add the character to the correct location.
  canvas[row][col] = c;
}

char** makeCanvas(unsigned int width, unsigned int height) {
  // allocate on heap and initialize with ' ' spaces
  // row major
  cout << "makeCanvas" << endl;
  char** canvas = nullptr;
  canvas = new char*[height];
  for (unsigned int row=0; row<height; ++row) {
    canvas[row] = new char[width];
    for (unsigned int col=0; col<width; ++col) {
      canvas[row][col] = ' ';
    }
  }
  return canvas;
}

void resizeCanvas(char**& canvas, unsigned int& width,  unsigned int& height, unsigned int newWidth, unsigned int newHeight) {
  cout << "resizeCanvas" << endl;
  // make new array
  char** newCanvas = makeCanvas(newWidth, newHeight);

  // copy
  unsigned int w = newWidth;
  if (width < w) w = width;
  unsigned int h = newHeight;
  if (height < h) h = height;

  for (unsigned int row = 0; row<h; ++row) {
    for (unsigned int col=0; col<w; ++col) {
      newCanvas[row][col] = canvas[row][col];
    }
  }

  // delete old memory
  releaseCanvas(canvas, width, height);

  // update
  canvas = newCanvas;
  width = newWidth;
  height = newHeight;
  newCanvas = nullptr;
}

void releaseCanvas(char**& canvas, unsigned int& width, unsigned int& height) { 
  cout << "releaseCanvas" << endl;
  // row major
  for (unsigned int row=0; row<height; ++row) {
    delete [] canvas[row];
  }
  delete [] canvas;

  canvas = nullptr;
  width = 0;
  height = 0;
}

void printCanvas(const char*const* canvas, unsigned int width, unsigned int height) {
  cout << "printCanvas" << endl;
  for (unsigned int row=0; row<height; ++row) {
    for (unsigned int col=0; col<width; ++col) {
      cout << canvas[row][col];
    }
    cout << endl;
  }
}