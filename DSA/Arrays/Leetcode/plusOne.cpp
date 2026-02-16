#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main()
{
    vector<int> ans = plusOne({1, 2, 3});
    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}