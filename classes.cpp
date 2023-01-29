#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

class Person {
  public:
    Person(std::string name, int year) : name(name), yearOfBirth(year), ss(std::ios_base::out) {}
    std::string getName() const { return name; }
    int getYearOfBirth() const { return yearOfBirth; }
    virtual std::string toString() const { 
      ss.str("");
      ss << "Name: " << name << ", Year of Birth: " << yearOfBirth;
      return ss.str();
    }
    bool equals(const Person &p) const { 
      return name == p.name && yearOfBirth == p.yearOfBirth; 
    }

  private:
    std::string name;
    int yearOfBirth;
    mutable std::stringstream ss;
};



class Student : public Person {
  public:
    Student(std::string name, int year, std::string major) 
      : Person(name, year), major(major) {}
    std::string getMajor() const { return major; }
    std::string toString() const override { 
      return Person::toString() + ", Major: " + major;
    }
    bool equals(const Student &s) const { 
      return Person::equals(s) && major == s.major; 
    }

  private:
    std::string major;
};

class Instructor : public Person {
  public:
    Instructor(std::string name, int year, int salary) 
      : Person(name, year), salary(salary) {}
    int getSalary() const { return salary; }
    std::string toString() const override { 
      return Person::toString() + ", Salary: ";// + std::to_string(salary);
    }
    bool equals(const Instructor &i) const { 
      return Person::equals(i) && salary == i.salary; 
    }

  private:
    int salary;
};

int main() {
  Person p("John Doe", 1990);
  Student s("Jane Doe", 1995, "Computer Science");
  Instructor i("Bob Smith", 1980, 100000);

  std::cout << p.toString() << std::endl;
  std::cout << s.toString() << std::endl;
  std::cout << i.toString() << std::endl;

  std::cout << "p and s are equal: " << (p.equals(s) ? "True" : "False") << std::endl;
  std::cout << "s and s are equal: " << (s.equals(s) ? "True" : "False") << std::endl;
  std::cout << "i and i are equal: " << (i.equals(i) ? "True" : "False") << std::endl;

  return 0;
}

