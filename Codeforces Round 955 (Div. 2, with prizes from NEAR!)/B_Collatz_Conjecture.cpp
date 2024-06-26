#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        while (c > 0 && a != 1) {
            int temp = ((a / b) + 1) * b;
            int temp1 = temp - a;

            if (c < temp1) {
                a += c;
                c = 0;
            } else {
                c -= temp1;
                a = temp;

                while (a % b == 0) {
                    a /= b;
                }
            }
        }

        if (a == 1) {
            cout << 1 + c % (b - 1) << "\n";
        } else {
            cout << a << "\n";
        }
    }

    return 0;
}