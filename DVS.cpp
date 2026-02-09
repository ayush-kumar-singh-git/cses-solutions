// Author: ayush.kumar.singh
// Date: 09-02-26 07:16:54
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    multiset<int> st;
    int l = 0, r = 0;
    long long N = n;
    long long ans = N;
    while (r < n) {
        st.insert(v[r]);
        while (l <= r && st.count(v[r]) > 1) {
            auto it = st.find(v[l]);
            st.erase(it);
            l++;
        }
        long long len = r - l + 1;
        ans += len - 1;
        r++;
    }
    cout << ans << "\n";
}

