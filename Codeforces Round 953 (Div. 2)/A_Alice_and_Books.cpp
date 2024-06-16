#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &c : v) {
            cin >> c;
        }
        int mx = 0;
        for (int i = 0; i < n - 1; ++i) {
            mx = max(mx, v[i]);
        }
        cout << mx + v[n - 1] << "\n";
    }

    return 0;
}
