#include <iostream>
#include <vector>

using namespace std;

long long pw(long long a, long long b, long long mod)
{
    long long result = 1;
    a = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = (result * a) % mod;
        }
        b = b / 2;
        a = (a * a) % mod;
    }
    return result;
}

void solve()
{
    int l = 2, r = 999;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        cout << "? " << mid - 1 << " " << mid << endl;
        cout.flush();

        long long a;
        cin >> a;

        // Check conditions and update the binary search range
        if (a == (mid - 1) * (mid + 1))
        {
            cout << "! " << mid << endl;
            return;
        }
        if (a == mid * (mid - 1))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}
