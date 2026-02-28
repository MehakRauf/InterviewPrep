#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());

    return s == s2;
}

void getAllParts(string s, vector<vector<string>> &ans, vector<string> &partitions)
{
    if (s.length() == 0)
    {
        ans.push_back(partitions);
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        string part = s.substr(0, i + 1);
        if (isPalindrome(part))
        {
            partitions.push_back(part);
            getAllParts(s.substr(i + 1), ans, partitions);
            partitions.pop_back();
        }
    }
}

vector<vector<string>> palindromePartition(string s)
{
    vector<vector<string>> ans;
    vector<string> partitions;

    getAllParts(s, ans, partitions);
    return ans;
}

int main()
{
    string s = "aab";
    vector<vector<string>> ans = palindromePartition(s);
    for (auto values : ans)
    {
        for (auto val : values)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}