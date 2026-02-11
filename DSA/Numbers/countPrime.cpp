#include <iostream>
#include <vector>
using namespace std;

int countPrime(int n)
{

    int count = 0;
    vector<bool> isPrime(n + 1, true); // assume all numbers are prime intially

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {                                         // if the current number is prime
            count++;                              // increase the count
            for (int j = i * 2; j < n; j = j + i) // now check for the multiple of i and make them non prime in the vector
            // j = i*2 => 2*2 = 4 3*2= 6 5*2=10 this is the reason
            // j = j + 1 => 2+2 = 4 4+2= 6 will take us to the next multiple
            {
                isPrime[j] = false; // mark as false
            }
        }
    }
    return count;
}

int main()
{
    cout << countPrime(15) << endl;
    return 0;
}