#include <iostream>
using namespace std;

void squarePatternNum(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void squarePatternChar(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char c = 'A';
        for (int j = 1; j <= n; j++)
        {
            cout << c << " ";
            c++;
        }
        cout << endl;
    }
}

void squarePattern(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << count++ << " ";
        }
        cout << endl;
    }
}

void trianglePatternStar(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void trianglePatternNumber(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void trianglePatternCharacter(int n)
{
    char c = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << c << " ";
        }
        c++;
        cout << endl;
    }
}

void trianglePatternNumber2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void trianglePatternReverse(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void triangleFloyd(int n)
{
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << c++ << " ";
        }
        cout << endl;
    }
}

void invertedTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        { // spaces
            cout << "  ";
        }
        for (int k = n; k > i; k--)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

void pyramidTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = i; k < n - 1; k++)
        {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        for (int l = i; l > 0; l--)
        {
            cout << l << " ";
        }
        cout << endl;
    }
}

void hollowDiamond(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        cout << "*";
        if (i != 0)
        {
            for (int j = 0; j < 2 * i - 1; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }

        cout << "*";
        if (i != 0)
        {
            for (int j = 0; j < 2 * i - 1; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}

void butterflyPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        for (int k = 0; k < 2 * (n - i) - 2; k++)
        {
            cout << "  ";
        }
        for (int l = 0; l <= i; l++)
        {

            cout << "* ";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        for (int k = 0; k < 2 * (n - i) - 2; k++)
        {
            cout << "  ";
        }
        for (int l = 0; l <= i; l++)
        {

            cout << "* ";
        }
        cout << endl;
    }
}
int main()
{
    butterflyPattern(3);
    return 0;
}