#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n);
        long long total_sum = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            total_sum += a[i];
        }

        while (q--)
        {
            int l, r;
            long long k;
            cin >> l >> r >> k;

            l--;
            r--;

            long long range_sum = 0;
            for (int i = l; i <= r; ++i)
            {
                range_sum += a[i];
            }

            long long new_sum = total_sum - range_sum + (r - l + 1) * k;

            if (new_sum % 2 == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}