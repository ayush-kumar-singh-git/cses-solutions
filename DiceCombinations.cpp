#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

// recursive (won't pass)
long long DP(int n, vector<long long> &dp)
{
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i < 0)
            break;
        dp[n] = (dp[n] + DP(n - i, dp)) % MOD;
    }
    return dp[n] % MOD;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0); // for recursive set as -1
    dp[0] = 1;
    // cout << DP(n, dp) << "\n";

    // iterative solution
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j < 0)
                break;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}