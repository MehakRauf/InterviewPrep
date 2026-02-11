#include <iostream>

using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        int rem = n % 10;
        count++;
        n /= 10;
    }
    return count;
}

void printDigits(int n)
{
    while (n != 0)
    {
        int rem = n % 10;
        cout << rem << " ";
        n /= 10;
    }
    cout << endl;
}

int sumOfDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int rem = n % 10;
        sum += rem;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n = 12345;
    cout << countDigits(n) << endl;
    cout << sumOfDigits(n) << endl;
    printDigits(n);
    return 0;
}