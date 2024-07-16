#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<int> v;
        for (int i = 60; i >= 0; i--)
        {
            if (n >> i & 1)
            {
                v.push_back(i);
            }
        }
        if (v.size() == 1)
        {
            cout << 1 << '\n'
                 << n << '\n';
            continue;
        }
        cout << v.size() + 1 << '\n';
        for (int i = 0; i < v.size(); i++)
        {
            cout << (n ^ (1LL << v[i])) << ' ';
        }
        cout << n << '\n';
    }
    return 0;
}