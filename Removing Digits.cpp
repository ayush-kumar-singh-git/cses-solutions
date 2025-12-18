#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<int> digits(int n)
{
    vector<int> digi;
    while (n > 0)
    {
        digi.emplace_back(n % 10);
        n /= 10;
    }
    return digi;
}

int main()
{
    int n;
    cin >> n;
    if (n <= 9)
    {
        cout << 1 << "\n";
        return 0;
    }
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i < 10; i++)
        dp[i] = 1;
    for (int i = 10; i <= n; i++)
    {
        vector<int> digi = digits(i);
        for (int d : digi)
        {
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}