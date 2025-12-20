#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

bool valid(int n, int m)
{
    return ((n > 0) && (n <= m));
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // dp[i][k] = # of prefixes of length i that can be formed such that the last element in k
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        if (v[0] == i || v[0] == 0)
        {
            dp[1][i] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            if (v[i - 1] != 0 && v[i - 1] != k)
            {
                dp[i][k] = 0;
                continue;
            }
            for (int prev = k - 1; prev <= k + 1; prev++)
            {
                if (!valid(prev, m))
                {
                    continue;
                }
                dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % MOD;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}