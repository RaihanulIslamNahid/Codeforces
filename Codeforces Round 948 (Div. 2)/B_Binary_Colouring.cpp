#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        
        vector<int> a;
        int position = 0;
        
        while (x > 0) {
            if (x & 1) {
                if (x & 2) { 
                    a.push_back(-1);
                    x = (x >> 1) + 1; 
                } else {
                    a.push_back(1);
                    x >>= 1;
                }
            } else {
                a.push_back(0);
                x >>= 1;
            }
            position++;
        }
        
        cout << a.size() << endl;
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] << (i < a.size() - 1 ? " " : "");
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
