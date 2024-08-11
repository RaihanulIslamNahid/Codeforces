#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n, -1);
        for (int i = 1; i < n; ++i)
        {
            cin >> a[i];
            --a[i];
        }

        vector<int> p(n);
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> p[i];
            --p[i];
            pos[p[i]] = i;
        }

        vector<int> f(n, 0);
        vector<vector<int>> adj(n);
        for (int i = n - 1; i >= 0; --i)
        {
            if (i > 0)
            {
                adj[a[i]].push_back(i);
            }
            for (int j : adj[i])
            {
                f[i] += f[j];
            }
            f[i] += 1;
        }

        vector<set<int>> s(n);
        int bad = 0;

        auto calc = [&](int i)
        {
            if (s[i].empty())
                return false;
            int x = pos[i];
            int y = *s[i].begin();
            return y < x;
        };

        auto del_ = [&](int i, int x)
        {
            if (s[i].count(x))
            {
                auto it = s[i].lower_bound(x);
                int l = (it == s[i].begin()) ? -1 : *prev(it);
                int r = (next(it) == s[i].end()) ? -1 : *next(it);

                if (l != -1 && l + f[p[l]] != x)
                    bad--;
                if (r != -1 && x + f[p[x]] != r)
                    bad--;
                if (l != -1 && r != -1 && l + f[p[l]] != r)
                    bad++;
                s[i].erase(it);
            }
        };

        auto add = [&](int i, int x)
        {
            s[i].insert(x);
            auto it = s[i].lower_bound(x);
            int l = (it == s[i].begin()) ? -1 : *prev(it);
            int r = (next(it) == s[i].end()) ? -1 : *next(it);

            if (l != -1 && l + f[p[l]] != x)
                bad++;
            if (r != -1 && x + f[p[x]] != r)
                bad++;
            if (l != -1 && r != -1 && l + f[p[l]] != r)
                bad--;
        };

        for (int i = 0; i < n; ++i)
        {
            if (a[p[i]] != -1)
            {
                add(a[p[i]], i);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            bad += calc(i);
        }

        while (q--)
        {
            int x, y;
            cin >> x >> y;
            --x;
            --y;

            set<int> change = {p[x], p[y], a[p[x]], a[p[y]]};
            for (int z : change)
            {
                if (z != -1)
                    bad -= calc(z);
            }

            if (a[p[x]] != -1)
                del_(a[p[x]], x);
            if (a[p[y]] != -1)
                del_(a[p[y]], y);

            swap(p[x], p[y]);
            swap(pos[p[x]], pos[p[y]]);

            if (a[p[x]] != -1)
                add(a[p[x]], x);
            if (a[p[y]] != -1)
                add(a[p[y]], y);

            for (int z : change)
            {
                if (z != -1)
                    bad += calc(z);
            }

            cout << (bad == 0 ? "YES" : "NO") << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
