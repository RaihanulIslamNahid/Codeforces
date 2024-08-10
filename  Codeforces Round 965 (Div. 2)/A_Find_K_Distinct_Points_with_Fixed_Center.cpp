#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        vector<pair<int, int>> points;

        if (k % 2 == 1)
        {
            points.push_back({x, y});
        }

        for (int i = 1; i <= k / 2; i++)
        {
            points.push_back({x - i, y - i});
        }

        for (int i = 1; i <= k / 2; i++)
        {
            points.push_back({x + i, y + i});
        }

        for (auto point : points)
        {
            cout << point.first << " " << point.second << endl;
        }
    }

    return 0;
}
