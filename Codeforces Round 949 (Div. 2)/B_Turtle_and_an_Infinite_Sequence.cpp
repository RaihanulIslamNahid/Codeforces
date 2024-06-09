#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long l = max(0LL, n - m), r = n + m;
        int at = 40;
        while (at >= 0 && (l >> at & 1) == (r >> at & 1)) --at;
        long long ans = r;
        if (at >= 0) ans |= (1LL << at) - 1;
        cout << ans << endl;
    }
    return 0;
}
