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

void processQuadratic(double a, double b, double c) {
    double disc = b*b - 4*a*c;
    if (disc < 0) {
        processImaginary(disc, a, b, c);
    }
    else {  // >= 0
        processReal(disc, a, b, c);
    }
}

void processImaginary(double disc, double a, double b, double c) {
    /*Assign disc to disc*-1
Assign real to -b/(2*a)
Assign imag to sqrt(disc)/(2*a)
Output “x = “real” - “imag”i”
Output “x = “real” + “imag”i”
*/
    disc = fabs(disc);
    double real = -b/(2*a);
    double imag = sqrt(disc)/(2*a);
    cout << "x = " << real << " - " << imag << "i" << endl;
    cout << "x = " << real << " + " << imag << "i" << endl;
    if (isSolution(a, b, c, real, imag)) {
        cout << "valid solution" << endl;
    }
    else {
        cout << "invalid solution" << endl;
    }
}

void processReal(double disc, double a, double b, double c) {
    /*Assign x1 to (-b - sqrt(disc))/(2*a)
Output “x = “x1
If disc not equal 0
Assign x2 to  (-b + sqrt(disc))/(2*a)
Output “x = “x2
*/
    double x1 = (-b - sqrt(disc))/(2*a);
    cout << "x = " << x1 << endl;
    if (isSolution(a, b, c, x1, 0)) {
        cout << "valid solution" << endl;
    }
    else {
        cout << "invalid solution" << endl;
    }
    if (disc != 0) {
        double x2 = (-b + sqrt(disc))/(2*a);
        cout << "x = " << x2 << endl;
        if (isSolution(a, b, c, x2, 0)) {
            cout << "valid solution" << endl;
        }
        else {
            cout << "invalid solution" << endl;
        }
    }
}

void processLinear(double b, double c) {
    cout << "x = " << -c/b << endl;
}

bool isSolution(double a, double b, double c, double xReal, double xImag) {
    double real = a*xReal*xReal - a*xImag*xImag + b*xReal + c;
    double imag = -2*a*xReal*xImag - b*xImag;
    double sum = real + imag;
    cout << "sum: " << sum << endl;
    if (abs(sum) < 0.000000001) {
        return true;
    }
    else {
        return false;
    }
}