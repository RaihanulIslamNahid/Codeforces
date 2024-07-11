#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int ans = 0;

        for (int i = 0; i <= 5; ++i)
        {
            for (int j = 0; j <= 5 - i; ++j)
            {
                int k = 5 - i - j;
                int x = a + i;
                int y = b + j;
                int z = c + k;
                ans = max(ans, x * y * z);
            }
        }

        cout << ans << endl;
    }

    return 0;
}