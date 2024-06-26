#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        int l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        int curr_sum = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            curr_sum += a[end];

            while (curr_sum > r && start <= end) {
                curr_sum -= a[start];
                ++start;
            }

            if (curr_sum >= l && curr_sum <= r) {
                ++ans;
                curr_sum = 0;
                start = end + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
