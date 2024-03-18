#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>
#include <string>
#include "functions.h"

using std::cin, std::cout, std::endl;
using std::numeric_limits, std::streamsize;
using std::ofstream, std::ifstream;
using std::string;

///////////////////////////////////////////////////////////////////////////////
// create / delete image on heap

/*
  Create image on the heap of the appropriate size.
  If there is an existing image pointed to, 
  release that memory before creating new image
*/
void makeImage(Pixel**& image, unsigned int width, unsigned int height) {
  // should check width and height before making
  image = new Pixel*[width];
  for (unsigned int col=0; col<width; ++col) {
    image[col] = new Pixel[height];
  }
}

/*
  Release all memory from the heap and update variables to represent an empty image
*/
void releaseImage(Pixel**& image, unsigned int& width, unsigned int& height) {
  for (unsigned int col=0; col<height; ++col) {
    delete [] image[col];
  }
  delete [] image;

  image = nullptr;
  width = 0;
  height = 0;
}

///////////////////////////////////////////////////////////////////////////////
// Image processing functions

/*
  Load image
  If image points to an existing image, 
  then release old image before creating new image
*/
// You should complete this function. //
void loadImage(const string filename, Pixel**& image, 
               unsigned int& width, unsigned int& height)
{
  cout << "Loading image..." << endl;
  ifstream ifs(filename); // input file stream opened with filename 

  // check if it's open
  if (!ifs.is_open()) {
    throw std::invalid_argument("Unable to open file: " + filename);
  }

  // we were able to open the file

  // TODO: release old memory
  releaseImage(image, width, height);

  // read in Image type, for us it must be P3
  string type;
  ifs >> type;

  // read in width and height
  ifs >> width >> height;
  if (width == 0 || height == 0) {
    throw std::invalid_argument("File width or height is invalid.");
  }

  // read in maximum color value, for us it must be 255
  unsigned int maxColor = 0;
  ifs >> maxColor;

  // TODO: allocate memory for an image (an existing function might help)
  makeImage(image, width, height);

  // read the color values into the 2D array in Column Major Order
  for (unsigned int row=0; row<height; ++row) {
    for (unsigned int col=0; col<width; ++col) {
      ifs >> image[col][row].r;
      ifs >> image[col][row].g;
      ifs >> image[col][row].b;
    }
  }
}

