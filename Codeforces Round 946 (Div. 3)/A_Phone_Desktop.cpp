#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x, y; 
        cin >> x >> y;
        int temp = (y + 1) / 2;
        int r = (15 * temp) - (y * 4);
        x -= r;
        x = max(0, x);
        int ans = (x + 14) / 15;
        ans += temp;
        cout << ans << endl;
    }

    return 0;
}
