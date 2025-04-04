#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    std::string first_name, last_name;
};

struct HourlyEmployee: public Employee {
    double hourly_wage;
};

struct SalariedEmployee: public Employee {
    double annual_salary;
};

int main (int argc, char * argv[])
{

    HourlyEmployee he {"James", "Williams", 18.50};
    cout << "HourlyEmployee" << endl;
    cout << '\t' << he.first_name << ' ' << he.last_name << '\t' << he.hourly_wage << endl;

    SalariedEmployee sh {"Mary", "Smith", 134000};
    cout << "SalariedEmployee" << endl;
    cout << '\t' << sh.first_name << ' ' << sh.last_name << '\t' << sh.annual_salary << endl;

    return 0;

}