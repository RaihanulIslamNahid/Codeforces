#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string a;
        cin >> a;

        bool flag = false;
        if (a.find("111") != string::npos)
        {
            flag = true;
        }

        int cnt_11 = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[i] == '1' && a[i + 1] == '1')
            {
                cnt_11++;
            }
        }

        if (cnt_11 >= 2)
        {
            flag = true;
        }

        if (a[0] == '1' && a[n - 1] == '1')
        {
            flag = true;
        }

        if ((a[0] == '1' || a[n - 1] == '1') && cnt_11 >= 1)
        {
            flag = true;
        }

        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
