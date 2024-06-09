#include <iostream>
using namespace std;

#define ll long long

void solve() {
    ll n;
    cin >> n;

    // Adjust n to ensure the last digit is one more than its original value
    n = n - n % 10 + (n % 10 + 1) % 10;

    // Check if n satisfies the condition
    while (n > 9) {
        // If the last digit becomes 0, it cannot be expressed as the sum of two large positive integers with the same number of digits
        if (n % 10 == 0) {
            cout << "NO\n";
            return;
        }
        // Divide n by 10 to consider the next digit
        n /= 10;
    }

    // If n becomes 1, it can be expressed as the sum of two large positive integers with the same number of digits; otherwise, it cannot
    cout << (n == 1 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();

    return 0;
}
