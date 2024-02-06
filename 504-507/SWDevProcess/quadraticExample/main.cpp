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