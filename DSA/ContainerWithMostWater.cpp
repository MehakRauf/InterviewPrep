#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxArea(vector<int> height)
{
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r)
    {
        int ht = min(height[l], height[r]), width = r - l;
        int area = ht * width;
        ans = max(area, ans);
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return ans;
}

int maxAreaBrute(vector<int> height)
{
    int ans = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int width = j - i, ht = min (height[i], height[j]);
            int area = width * ht;
            ans = max(area, ans);
        }
    }
    return ans;
}
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxAreaBrute(height) << endl;
    return 0;
}