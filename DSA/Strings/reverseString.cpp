#include <iostream>
using namespace std;

int main()
{
    string s = "Mehak Fatima";
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }
    cout << s << endl;
    return 0;
}