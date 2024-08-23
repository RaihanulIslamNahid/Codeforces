#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define SIZE 16 + 2
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int sm = 1;
    if (v[0] != 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] <= sm)
        {
            sm += v[i];
            continue;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
