#include "Pixel.h"
#include <stdexcept>

void Pixel::setRed(unsigned short red) {
    if(red > 255) {
        throw std::invalid_argument("Color outside of bounds");
      }
    this->red = red;
  }

  void Pixel::setGreen(unsigned short green) {
    if(green > 255) {
        throw std::invalid_argument("Color outside of bounds");
      }
    this->green = green;
  }

  void Pixel::setBlue(unsigned short blue) {
    if(blue > 255) {
        throw std::invalid_argument("Color outside of bounds");
      }
    this->blue = blue;
  }


Pixel::Pixel(unsigned short red, unsigned short green, unsigned short blue) : 
  red(red), green(green), blue(blue) {
    if(red > 255 || green > 255 || blue > 255){
    throw std::invalid_argument("Color outside of bounds");
    }
}
