#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
using namespace std;

int main (int argc, char * argv[])
{
    HourlyEmployee h1("Jill", "Williamson", 20.0, 40);
    cout << h1 << endl;
    SalariedEmployee s1("Jack", "Smith", 40000);
    cout << s1 << endl;
//    Employee e1("Michael", "Smith");
//    cout << e1 << endl;
    cout << endl;

    vector<Employee*> employees;
    employees.push_back(&h1);
    employees.push_back(&s1);
//    employees.push_back(&e1);
    for (int i = 0; i < employees.size(); ++i) {
        string e = employees.at(i)->to_str();
        cout << "salary: " << employees.at(i)->get_annual_pay() << endl;
        cout << e << endl;
        cout << endl;
    }

    return 0;
}