#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> s(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            s[i][j] = row[j] - '0';
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    int diff = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 1) {
                cur += 1;
                diff += a[i][j];
            } else {
                diff -= a[i][j];
            }
            pref[i + 1][j + 1] = pref[i][j + 1] + cur;
        }
    }

    if (diff == 0) {
        cout << "YES\n";
        return;
    }

    int g = 0;
    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j <= m - k; ++j) {
            int f = pref[i + k][j + k] - pref[i + k][j] - pref[i][j + k] + pref[i][j];
            f = abs(k * k - 2 * f);
            g = gcd(g, f);
        }
    }

    if (g == 0 || diff % g != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}