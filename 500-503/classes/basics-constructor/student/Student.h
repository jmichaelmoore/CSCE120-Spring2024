#include <string>
#include <stdexcept>

class Student {
  
  private:
    
    std::string name;
    int uin;
  
  public:
    
    //Constructors
    Student(std::string name, int uin);
    Student(std::string name);
    Student(int uin);
    Student();

    //Methods
    std::string getName() const {
      return name;
    }

    int getUIN() const {
      return uin;
    }

};
