 // define a class complex number
 //   has a real part and an imaginary part (make them double)
 // constructors
 //  - default
 //  - real and imagingary parameters
 //  - real parameter
 //  - imaginary parameter (not possible)
 //  - Complex parameter

 class Complex {
   double real;
   double imaginary;
public:

  Complex() : real(0.0), imaginary(0.0) {}
  Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}
  Complex(double real) : real(real), imaginary(0.0) {}
  Complex(const Complex& c) : real(c.real), imaginary(c.imaginary) {}
 };
