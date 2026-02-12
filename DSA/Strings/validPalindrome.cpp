#include <iostream>
using namespace std;

int main()
{
    string s = "racecar";
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            cout << "The given string is not a valid palindrome" << endl;
            return 0;
        }
        i++;
        j--;
    }
    cout << "The given string is a valid palindrome!" << endl;
    return 0;
}