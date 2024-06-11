#include <bits/stdc++.h>
using namespace std;

int main() {
    long long tt;
    cin >> tt;
    while(tt--) {
        long long n, l, r, k, flag, x, temp, last, maxx, sub, m, y;
        long long summ;
        long long q[200005];
        
        cin >> n;
        maxx = 0;
        summ = 0;
        for (int i = 1; i <= n; i++) {
            cin >> q[i];
        }
        x = 0;
        for (int i = 1; i <= n; i++) {
            summ += q[i];
            maxx = max(maxx, q[i]);
            if(maxx == summ - maxx) {
                x++;
            }
        }
        cout << x << endl;
    }

    return 0;
}
