#include <iostream>
using namespace std;

bool isAlphaNumeric(char c)
{
    if ((c >= '0' && c <= '9') || (tolower(c) >= 'a' && tolower(c) <= 'z'))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    int st = 0, end = s.length() - 1;
    while (st < end)
    {
        if (!isAlphaNumeric(s[st]))
        {
            st++;
            continue;
        }
        if (!isAlphaNumeric(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end]))
            return false;
        st++;
        end--;
    }
    return true;
}

int main()
{
    string S = "Ac3?e3c&a";
    cout << isPalindrome(S) << endl;
    return 0;
}