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
        int m = n / 4;
        if (n % 4 != 0)
        {
            m++;
        }
        cout << m << endl;
    }

    return 0;
}