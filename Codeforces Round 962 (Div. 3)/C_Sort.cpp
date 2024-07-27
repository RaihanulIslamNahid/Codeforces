#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        vector<vector<int>> A(n + 1, vector<int>(26, 0));
        vector<vector<int>> B(n + 1, vector<int>(26, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                A[i + 1][j] = A[i][j];
                B[i + 1][j] = B[i][j];
            }
            A[i + 1][a[i] - 'a']++;
            B[i + 1][b[i] - 'a']++;
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;

            int ans = 0;
            for (int j = 0; j < 26; ++j)
            {
                int cntA = A[r + 1][j] - A[l][j];
                int cntB = B[r + 1][j] - B[l][j];
                ans += abs(cntA - cntB);
            }
            cout << ans / 2 << endl;
        }
    }
    return 0;
}