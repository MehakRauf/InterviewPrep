#include <iostream>
#include <vector>

using namespace std;

int removeDups(vector<int> arr)
{
    int slow = 0;
    for (int fast = 1; fast < arr.size(); fast++)
    {
        if (arr[slow] != arr[fast])
        {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1;
}

int main()
{
    cout << removeDups({1, 1, 1, 2, 3, 3, 4, 4}) << endl;
    return 0;
}