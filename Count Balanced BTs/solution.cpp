#include <iostream>
using namespace std;
#define mod 1000000007

int balancedBTsHelper(int h, int *dp)
{
    if (h <= 1)
        return 1;
    if (dp[h] != -1)
    {
        return dp[h];
    }
    int x = balancedBTsHelper(h - 1, dp);
    int y = balancedBTsHelper(h - 2, dp);
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    dp[h] = (temp1 + temp2) % mod;
    return dp[h];
}

int balancedBTs(int h)
{
    int dp[h + 1];
    for (int i = 0; i <= h; i++)
        dp[i] = -1;
    return balancedBTsHelper(h, dp);
}

// main function
int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}