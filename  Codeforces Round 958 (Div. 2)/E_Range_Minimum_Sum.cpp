#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
using ll = long long;

struct BIT
{
    int n;
    vector<ll> M, A;
    BIT() {}
    BIT(int _n)
    {
        n = _n;
        M = A = vector<ll>(n + 1, 0);
    }
    void update(int i, ll mul, ll add)
    {
        while (i <= n)
        {
            M[i] += mul;
            A[i] += add;
            i |= (i + 1);
        }
    }
    void upd(int l, int r, ll x)
    {
        update(l, x, -x * (l - 1));
        update(r, -x, x * r);
    }
    ll query(int i)
    {
        ll mul = 0, add = 0;
        int st = i;
        while (i >= 0)
        {
            mul += M[i];
            add += A[i];
            i = (i & (i + 1)) - 1;
        }
        return (mul * st + add);
    }
    ll query(int l, int r)
    {
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
    }
} t;

int a[N], l[N], r[N];
ll ans[N];
bool loop_over_left[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = a[n + 1] = 0;
    vector<int> v;
    v.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        while (a[v.back()] > a[i])
        {
            v.pop_back();
        }
        l[i] = v.back();
        v.push_back(i);
    }
    v.clear();
    v.push_back(n + 1);
    for (int i = n; i >= 1; i--)
    {
        while (a[v.back()] > a[i])
        {
            v.pop_back();
        }
        r[i] = v.back();
        v.push_back(i);
    }

    // for (int i = 1; i <= n; i++) {
    //   cout << l[i] << ' ' << r[i] << '\n';
    // }

    ll tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += 1LL * a[i] * (i - l[i]) * (r[i] - i);
    }

    for (int i = 1; i <= n; i++)
    {
        ans[i] = tot - 1LL * a[i] * (i - l[i]) * (r[i] - i);

        loop_over_left[i] = false;
        if (i - l[i] < r[i] - i)
        {
            loop_over_left[i] = true;
        }
    }

    v.clear();
    v.push_back(0);
    t = BIT(n);
    for (int i = 1; i <= n; i++)
    {
        while (a[v.back()] > a[i])
        {
            int R = v.back(), val = a[v.back()];
            v.pop_back();
            int L = v.back() + 1;
            t.upd(L, R, -val + a[i]);
        }
        v.push_back(i);
        t.upd(i, i, +a[i]);

        ans[i] -= t.query(1, l[i]);

        int id = i + 1;
        if (id <= n and !loop_over_left[id])
        {
            int mn = N;
            for (int j = i + 2; j < r[id]; j++)
            {
                mn = min(mn, a[j]);

                int L = 0, R = (int)v.size() - 1, cur = 0;
                while (L <= R)
                {
                    int mid = L + R >> 1;
                    if (a[v[mid]] < mn)
                    {
                        cur = v[mid];
                        L = mid + 1;
                    }
                    else
                    {
                        R = mid - 1;
                    }
                }

                ans[id] += 1LL * max(0, i - max(cur, l[id])) * mn;
                ans[id] += t.query(l[id] + 1, cur);
            }
        }
    }

    v.clear();
    v.push_back(n + 1);
    t = BIT(n);
    for (int i = n; i >= 1; i--)
    {
        while (a[v.back()] > a[i])
        {
            int L = v.back(), val = a[v.back()];
            v.pop_back();
            int R = v.back() - 1;
            t.upd(L, R, -val + a[i]);
        }
        v.push_back(i);
        t.upd(i, i, +a[i]);

        ans[i] -= t.query(r[i], n);

        int id = i - 1;
        if (id >= 1 and loop_over_left[id])
        {
            int mn = N;
            for (int j = i - 2; j > l[id]; j--)
            {
                mn = min(mn, a[j]);

                int L = 0, R = (int)v.size() - 1, cur = n + 1;
                while (L <= R)
                {
                    int mid = L + R >> 1;
                    if (a[v[mid]] < mn)
                    {
                        cur = v[mid];
                        L = mid + 1;
                    }
                    else
                    {
                        R = mid - 1;
                    }
                }

                ans[id] += 1LL * max(0, min(cur, r[id]) - i) * mn;
                ans[id] += t.query(cur, r[id] - 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}