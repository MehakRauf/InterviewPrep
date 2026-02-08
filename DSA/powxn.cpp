#include <iostream>
using namespace std;

double power(int x, int n)
{
    long binaryForm = n;
    double ans = 1;
    while (binaryForm > 0)
    {
        if (binaryForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binaryForm /= 2;
    }
    return ans;
}

int main()
{
    cout << power(2, 4) << endl;
    return 0;
}