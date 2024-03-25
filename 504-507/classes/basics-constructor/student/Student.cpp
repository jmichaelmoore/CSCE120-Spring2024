#include "Student.h"
#include <cstdio>
#include <iostream>

using std::string, std::cout;

Student::Student(int _uin){ //Pre-C++11
  this->uin = _uin;
  this->name = "Joe Bloggs";
}

Student::Student(string _name){ //Dropped implicit "this"
  name = _name;
  uin = 0;
}

Student::Student(string name, int uin): name(name), uin(uin) {} //Member initialization list

Student::Student() { //Default constructor (do we want this?)
  name = "";
  uin = 0;
}

int main(){

  auto Student1 = Student("Alice", 1234);
  auto Student2 = Student("Bob");
  Student Student3 = Student(5678);
  Student Student4 = Student();
  /* 
  cout << "My name is" << Student1.name << "and my UIN is" << Student1.uin << "\n";
  cout << "My name is" << Student2.name << "and my UIN is" << Student2.uin << "\n";
  cout << "My name is" << Student3.name << "and my UIN is" << Student3.uin;
  */
  cout << "My name is " << Student1.getName() << " and my UIN is " << Student1.getUIN() << "\n";
  cout << "My name is " << Student2.getName() << " and my UIN is " << Student2.getUIN() << "\n";
  cout << "My name is " << Student3.getName() << " and my UIN is " << Student3.getUIN() << "\n";
  cout << "My name is " << Student4.getName() << " and my UIN is " << Student4.getUIN();
  return 0;
}

