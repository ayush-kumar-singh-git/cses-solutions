#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mp[t] = i;
    }
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        if (mp[i] < mp[i - 1]) ans++;
    }
    cout << ans << "\n";
    return 0;
}
