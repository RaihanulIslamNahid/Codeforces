#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOVES = 40;
const int INF = INT64_MAX;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ans += arr[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<int> sum(2);
    function<vector<int>(int, int, int)> dfs = [&](int x, int p, int type)
    {
        sum[type] += arr[x];
        vector<int> res(MOVES + 1);
        for (int i = 1; i <= MOVES; i++)
            res[i] = arr[x] * i;
        for (int &v : adj[x])
            if (v != p)
            {
                auto before = dfs(v, x, type ^ 1ll);
                before[0] = INF;
                auto after = before;
                after.emplace_back(INF);
                for (int i = 1; i <= MOVES; i++)
                    before[i] = min(before[i], before[i - 1]);
                for (int i = MOVES; i; i--)
                    after[i] = min(after[i], after[i + 1]);
                for (int i = 1; i <= MOVES; i++)
                {
                    res[i] += min(before[i - 1], after[i + 1]);
                }
            }
        return res;
    };
    auto res = dfs(1, 0, 0);
    res.erase(res.begin());
    cout << *min_element(res.begin(), res.end()) << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}