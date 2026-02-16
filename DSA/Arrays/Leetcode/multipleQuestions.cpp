#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s.
// The maximum number of consecutive 1s is 3.

int maxConsecutiveOnes(vector<int> arr)
{
    int count = 0, maxCount = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.

int islandPerimeter(vector<vector<int>> grid)
{
    int perimeter = 0, n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                if (i == 0 || grid[i - 1][j])
                    perimeter++;
                if (i == n - 1 || grid[i + 1][j])
                    perimeter++;
                if (j == 0 || grid[i][j - 1])
                    perimeter++;
                if (j == m - 1 || grid[i][j + 1])
                    perimeter++;
            }
        }
    }
    return perimeter;
}

int main()
{
    return 0;
}