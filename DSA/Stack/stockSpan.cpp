#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> stockSpan(vector<int> prices)
{
    vector<int> ans(prices.size(), 0);
    stack<int> st;

    for (int i = 0; i < prices.size(); i++)
    {
        while (st.size() > 0 && prices[st.top()] <= prices[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - st.top();
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stockSpan(prices);
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}