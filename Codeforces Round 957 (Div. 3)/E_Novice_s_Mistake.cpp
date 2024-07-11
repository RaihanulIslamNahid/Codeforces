#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define vii vector<ll>
#define pll pair<ll, ll>
#define F first
#define S second

const ll N = (ll)3e5 + 5;
const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e18;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        ll a, b, c, i, j, k, m, n, o, x, y, z;

        cin >> n;
        string s = to_string(n);
        ll dg = s.size();
        vector<pll> v;

        s = s + s + s + s + s + s;
        ll nn = stoll(s);

        vii tpw(10, 1);
        ll cur = 0;
        for (i = 1; i < 10; i++)
        {
            cur = cur * 10 + (s[i - 1] - '0');
            tpw[i] = cur;
        }

        for (i = 1; i <= 10000; i++)
        {
            ll tot = i * dg;

            for (j = max(1ll, tot - 7); j <= min(10000ll, tot - 1); j++)
            {
                if (n * i - j == tpw[tot - j])
                {
                    v.push_back({i, j});
                }
            }
        }

        cout << v.size() << "\n";
        for (pll p : v)
        {
            cout << p.F << " " << p.S << "\n";
        }
    }
}