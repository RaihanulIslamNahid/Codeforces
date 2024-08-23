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
        string s;
        cin >> s;

        unordered_map<char, int> pos;

        bool possible = true;
        for (int i = 0; i < n; ++i)
        {
            if (pos.count(s[i]))
            {
                if (pos[s[i]] % 2 != i % 2)
                {
                    possible = false;
                    break;
                }
            }
            else
            {
                pos[s[i]] = i;
            }
        }

        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
