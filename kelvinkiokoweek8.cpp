#include <iostream>
using namespace std;

// Base class
class Square
{
protected:
    double side;

public:
    // Constructor
    Square(double s)
    {
        side = s;
    }

    // Destructor
    ~Square()
    {
        cout << "Square object destroyed" << endl;
    }

    // Member functions
    double getPeri()
    {
        return 4 * side;
    }

    double getArea()
    {
        return side * side;
    }
};

// Derived class
class Cube : public Square
{
public:
    // Constructor
    Cube(double s) : Square(s)
    {
    }

    // Destructor
    ~Cube()
    {
        cout << "Cube object destroyed" << endl;
    }

    // Surface area of the cube
    double getArea()
    {
        return 6 * side * side;
    }

    // Volume of the cube
    double getVolume()
    {
        return side * side * side;
    }
};

int main()
{
    Square sq(4);
    Cube cb(4);

    cout << "Square perimeter: " << sq.getPeri() << endl;
    cout << "Square area: " << sq.getArea() << endl;

    cout << "\nCube surface area: " << cb.getArea() << endl;
    cout << "Cube volume: " << cb.getVolume() << endl;

    return 0;
}
