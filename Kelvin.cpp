#include <iostream>
#include <string>
using namespace std;
class myNeighbor {
public:
    string name;
    string nationality;
    string skinColour;
    string traits;
    string hobby;
    string Level_of_education;
    int age;
    float height;
};
int main() {

    myNeighbor neighbor;
    neighbor.name = "Joseph";
    neighbor.age = 21;
    neighbor.height = 6'1;
    neighbor.nationality = "Uganda";
    neighbor.traits = "hardworking,freindly amd jovial";
    neighbor.hobby = "swimming";
    neighbor.Level_of_education = "Diploma";
    cout << "My Neighbour:" << "\n";
    cout << "Name: " << neighbor.name << "\n";
    cout << "Age: " << neighbor.age << " years old" << "\n";
    cout << "Height: " << neighbor.height << " feet" << "\n";
    cout << "Nationality: " << neighbor.nationality << "\n";
    cout << "Personality: " << neighbor.traits<< "\n";
    cout << "Hobby: " << neighbor.hobby << "\n";
    cout << "Level_of_education: " << neighbor.Level_of_education << "\n";

    return 0;
};