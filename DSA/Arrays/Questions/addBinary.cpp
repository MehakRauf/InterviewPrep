#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    string result = "";
    while (i >= 0 || j >= 0 || carry)
    {
        int n1 = (i >= 0) ? a[i] - '0' : 0;
        int n2 = (j >= 0) ? b[j] - '0' : 0;

        int sum = n1 + n2 + carry;
        carry = sum / 2;
        result += (sum % 2) + '0';

        i--; j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s1 = "11", s2 = "1";
    cout << addBinary(s1, s2) << endl;

    return 0;
}