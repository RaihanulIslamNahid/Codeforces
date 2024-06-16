#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;
    vector<int> v(t);

    for (int i = 0; i < t; ++i) {
        int n, a, b;
        cin >> n >> a >> b;

        if (b < a) {
            v[i] = a * n;
        } else {
            int k = min(b - a, n);
            int temp1 = k * (2 * b - k + 1) / 2;
            int temp2 = (n - k) * a;
            v[i] = temp1 + temp2;
        }
    }

    for (int result : v) {
        cout << result << "\n";
    }

    return 0;
}
