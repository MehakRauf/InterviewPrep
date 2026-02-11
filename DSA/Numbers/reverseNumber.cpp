#include <iostream>
#include <climits>

using namespace std;

int reverseNumber(int a)
{
    int ans = 0;
    while (a != 0)
    {
        int rem = a % 10;
        if (ans > INT_MAX / 10 || ans < INT_MIN)
        {
            return 0;
        }
        ans = (ans * 10) + rem;
        a /= 10;
    }
    return ans;
}

int main()
{
    int ans = reverseNumber(123);
    cout << ans << endl;
}