#include <iostream>

using std::cin, std::cout, std::endl, std::string;

// define a struct
struct name {
    string firstname = "";
    string lastname = "";
    char grade = 'F';
};

int main() {
    // declare / define a struct variable
    name aname;
    // assign values to elements of the struct
    //aname.firstname = "Michael";
    //aname.lastname = "Moore";
    aname = {"Michael", "Moore", 'B'};
    // access elements of the struct - i.e. print them
    cout << aname.firstname << " " << aname.lastname << ": " << aname.grade << endl;
}