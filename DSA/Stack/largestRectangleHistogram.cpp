#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int largestRectangle(vector<int> heights)
{
    int maxArea = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int height = INT_MAX;
        for (int j = i; j < heights.size(); j++)
        {
            height = min(height, heights[j]);
            int width = j - i + 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int main()
{
    cout << largestRectangle({2, 1, 5, 6, 2, 3}) << endl;
    return 0;
}