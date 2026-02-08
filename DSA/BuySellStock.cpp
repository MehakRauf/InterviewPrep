#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxProfit(vector<int> prices)
{
    int bestBuy = prices[0], maxProf = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > bestBuy)
        {
            maxProf = max(maxProf, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProf;
}

int main()
{
    // vector<int> prices = {7, 1, 5, 3, 6, 4};  // 5
    vector<int> prices = {7, 6, 4, 3, 1}; //0

    cout << maxProfit(prices) << endl;
    return 0;
}