void saveImage(const string filename, const Pixel*const* image, unsigned int width, unsigned int height)
{
  cout << "Saving image..." << endl;

  // open output file
  ofstream ofs(filename);

  if (!ofs.is_open()) {
    throw std::invalid_argument("Unable to create output file: " + filename);
  }

  // output image type, P3 for us
  ofs << "P3" << endl;

  // output width and height, don't forget to separate by a space
  ofs << width << " " << height << endl;

  // output max color value, for us 255
  ofs << 255 << endl;

  // output from column major order array into row major PPM file
  for (unsigned int row=0; row<height; ++row) {
    for (unsigned int col=0; col<width; ++col) {
      ofs << image[col][row].r << " ";
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
    ofs << endl;
  }
}

void grayscaleFilter(Pixel** image, unsigned int width, unsigned int height)
{
  cout << "Converting image to grayscale... " << endl;
  // iterate through 2d image of Pixels and convert them to grayscale
  // use opposite outer loop than load and output just to be different
    for (unsigned int col=0; col<width; ++col) {
    for (unsigned int row=0; row<height; ++row) {
      unsigned int newColor = (image[col][row].r + image[col][row].g + image[col][row].b)/3;
      image[col][row] = {newColor, newColor, newColor};
    }
  }
 }

/*
  create a new image with twice the number of rows and columns
  hint: a type of resize
  during copy into a larger image. Each pixel should be mapped to the
  corresponding value at half of its location 
  (note that integer division allows this to work)
*/
void doubleImage(Pixel**& image, unsigned int& width, unsigned int& height) {
}

/*
  create a new image with half the number of rows and columns
  hint: a type of resize & analagous to doubleImage
  during copy into a larger image. Each pixel should be mapped to the
  corresponding value at twice its location 
  (note that integer division allows this to work)
*/
void halveImage(Pixel**& image, unsigned int& width, unsigned int& height) {
}

/*
  make a smaller image based on 
  new coordinate for upper left corner and new width and height
  throw invalid_argument exceptions 
    if startCol, startRow, newWidth, or newHeight are invalid
*/
void crop(Pixel**& image, unsigned int& width, unsigned int& height, unsigned int startCol, unsigned int startRow, unsigned int newWidth, unsigned int newHeight) {
}

/*
  load three image files
  if an existing image is passed in, release before creating new image
  if any of the dimensions of the new images do not match, 
    throw an invalid_argument exception
*/
void noiseFilter(string file1, string file2, string file3, Pixel**& image, unsigned int& width, unsigned int& height) {
}

///////////////////////////////////////////////////////////////////////////////
// IO functions

/*  Function printMenu
 *  Return value: none
 */
// You should not modify this function. //
void printMenu()
{
  cout << "----------------------------------" << endl;
  cout << " L: Load Image" << endl;
  cout << " S: Save Image" << endl;
  cout << " X: Load Image removing noise" << endl;
  cout << " G: Greyscale image" << endl;
  cout << " D: Double image" << endl;
  cout << " H: Halve image" << endl;
  cout << " C: Crop Image" << endl;
  cout << " F: Filter Image" << endl;
  cout << " Q: Quit" << endl;
  cout << "----------------------------------" << endl;
  cout << endl
       << "Please enter your choice: ";
}

void processLoad(Pixel**& image, unsigned int& width, unsigned int& height) {
  if (image != nullptr || width == 0 || height == 0) {
    releaseImage(image, width, height);
  }

  string filename;

  // get filename from user
  cout << "Input filename to load: ";
  cin >> filename;

  loadImage(filename, image, width, height);
}

void processSave(const Pixel*const* image, unsigned int width, unsigned int height) {
   string filename;

  // get filename from user
  cout << "Input filename to save: ";
  cin >> filename;

  saveImage(filename, image, width, height);
}

void processFilter(Pixel**& image, unsigned int& width, unsigned int& height) {
  string source1, source2, source3, result;
  cout << "Input filename for 3 files to filter noise..." << endl;

  cout << "Input first filename to process:  ";
  cin >> source1;
  cout << "Input second filename to process:  ";
  cin >> source2;
  cout << "Input third filename to process:  ";
  cin >> source3;

  noiseFilter(source1, source2, source3, image, width, height);
}

void processCrop(Pixel**& image, unsigned int& width, unsigned int& height) {
  unsigned int newWidth = 0;
  unsigned int newHeight = 0;
  unsigned int col = 0;
  unsigned int row = 0;
  cout << "Location of the upper left hand corner:" << endl;
  row = getInteger("   Input row:  ", 0, height-1);
  col = getInteger("   Input column: ", 0, width-1);

  newWidth = getInteger("Input the new width: ", 1, height-row-1);
  newHeight = getInteger("Input the new height: ", 1, width-col-1);

  crop(image, width, height, col, row, newWidth, newHeight);
}

unsigned int getInteger(const string label, unsigned int min, unsigned int max)
{
  // get value from user repeatedly until input matches requirements
  unsigned int num = 0;
  do
  {
    cin.clear();                                         // reset stream states
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

    cout << "Please enter " << label << " (" << min << " - " << max << "): ";
    cin >> num;
  } while (!cin.good() || num < min || num > max); // while input does not match requirements
  return num;
}

///////////////////////////////////////////////////////////////////////////////
// helper functions

void mySwap(unsigned int& a, unsigned int& b) {
    unsigned int temp = a;
    a = b;
    b = temp;
}

unsigned int getMedian(unsigned int a, unsigned int b, unsigned int c) {
    // sort local copies, hint: use mySwap
    // only need three if statements
    // return middle value (i.e. b)
    return 0;
}
