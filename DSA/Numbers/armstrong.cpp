#include <iostream>
using namespace std;

bool isArmstrong(int number)
{
    int sum = 0, original = number;
    while (number != 0)
    {
        int remainder = number % 10;
        sum += remainder * remainder * remainder;
        number /= 10;
    }
    if (sum == original)
    {
        return true;
    }
    return false;
}
int main()
{
    cout << isArmstrong(12) << endl;  // 0
    cout << isArmstrong(1) << endl;   // 1
    cout << isArmstrong(153) << endl; // 1
    cout << isArmstrong(371) << endl; // 1
    return 0;
}