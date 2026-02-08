// Author: ayush.kumar.singh
// Date: 08-02-26 15:23:49
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> l, r;
    l.insert(0);
    r.insert(n);
    multiset<int> sz;
    sz.insert(n);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        auto it1 = l.upper_bound(x);
        it1--;
        auto it2 = r.upper_bound(x);
        int ll = *(it1);
        int rr = *(it2);
        auto it3 = sz.find(rr - ll);
        sz.erase(it3);
        sz.insert(x - ll);
        sz.insert(rr - x);
        l.insert(x);
        r.insert(x);
        cout << *(sz.rbegin()) << " ";
    }
    cout << "\n";
    return 0;
}
