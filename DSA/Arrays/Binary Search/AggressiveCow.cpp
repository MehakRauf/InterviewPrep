#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int cows, int n, int maxPossible)
{
    int c = 1, position = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - position) > maxPossible)
        {
            c++;
            maxPossible = arr[i];
        }
        if (c == cows)
        {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> arr, int cows, int n)
{
    sort(arr.begin(), arr.end());
    int st = 0, end = arr[n - 1] - arr[0], ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(arr, cows, n, mid))
        {
            st = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
}
int main()
{
    vector<int> arr = {1, 2, 8, 4, 9};
    int n = arr.size();
    int c = 3; // no. of cows
    cout << aggressiveCows(arr, c,n) << endl;
    return 0;
}