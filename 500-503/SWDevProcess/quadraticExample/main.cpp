#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl; 

// function declarations
void outputEquation(double a, double b, double c);
void processLinear(double b, double c);
void processQuadratic(double a, double b, double c);
void processImaginary(double disc, double a, double b, double c);
void processReal(double disc, double a, double b, double c);
bool isSolution(double a, double b, double c, double xReal, double xImag);

/**
Output prompt
Input coefficients (a, b, c)
Output equation (a, b, c)
If (a = 0 and b = 0)
Output “Unable to determine roots”
Else
If a = 0
processLinear
Else
processQuadratic
*/

int main() {
    cout << "Input coefficients a, b, and c: ";
    double a=0, b=0, c=0;
    cin >> a >> b >> c;
    outputEquation(a, b, c);
    if (a == 0 && b == 0) {
        cout << "Unable to determine roots" << endl;
    }
    else if (a==0) {
        processLinear(b, c);
    }
    else {
        processQuadratic(a, b, c);
    }

  
}

void outputEquation(double a, double b, double c) {
    if (a != 0) {
        cout << a << "x^2 + ";
    }
    cout << b << "x + ";
    cout << c << " = 0" << endl;
}

void processLinear(double b, double c) {
    cout << "x = " << (-c/b) << endl;
}

void processQuadratic(double a, double b, double c) {
    /*
    Assign disc to b*b - 4*a*c
````If disc is negative
        processImaginary
    Else (includes 0)
        processReal
    */
   double disc = b*b - 4*a*c;
   if (disc < 0) {
    processImaginary(disc, a, b, c);
   }
   else { // disc >= 0
    processReal(disc, a, b, c);
   }
}

void processReal(double disc, double a, double b, double c) {
    /*Assign x1 to (b*b + sqrt(disc))/(2*a)
Output “x = “x1
If disc not equal to 0
Assign x2 to  (b*b - sqrt(disc))/(2*a)
Output “x = “x2
*/
    double x1 = (b*b + sqrt(disc)/(2*a));
    cout << "x = " << x1 << endl;
    if (disc != 0) {
        double x2 = (b*b - sqrt(disc)/(2*a));
        cout << "x = " << x2 << endl;
    }
}

void processImaginary(double disc, double a, double b, double c) {
    /*Assign disc to disc*-1
Assign x1real to b*b/(2*a)
Assign x1img to sqrt(disc)/(2*a)
Output “x = “x1real” + “x1img”i”
Output “x = “x1real” - “x1img”i”
*/
    disc = fabs(disc);
    double real = b*b/(2*a);
    double img = sqrt(disc)/(2*a);
    cout << "x = " << real << " + " << img << "i" << endl;
    cout << "x = " << real << " - " << img << "i" << endl;


}

bool isSolution(double a, double b, double c, double xReal, double xImag) {
    double real = a*xReal*xReal - a*xImag*xImag + b*xReal + c;
    double imag = -2*a*xReal*xImag - b*xImag;
    if (fabs(real + imag) < 0.00000001) {
        cout << "is a solution";
    }
    else {
        cout << "not a soluction";
    }
    cout << endl;
}