#include <iostream>
#include <climits>
using namespace std;

bool isPowerOfTwo_Loop(int n)
{
    if (n < 0)
    {
        return false;
    }

    while (n % 2 == 0)
    {
        n = n / 2;
    }
    return n == 1;
}

bool isPowerOfTwo_Operators(int n)
{
    return (n > 0) && (n & (n - 1)) == 0;
}

int reverseInteger(int n)
{
    int value = 0;
    while (n > 0)
    {
        int rem = n % 10;
        value = value * 10 + rem;
        n = n / 10;
    }
    return value;
}

int reverseInteger_HandlingOverflow(int n)
{
    int value = 0;
    while (n > 0)
    {
        int rem = n % 10;
        // to handle overflows
        if (rem > INT_MAX || rem < INT_MIN)
        {
            return 0;
        }
        value = value * 10 + rem;
        n = n / 10;
    }
    return value;
}

int main()
{
    cout << reverseInteger(2095) << endl;
    cout << reverseInteger_HandlingOverflow(5106) << endl;

    cout << isPowerOfTwo_Loop(6) << endl;
    cout << isPowerOfTwo_Operators(8) << endl;
    return 0;
}