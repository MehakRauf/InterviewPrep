#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> pages, int students, int books, int maxAllowed)
{
    int pageCount = 0, studentCount = 1;
    for (int i = 0; i < pages.size(); i++)
    {
        if (pages[i] > maxAllowed)
        {
            return false;
        }
        if ((pages[i] + pageCount) <= maxAllowed)
        {
            pageCount += pages[i];
        }
        else
        {
            studentCount++;
            pageCount = pages[i];
        }
    }
    if (studentCount > students)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int minPages(vector<int> pages, int students, int books)
{
    int sum = 0;
    for (int i = 0; i < pages.size(); i++)
    {
        sum += pages[i];
    }
    int st = 0, end = sum, ans = 0;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(pages, students, books, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}
int main()
{
    // vector<int> arr = {2, 1, 3, 4};
    vector<int> arr = {15, 17, 20};
    int students = 2;
    cout << minPages(arr, students, arr.size()) << endl;
    return 0;
}