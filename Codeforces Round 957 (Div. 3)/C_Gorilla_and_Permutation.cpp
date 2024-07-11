#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> result;

        for (int i = 0; i < x; i++)
        {
            result.push_back(i + 1);
        }

        for (int i = x; i >= z; --i)
        {
            cout << i << " ";
        }
        if (z < y)
        {
            for (int i = z + 1; i < y; ++i)
            {
                cout << i << " ";
            }
        }
        else
        {
            for (int i = y + 1; i < z; ++i)
            {
                cout << i << " ";
            }
        }
        for (int i = 1; i <= y; ++i)
        {
            cout << i << " ";
        }
        for (int i = z; i < y; i++)
        {
            result.push_back(i + 1);
        }

        cout << endl;
    }
    return 0;
}
