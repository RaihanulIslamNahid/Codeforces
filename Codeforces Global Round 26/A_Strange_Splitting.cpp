#include<bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (a[0] == a[n-1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            string result(n, 'B');
            result[1] = 'R';
            cout << result << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
