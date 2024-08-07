#include <bits/stdc++.h>

using namespace std;

const int MAX = 200'007;
const int MOD = 1'000'000'007;

void solve()
{
    int l = 1, r = 999;
    while (r - l > 2)
    {
        int a = (2 * l + r) / 3;
        int b = (2 * r + l) / 3;
        cout << "? " << a << ' ' << b << endl;
        int resp;
        cin >> resp;

        if (resp == (a + 1) * (b + 1))
        {
            r = a;
        }
        else if (resp == a * b)
        {
            l = b;
        }
        else
        {
            l = a;
            r = b;
        }
    }
    if (r - l == 2)
    {
        cout << "? 1 " << l + 1 << endl;
        int resp;
        cin >> resp;

        if (resp == l + 1)
        {
            l = l + 1;
        }
        else
        {
            r = l + 1;
        }
    }
    cout << "! " << r << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        solve();
    }
    // solve();
}
