// Author: ayush.kumar.singh
// Date: 08-02-26 15:35:54
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++) cin >> v[i];
    set<int> on;
    on.insert(0);
    on.insert(n);
    multiset<int> sz;
    sz.insert(n);
    for (int x : v) {
        auto it = on.upper_bound(x);
        int r = *it;
        it--;
        int l = *it;
        auto itr = sz.find(r - l);
        sz.erase(itr);
        on.insert(x);
        sz.insert(x - l);
        sz.insert(r - x);
        cout << *(sz.rbegin()) << " ";
    }
    cout << "\n";
    return 0;
}
