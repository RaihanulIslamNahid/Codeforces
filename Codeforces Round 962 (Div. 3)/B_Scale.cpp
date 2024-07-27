#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<string> str(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> str[i];
        }
        int size = n / k;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                cout << str[i * k][j * k];
            }
            cout << endl;
        }
    }

    return 0;
}