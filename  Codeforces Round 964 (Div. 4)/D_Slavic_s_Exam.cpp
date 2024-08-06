#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSubsequence(const string &s, const string &t)
{
    int n = s.size(), m = t.size();
    int j = 0;
    for (int i = 0; i < n && j < m; ++i)
    {
        if (s[i] == t[j])
        {
            ++j;
        }
    }
    return j == m;
}

int main()
{
    int t;
    cin >> t;
    vector<string> results;

    while (t--)
    {
        string s, t;
        cin >> s >> t;

        int n = s.size(), m = t.size();
        string modified_s = s;
        bool possible = false;

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == '?')
            {
                modified_s[i] = t[j];
                ++j;
            }
            else if (s[i] == t[j])
            {
                ++j;
            }
            ++i;
        }

        if (j == m)
        {
            possible = true;
            for (int k = 0; k < n; ++k)
            {
                if (modified_s[k] == '?')
                {
                    modified_s[k] = 'a'; // Replace remaining '?' with 'a' or any other letter
                }
            }
        }

        if (possible)
        {
            results.push_back("YES");
            results.push_back(modified_s);
        }
        else
        {
            results.push_back("NO");
        }
    }

    for (const string &result : results)
    {
        cout << result << endl;
    }

    return 0;
}