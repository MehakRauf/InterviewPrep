#include <iostream>
using namespace std;

void digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int n1 = n % 10;
        sum += n1;
        n = n / 10;
    }
    cout << sum << endl;
}

int fac(int n)
{
    int fac = 1;
    for (int i = 2; i <= n; i++)
    {
        fac *= i;
    }
    return fac;
}

void nCr(int n, int r)
{
    int nrfac = fac((n - r));
    int nfac = fac(n);
    int rfac = fac(r);

    int ncr = nfac / (rfac * nrfac);
    cout << ncr << endl;
}

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void printPrime(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void printFabonacciSeries(int n)
{
    int a = 0, b = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << a << " " ;
        int c = a + b;
        a = b;
        b = c;
    }
}
int main()
{
    printFabonacciSeries(7);
    return 0;
}