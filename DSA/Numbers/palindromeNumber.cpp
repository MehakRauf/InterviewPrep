#include <iostream>

using namespace std;

int reverseNumber(int n)
{
    int ans = 0;
    while (n != 0)
    {
        int rem = n % 10;
        ans = (ans * 10) + rem;
        n /= 10;
    }

    cout << ans << endl;
    return ans;
}

bool isPalindrome(int n)
{
    if (n == reverseNumber(n))
    {
        return true;
    }
    return false;
}

int main()
{
    cout << isPalindrome(3532) << endl;
    return 0;
}