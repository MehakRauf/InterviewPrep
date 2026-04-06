#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> s;

void push(int val)
{
    if (s.empty())
    {
        s.push({val, val});
    }
    else
    {
        int minVal = min(val, s.top().second);
        s.push({val, minVal});
    }
}

int top()
{
    return s.top().first;
}

void pop()
{
    s.pop();
}

int minValue()
{
    return s.top().second;
}

int main()
{
    return 0;
}