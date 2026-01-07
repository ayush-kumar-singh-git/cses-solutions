#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    vector<long long> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coin[j] < 0)
                continue;
            dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }
    if (dp[x] == INF)
        cout << -1 << "\n";
    else
        cout << dp[x] << "\n";
    return 0;
}