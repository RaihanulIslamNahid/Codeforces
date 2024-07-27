#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int cnt = 0;

        for (int a = 1; a <= x; ++a)
        {
            int max_b = min(n / a, x - a);

            for (int b = 1; b <= max_b; ++b)
            {
                int max_c = min((n - a * b) / (a + b), x - a - b);

                if (max_c >= 1)
                {
                    cnt += max_c;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}