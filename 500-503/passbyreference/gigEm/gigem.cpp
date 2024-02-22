#include <iostream>

using std::cout, std::endl;

int em(int a, int b) {
   int k = 3;
   int whoop = a + b + k;
   return whoop;
}

int gig(int rev) {
   int howdy = 4;
   return em(rev, howdy);
}

int main() {
   int twelfthMan = gig(em(1, 2));
   cout << "twelfthMan: " << twelfthMan << endl;
}