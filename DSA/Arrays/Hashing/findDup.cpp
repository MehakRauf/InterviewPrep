#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int findDup(vector<int> arr)
{
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        if (s.find(arr[i]) != s.end())
        {
            return arr[i];
        }
        s.insert(arr[i]);
    }
    return -1;
}

int findDupOptimized(vector<int> arr)
{
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};
    int ans = findDupOptimized(arr);
    cout << ans << endl;
    return 0;
}