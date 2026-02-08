#include <iostream>
using namespace std;

int decimalToBinary(int n)
{
    int ans = 0, pow = 1;
    while (n > 0)
    {
        int rem = n % 2;
        n = n / 2;
        ans += rem * pow;
        pow *= 10;
    }
    return ans;
}

int binaryToDecimal(int n)
{
    int ans = 0, pow = 1;
    while (n > 0)
    {
        int rem = n % 10;
        n = n / 10;
        ans += rem * pow;
        pow *= 10;
    }
    return ans;
}
int main()
{
    // for (int i = 0; i <= 10; i++)
    // {
    //     cout << decimalToBinary(i) << endl;
    // }
    cout<<binaryToDecimal(6)<<endl;
    return 0;
}