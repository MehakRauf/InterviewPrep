#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> board, int numberOfPainters, int numberOfBoards, int maxValue)
{
    int painterCount = 1, time = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] > maxValue)
        {
            return false;
        }
        if ((board[i] + time) <= maxValue)
        {
            time += board[i];
        }
        else
        {
            painterCount++;
            time = board[i];
        }
    }
    if (painterCount > numberOfPainters)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int painterPartition(vector<int> board, int numberOfPainters, int numberOfBoards)
{
    int total = 0;
    for (int i = 0; i < board.size(); i++)
    {
        total += board[i];
    }
    int st = 0, end = total, ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValid(board, numberOfPainters, numberOfBoards, mid))
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
    // vector<int> board = {40, 30, 10, 20}; // 60
    vector<int> board = {10, 10, 10, 10}; // 20
    int numberOfPainters = 2;
    cout << painterPartition(board, numberOfPainters, board.size());
    return 0;
}