#include <bits/stdc++.h>
#define pb push_back
#include <vector>
#include <set>
#include <map>
using namespace std;
#define ll long long
#define yes cout << "YES"
#define no cout << "NO"
#define nl "\n"
#define loop(i, n) for (int i = 0; i < (int)n; i++)
#define loop1(i, n) for (int i = 1; i <= (int)n; i++)
#define loopab(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define all(a) (a).begin(), (a).end()
ll MOD = 1e9 + 7;
//(a-b)%m=(a%m-b%m+m)%m
// DIV BY MOD  (multiplicative in of b)=pw(b,m-2)%m;
ll pw(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = pw(a, b / 2);
    if (b % 2 == 0)
        return 1ll * t * t % MOD;
    else
        return 1ll * t * t * a % MOD;
}
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    ll b[n];
    loop(i, n) cin >> a[i];
    loop(i, n) cin >> b[i];
    ll ft = true;
    ll bt = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            ft = false;
    }
    if (ft)
    {
        cout << "Bob" << nl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[n - i - 1])
            bt = false;
    }
    if (bt)
    {
        cout << "Bob" << nl;
        return;
    }
    cout << "Alice" << nl;
    return;
}

int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
