#include <iostream>

using namespace std;

// Divide a number into two halves and add both the halves to an array.
// If the number is odd, add the largest half to the right side of the array.
// For example: Input: 10 Result: [5,5] Input: 11 Result: [5,6]

void twoHalves(int n)
{
    int arr[2];
    int n1 = n / 2, n2 = n - n1;
    arr[0] = n1;
    arr[1] = n2;
    cout << arr[0] << " " << arr[1] << endl;
}

int main()
{
    twoHalves(21);
    return 0;
}