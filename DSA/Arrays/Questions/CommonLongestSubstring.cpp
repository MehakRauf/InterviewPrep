#include <iostream>
#include <vector>

using namespace std;

string commonLongestSubstring(vector<string> arr)
{
    string res = "", first = arr[0];
    bool match = false;

    for (int i = 0; i < first.length(); i++)
    {
        char ch = first[i];
        match = true;
        for (int j = 1; j < arr.size(); j++)
        {
            if (i >= arr[j].length() || arr[j][i] != ch)
            {
                match = false;
                break;
            }
        }
        if (!match)
        {
            break;
        }
        res += ch;
    }
    return res;
}

int main()
{
    vector<string> arr = {"Flaura", "Flower", "Flow"};
    string ans = commonLongestSubstring(arr);
    cout << ans;
}