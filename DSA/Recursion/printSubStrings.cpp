#include <iostream>
#include <vector>

using namespace std;

void printSubStrings(vector<int> arr, vector<int> ans, int idx)
{
    if (idx == arr.size())
    {
        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[idx]);
    printSubStrings(arr, ans, idx + 1);
    ans.pop_back();
    printSubStrings(arr, ans, idx + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int idx = 0;
    vector<int> ans;
    printSubStrings(arr, ans, idx);
    return 0;
}