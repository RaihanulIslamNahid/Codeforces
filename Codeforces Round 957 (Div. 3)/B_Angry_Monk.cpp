#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        vector<int> v(y);
        int temp = 0;

        for (int i = 0; i < y; i++)
        {
            cin >> v[i];
            temp = max(temp, v[i]);
        }

        int ans = 0;

        for (int i = 0; i < y; i++)
        {
            if (v[i] != 1)
            {
                ans += v[i] - 1;
            }
        }

        ans = ans + x - 2 * temp + 1;
        cout << ans << endl;
    }
    return 0;
}
