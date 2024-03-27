#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
private: // optional here since classes are private by default

  unsigned short red;
  unsigned short green;
  unsigned short blue;

public:
    //parameterized constructor with r, g, & b values passed in
    //copy constructor with Pixel passed in
    //default constructor ? What to set r, g & b values to?

  Pixel(unsigned short red, unsigned short green, unsigned short blue);
  Pixel() : red(0), green(0), blue(0) {};

  unsigned short int getRed() { return red; }
  unsigned short int getGreen() { return green; }
  unsigned short int getBlue() { return blue; }

  void setRed(unsigned short int );
  void setGreen(unsigned short int );
  void setBlue(unsigned short int );

};

#endif