#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    if (a == 0)
        return b;
    return a;
}

int lcm(int a, int b)
{
    int gcdValue = gcd(a, b);
    return (a * b) / gcdValue;
}

int main()
{
    int ans = lcm(20, 28);
    cout << ans << endl;
}