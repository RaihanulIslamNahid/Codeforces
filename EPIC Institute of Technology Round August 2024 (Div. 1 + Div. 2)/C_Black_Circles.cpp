#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll squaredDistance(ll x1, ll y1, ll x2, ll y2)
{
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    return dx * dx + dy * dy;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<pair<ll, ll>> points(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> points[i].first >> points[i].second;
        }

        ll xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;

        ll referenceDistance = squaredDistance(xs, ys, xd, yd);
        bool reachable = false;

        for (ll i = 0; i < n; ++i)
        {

            if (referenceDistance >= squaredDistance(points[i].first, points[i].second, xd, yd))
            {
                reachable = true;
                break;
            }
        }

        if (reachable)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}
