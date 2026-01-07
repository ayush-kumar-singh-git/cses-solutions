#include <bits/stdc++.h>
using namespace std;

// fails one case

const int MOD = 1e9 + 7;

int foo(int n, int k, vector<int> &v, int m, vector<vector<int>> &dp)
{
    if (dp[n][k] != -1)
        return dp[n][k];
    if (n == 1)
    {
        if (v[0] == 0 || v[0] == k)
            return dp[n][k] = 1;
        return dp[n][k] = 0;
    }
    if (v[n - 1] != 0 && v[n - 1] != k)
        return dp[n][k] = 0;
    vector<int> answers;
    if (k - 1 > 0)
        answers.emplace_back(foo(n - 1, k - 1, v, m, dp));
    answers.emplace_back(foo(n - 1, k, v, m, dp));
    if (k + 1 <= m)
        answers.emplace_back(foo(n - 1, k + 1, v, m, dp));
    int ans = 0;
    for (int x : answers)
    {
        ans = (ans + x) % MOD;
    }
    return dp[n][k] = ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + foo(n, i, v, m, dp)) % MOD;
    }
    cout << ans << "\n";
    return 0;
}