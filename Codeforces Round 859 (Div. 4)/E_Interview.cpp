#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    Faster int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        int ans;
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int len = mid - low + 1;
            if (low == high)
            {
                ans = mid;
                break;
            }
            cout << "? " << len << " ";
            ll sum = 0;
            for (int i = low; i <= mid; i++)
            {
                cout << i << " ";
                sum += a[i];
            }
            cout << endl;
            cout.flush();
            ll res;
            cin >> res;
            if (res > sum)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << "! " << ans << endl;
        cout.flush();
    }
    return 0;
}
