#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int prev = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        ans += max(0, prev - curr);
        prev = max(curr, prev);
    }
    cout << ans << "\n";
    return 0;
}