#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    bool isPrime = true;
    if (n == 2)
    {
        cout << "The number is a prime number." << endl;
        return 0;
    }
    for (int i = 2; i < n; i++)
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