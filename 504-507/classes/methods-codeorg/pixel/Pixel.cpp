#include "Pixel.h"
#include <stdexcept>

Pixel::Pixel(unsigned short red, unsigned short green, unsigned short blue) : 
red(red), green(green), blue(blue) {
    if(red > 255 || green > 255 || blue > 255){
    throw std::invalid_argument("Color outside of bounds");
    }
}

void Pixel::setRed(unsigned short int red) {
    if(red > 255) {
        throw std::invalid_argument("Color outside of bounds");
    }
    this->red = red;
  }

void Pixel::setGreen(unsigned short int green) {
    if(green > 255) {
        throw std::invalid_argument("Color outside of bounds");
    }
    this->green = green;
  }

void Pixel::setBlue(unsigned short int blue) {
    if(blue > 255) {
        throw std::invalid_argument("Color outside of bounds");
    }
    this->blue = blue;
  }
