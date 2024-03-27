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

  unsigned short getRed() { return red; }
  unsigned short getGreen() { return green; }
  unsigned short getBlue() { return blue; }

  void setRed(unsigned short red);
  void setGreen(unsigned short green);
  void setBlue(unsigned short blue);
};

#endif