#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        
        int array[] = {x1, x2, x3};
        sort(array, array + 3);
        
        int ans = 1e9; 
        
        for (int i = 0; i < 3; ++i) {
            int a = array[i];
            int f_a = abs(x1 - a) + abs(x2 - a) + abs(x3 - a);
            ans = min(ans, f_a);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
