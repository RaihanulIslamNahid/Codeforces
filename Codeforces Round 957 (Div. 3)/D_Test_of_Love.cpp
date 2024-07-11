#include <queue>
#include <vector>
#include <string>
#include <iostream> // Include for cin and cout

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        string str;
        cin >> str;

        vector<bool> v(n + 2, false);
        queue<pair<int, int>> q;

        q.push({0, 0});
        v[0] = true;

        bool flag = false;

        while (!flag && !q.empty())
        {
            auto [pos, swim] = q.front();
            q.pop();

            if (pos == 0 || str[pos - 1] == 'L')
            {
                for (int j = 1; j <= m; ++j)
                {
                    int temp = pos + j;
                    if (temp == n + 1)
                    {
                        flag = true;
                        break;
                    }
                    if (temp <= n && str[temp - 1] != 'C' && !v[temp])
                    {
                        v[temp] = true;
                        q.push({temp, swim});
                    }
                }
            }
            if (pos > 0 && pos <= n && str[pos - 1] == 'W' && swim < k)
            {
                int temp = pos + 1;
                if (temp == n + 1)
                {
                    flag = true;
                    break;
                }
                if (temp <= n && str[temp - 1] != 'C' && !v[temp])
                {
                    v[temp] = true;
                    q.push({temp, swim + 1});
                }
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}
