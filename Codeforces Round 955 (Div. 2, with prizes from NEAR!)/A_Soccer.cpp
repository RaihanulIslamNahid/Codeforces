#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int temp1 = x1 - y1;
        int temp2 = x2 - y2;

        if ((temp1 > 0 && temp2 > 0) || (temp1 < 0 && temp2 < 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
