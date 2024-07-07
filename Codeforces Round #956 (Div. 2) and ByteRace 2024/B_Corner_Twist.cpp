#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                char ch;
                cin >> ch;
                a[i][j] = ch - '0';
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                char ch;
                cin >> ch;
                b[i][j] = ch - '0';
            }

        bool possible = true;

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < m - 1; ++j)
            {
                while (a[i][j] != b[i][j])
                {
                    a[i][j] = (a[i][j] + 1) % 3;
                    a[i + 1][j] = (a[i + 1][j] + 2) % 3;
                    a[i][j + 1] = (a[i][j + 1] + 2) % 3;
                    a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (a[i][m - 1] != b[i][m - 1])
            {
                possible = false;
                break;
            }
        }

        for (int j = 0; j < m; ++j)
        {
            if (a[n - 1][j] != b[n - 1][j])
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}