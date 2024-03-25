#include <stdexcept>
class Pixel {
private: // optional here since classes are private by default
  unsigned short red;
  unsigned short green;
  unsigned short blue;

public:
    //parameterized constructor with r, g, & b values passed in
    //copy constructor with Pixel passed in
    //default constructor ? What to set r, g & b values to?
    
    Pixel(unsigned short red, unsigned short green, unsigned short blue) :
      red(red), green(green), blue(blue) {
        if(red > 255 || green > 255 || blue > 255){
          throw std::invalid_argument("Invalid color");
        }
      };

    Pixel() : red(0), green(0), blue(0) {}

    Pixel(const Pixel& p) : red(p.red), green(p.green), blue(p.blue) {}
};
