#include <iostream>
using namespace std;

int main()
{
    int n = 4, fac = 1;
    for (int i = 2; i <= n; i++)
    {
        fac *= i;
    }
    cout << fac << endl;

    return 0;
}