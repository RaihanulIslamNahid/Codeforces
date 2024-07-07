#include <bits/stdc++.h>
using namespace std;

#define long long long

long ans[6];

bool solve(vector<long> &a, vector<long> &b, vector<long> &c, long total)
{
    bool flag[3] = {false, false, false};
    int n = a.size();
    int j = 0;
    long sum = 0;
    ans[0] = 1;
    for (j = 0; j < n; ++j)
    {
        sum += a[j];
        ans[1] = j + 1;
        if (sum >= (total + 2) / 3)
        { // ceil(total, 3)
            ++j;
            flag[0] = true;
            break;
        }
    }
    sum = 0;
    ans[2] = j + 1;
    for (; j < n; ++j)
    {
        sum += b[j];
        ans[3] = j + 1;
        if (sum >= (total + 2) / 3)
        { // ceil(total, 3)
            ++j;
            flag[1] = true;
            break;
        }
    }
    sum = 0;
    ans[4] = j + 1;
    for (; j < n; ++j)
    {
        sum += c[j];
        ans[5] = j + 1;
        if (sum >= (total + 2) / 3)
        { // ceil(total, 3)
            ++j;
            flag[2] = true;
            break;
        }
    }
    return flag[0] && flag[1] && flag[2];
}

void solve()
{
    int n;
    cin >> n;
    vector<long> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    long total = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < 6; ++i)
    {
        vector<long> aa = a, bb = b, cc = c;
        bool flag = false;
        if (i == 0)
            flag = solve(aa, bb, cc, total);
        if (i == 1)
            flag = solve(aa, cc, bb, total);
        if (i == 2)
            flag = solve(bb, aa, cc, total);
        if (i == 3)
            flag = solve(bb, cc, aa, total);
        if (i == 4)
            flag = solve(cc, aa, bb, total);
        if (i == 5)
            flag = solve(cc, bb, aa, total);
        if (flag)
        {
            ans[5] = n;
            if (i == 0)
                cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << "\n";
            if (i == 1)
                cout << ans[0] << " " << ans[1] << " " << ans[4] << " " << ans[5] << " " << ans[2] << " " << ans[3] << "\n";
            if (i == 2)
                cout << ans[2] << " " << ans[3] << " " << ans[0] << " " << ans[1] << " " << ans[4] << " " << ans[5] << "\n";
            if (i == 3)
                cout << ans[4] << " " << ans[5] << " " << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
            if (i == 4)
                cout << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << " " << ans[0] << " " << ans[1] << "\n";
            if (i == 5)
                cout << ans[4] << " " << ans[5] << " " << ans[2] << " " << ans[3] << " " << ans[0] << " " << ans[1] << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t-- > 0)
        solve();

    return 0;
}