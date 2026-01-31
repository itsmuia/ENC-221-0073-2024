#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int numbers[20];
    int odd[20], even[20];
    int oddCount = 0, evenCount = 0;

    // Seed random number generator
    srand(time(0));

    // Fill array with random numbers between 1 and 100
    for (int i = 0; i < 20; i++)
    {
        numbers[i] = (rand() % 100) + 1;
    }

    // Separate odd and even numbers
    for (int i = 0; i < 20; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            even[evenCount++] = numbers[i];
        }
        else
        {
            odd[oddCount++] = numbers[i];
        }
    }

    // Display original array
    cout << "Original array:\n";
    for (int i = 0; i < 20; i++)
        cout << numbers[i] << " ";

    // Display even numbers
    cout << "\n\nEven numbers:\n";
    for (int i = 0; i < evenCount; i++)
        cout << even[i] << " ";

    // Display odd numbers
    cout << "\n\nOdd numbers:\n";
    for (int i = 0; i < oddCount; i++)
        cout << odd[i] << " ";

    return 0;
}
