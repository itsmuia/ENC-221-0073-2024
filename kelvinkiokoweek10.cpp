#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Employee
{
protected:
    string firstName;
    char initial;
    string lastName;

public:
    // Constructor
    Employee(string f, char i, string l)
        : firstName(f), initial(i), lastName(l) {}

    // Virtual destructor
    virtual ~Employee() {}

    // Pure virtual function
    virtual double getSalary() const = 0;

    // Concrete function
    string getFullName() const
    {
        return firstName + " " + initial + ". " + lastName;
    }
};

// Derived class: SalaryEmployee
class SalaryEmployee : public Employee
{
private:
    double monthlySalary;

public:
    SalaryEmployee(string f, char i, string l, double salary)
        : Employee(f, i, l), monthlySalary(salary) {}

    double getSalary() const override
    {
        return monthlySalary;
    }
};

// Derived class: HourlyEmployee
class HourlyEmployee : public Employee
{
private:
    int hoursWorked;
    double ratePerHour;

public:
    HourlyEmployee(string f, char i, string l, int hours, double rate)
        : Employee(f, i, l), hoursWorked(hours), ratePerHour(rate) {}

    double getSalary() const override
    {
        return hoursWorked * ratePerHour;
    }
};

// Application / Test
int main()
{
    // Base-class pointers (polymorphism)
    Employee *emp1 = new SalaryEmployee("John", 'A', "Doe", 50000);
    Employee *emp2 = new HourlyEmployee("Mary", 'B', "Smith", 160, 500);

    cout << "Employee: " << emp1->getFullName() << endl;
    cout << "Monthly Salary: " << emp1->getSalary() << endl
         << endl;

    cout << "Employee: " << emp2->getFullName() << endl;
    cout << "Monthly Salary: " << emp2->getSalary() << endl;

    delete emp1;
    delete emp2;

    return 0;
}
