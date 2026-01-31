#include <iostream>
using namespace std;

// Function to find the largest of three fractions
void largestFraction(int &n1, int &d1,
                     int &n2, int &d2,
                     int &n3, int &d3,
                     int *&largestNum, int *&largestDen)
{
    // Assume first fraction is the largest
    largestNum = &n1;
    largestDen = &d1;

    // Compare second fraction
    if (n2 * (*largestDen) > (*largestNum) * d2)
    {
        largestNum = &n2;
        largestDen = &d2;
    }

    // Compare third fraction
    if (n3 * (*largestDen) > (*largestNum) * d3)
    {
        largestNum = &n3;
        largestDen = &d3;
    }
}

int main()
{
    int n1 = 1, d1 = 2;
    int n2 = 3, d2 = 4;
    int n3 = 2, d3 = 3;

    int *largestNum;
    int *largestDen;

    largestFraction(n1, d1, n2, d2, n3, d3, largestNum, largestDen);

    cout << "Largest fraction is: "
         << *largestNum << "/" << *largestDen << endl;

    return 0;
}
