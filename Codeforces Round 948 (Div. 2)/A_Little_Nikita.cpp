#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        if (m <= n && (n % 2 == m % 2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
/*
For each test case, we read the integers n and m.
We check if m is less than or equal to n and if both n and m have the same parity.
*/