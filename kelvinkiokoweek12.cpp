#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Student class
class Student
{
private:
    string regNo;
    string name;

public:
    Student(string r, string n) : regNo(r), name(n) {}

    string getRegNo() const { return regNo; }
    string getName() const { return name; }
};

// Course class
class Course
{
private:
    string code;
    string title;

public:
    Course(string c, string t) : code(c), title(t) {}

    string getCode() const { return code; }
    string getTitle() const { return title; }
};

// Department class (ASSOCIATION)
class Department
{
private:
    string deptName;
    vector<Student *> students;
    vector<Course *> courses;

public:
    Department(string name) : deptName(name) {}

    void addStudent(Student *s)
    {
        students.push_back(s);
    }

    void addCourse(Course *c)
    {
        courses.push_back(c);
    }

    void displayInfo() const
    {
        cout << "Department: " << deptName << endl;

        cout << "\nStudents:\n";
        for (auto s : students)
            cout << "- " << s->getName() << " (" << s->getRegNo() << ")" << endl;

        cout << "\nCourses:\n";
        for (auto c : courses)
            cout << "- " << c->getCode() << ": " << c->getTitle() << endl;
    }
};

// RegistrationService class (DEPENDENCY)
class RegistrationService
{
public:
    void registerStudent(Student &s, Course &c)
    {
        cout << "Registering " << s.getName()
             << " for course " << c.getCode() << endl;
    }
};

// Application / Test
int main()
{
    // Create department
    Department dept("Computer Science");

    // Create students
    Student s1("CS001", "Alice");
    Student s2("CS002", "Bob");

    // Create courses
    Course c1("CS101", "Programming I");
    Course c2("CS102", "Data Structures");

    // ASSOCIATION
    dept.addStudent(&s1);
    dept.addStudent(&s2);
    dept.addCourse(&c1);
    dept.addCourse(&c2);

    // Display department info
    dept.displayInfo();

    cout << "\n--- Registration ---\n";

    // DEPENDENCY
    RegistrationService reg;
    reg.registerStudent(s1, c1);
    reg.registerStudent(s2, c2);

    return 0;
}
