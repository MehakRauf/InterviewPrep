#include <iostream>
using namespace std;

int fac(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fac(n - 1);
}

bool strongNumber(int n)
{
    int sum = 0, original = n;
    while (n != 0)
    {
        int rem = n % 10;
        sum += fac(rem);
        n = n / 10;
    }
    return (sum == original);
}

bool armStrongNumber(int n)
{
    int original = n, sum = 0;
    while (n != 0)
    {
        int rem = n % 10;
        sum += (rem * rem * rem);
        n /= 10;
    }
    return (original == sum);
}

int main()
{

    // cout << strongNumber(14);
    cout << armStrongNumber(12);
    return 0;
}