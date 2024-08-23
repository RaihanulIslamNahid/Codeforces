#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> even, odd;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            if (a % 2 == 0)
                even.push_back(a);
            else
                odd.push_back(a);
        }

        int sum_even = accumulate(even.begin(), even.end(), 0);
        int sum_odd = accumulate(odd.begin(), odd.end(), 0);

        if (sum_even > sum_odd)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
