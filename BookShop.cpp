#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    vector<long long> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= prices[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }
    long long ans = 0;
    for (auto y : dp)
        ans = max(ans, y);
    cout << ans << "\n";
    return 0;
}