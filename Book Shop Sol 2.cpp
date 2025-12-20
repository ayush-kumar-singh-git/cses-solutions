// doesn't pass
#include <bits/stdc++.h>
using namespace std;

const long long NINF = -1 * 1e18;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            long long take = NINF, notTake = NINF;
            notTake = dp[i - 1][j];
            if (j - prices[i - 1] >= 0)
                take = dp[i - 1][j - prices[i - 1]] + pages[i - 1];
            dp[i][j] = max(take, notTake);
        }
    }
    cout << dp[n][x] << "\n";
    return 0;
}