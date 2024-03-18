#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

// a Pixel struct representing a single red, green, blue pixel value for an image
struct Pixel {
  unsigned int r = 0; // red
  unsigned int g = 0; // green
  unsigned int b = 0; // blue
};

///////////////////////////////////////////////////////////////////////////////
// create / delete image on heap

void makeImage(Pixel**& image, unsigned int width, unsigned int height);

void releaseImage(Pixel**& image, unsigned int& width, unsigned int& height);

///////////////////////////////////////////////////////////////////////////////
// Image modification functions

void loadImage(const std::string filename, Pixel**& image, unsigned int& width, unsigned int& height);

void saveImage(const std::string filename, const Pixel*const* image, unsigned int width, unsigned int height);

void grayscaleFilter(Pixel** image, unsigned int width, unsigned int height);

void doubleImage(Pixel**& image, unsigned int& width, unsigned int& height);

void halveImage(Pixel**& image, unsigned int& width, unsigned int& height);

void crop(Pixel**& image, unsigned int& width, unsigned int& height, unsigned int startCol, unsigned int startRow, unsigned int newWidth, unsigned int newHeight);

void noiseFilter(std::string src1, std::string src2, std::string src3, Pixel**& image, unsigned int& width, unsigned int& height);

///////////////////////////////////////////////////////////////////////////////
// IO functions

void printMenu();

void processLoad(Pixel**& image, unsigned int& width, unsigned int& height);

void processSave(const Pixel*const* image, unsigned int width, unsigned int height);

void processCrop(Pixel**& image, unsigned int& width, unsigned int& height);

void processFilter(Pixel**& image, unsigned int& width, unsigned int& height);

unsigned int getInteger(const std::string label, unsigned int min, unsigned int max);

///////////////////////////////////////////////////////////////////////////////
// helper functions

void mySwap(unsigned int& a, unsigned int& b);

unsigned int getMedian(unsigned int a, unsigned int b, unsigned int c);


#endif