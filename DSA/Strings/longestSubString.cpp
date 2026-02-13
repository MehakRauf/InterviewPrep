#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int maxLengthSubString(string str)
{
    unordered_set<char> ch;
    int maxLength = 0, st = 0;
    for (int end = 0; end < str.length(); end++)
    {
        while (ch.count(str[end]))
        {
            ch.erase(str[st]);
            st++;
        }
        ch.insert(str[end]);
        maxLength = max(maxLength, end - st + 1);
    }
    return maxLength;
}
int main()
{
    string str = "bbbbbbb";
    cout << maxLengthSubString(str) << endl;
    return 0;
}