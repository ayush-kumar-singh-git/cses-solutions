#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    multiset<int> curr;
    int ans = 0;
    for (int x : v) {
        if (curr.size() == 0) {
            ans++;
            curr.insert(x);
            continue;
        }
        auto it = curr.upper_bound(x);
        if (it == curr.end()) {
            ans++;
        } else {
            curr.erase(it);
        }
        curr.insert(x);
    }
    cout << ans << "\n";
    return 0;
}
