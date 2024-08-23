#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, i1, j1, i2, j2;
        string d;
        cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;

        int bounces = 0;
        map<pair<pair<int, int>, string>, bool> visited;

        while (true)
        {
            if (i1 == i2 && j1 == j2)
            {
                cout << bounces << endl;
                break;
            }

            if (visited[{{i1, j1}, d}])
            {
                cout << -1 << endl;
                break;
            }

            visited[{{i1, j1}, d}] = true;

            if (d == "DR")
            {
                if (i1 == n && j1 == m)
                {
                    d = "UL";
                    bounces++;
                }
                else if (i1 == n)
                {
                    d = "UR";
                    bounces++;
                }
                else if (j1 == m)
                {
                    d = "DL";
                    bounces++;
                }
                else
                {
                    i1++;
                    j1++;
                }
            }
            else if (d == "DL")
            {
                if (i1 == n && j1 == 1)
                {
                    d = "UR";
                    bounces++;
                }
                else if (i1 == n)
                {
                    d = "UL";
                    bounces++;
                }
                else if (j1 == 1)
                {
                    d = "DR";
                    bounces++;
                }
                else
                {
                    i1++;
                    j1--;
                }
            }
            else if (d == "UR")
            {
                if (i1 == 1 && j1 == m)
                {
                    d = "DL";
                    bounces++;
                }
                else if (i1 == 1)
                {
                    d = "DR";
                    bounces++;
                }
                else if (j1 == m)
                {
                    d = "UL";
                    bounces++;
                }
                else
                {
                    i1--;
                    j1++;
                }
            }
            else if (d == "UL")
            {
                if (i1 == 1 && j1 == 1)
                {
                    d = "DR";
                    bounces++;
                }
                else if (i1 == 1)
                {
                    d = "DL";
                    bounces++;
                }
                else if (j1 == 1)
                {
                    d = "UR";
                    bounces++;
                }
                else
                {
                    i1--;
                    j1--;
                }
            }
        }
    }

    return 0;
}
