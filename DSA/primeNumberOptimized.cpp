#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    bool isPrime = true;
    if (n == 2)
    {
        cout << "The number is a prime number." << endl;
        return 0;
    }
    for (int i = 2; i * i <= n; i++) // ignore the repititve values
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << "The number is a prime number." << endl;
    }
    else
    {
        cout << "The number is not a prime number." << endl;
    }
    return 0;
}