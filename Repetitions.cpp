#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while ((j < n) && (s[j] == s[i]))
            j++;
        ans = max(ans, j - i);
        i = j - 1;
    }
    cout << ans << "\n";
    return 0;
}