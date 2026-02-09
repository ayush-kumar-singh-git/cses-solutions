// Author: ayush.kumar.singh
// Date: 09-02-26 07:04:13
#include <bits/stdc++.h>
using namespace std;

int foo(map<int, vector<int>>& tree, vector<int>& dp, int i) {
    if (dp[i] != -1) return dp[i];
    int ans = 0;
    if (tree.find(i) != tree.end()) {
        for (int x : tree[i]) {
            ans += foo(tree, dp, x);
            ans++;
        }
    }
    return dp[i] = ans;
}

int main() {
    int n;
    cin >> n;
    map<int, vector<int>> tree;
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].emplace_back(i);
    }
    vector<int> dp(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        dp[i] = foo(tree, dp, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}
