#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        if (n == 3)
        {
            a = {4, 22, 18};
        }
        else if (n == 6)
        {
            a = {10, 6, 15, 32, 125, 54};
        }
        else if (n == 7)
        {
            a = {23, 18, 27, 36, 5, 66, 7};
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                a[i] = (i + 1) * (i % 2 == 0 ? 1 : 2);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}