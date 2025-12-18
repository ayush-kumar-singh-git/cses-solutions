#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
    {
        cout << 0 << "\n";
        return 0;
    }
    vector<vector<long long>> dp(n, vector<long long>(n, 0LL));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - 1 >= 0 && grid[i - 1][j] != '*')
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j - 1 >= 0 && grid[i][j - 1] != '*')
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}