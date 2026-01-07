#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (auto c : coins)
    {
        for (int i = 0; i + c <= x; i++)
        {
            dp[i + c] = (dp[i + c] + dp[i]) % MOD;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}