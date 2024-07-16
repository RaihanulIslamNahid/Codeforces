#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = ceil((n - 1) / double(k - 1));
        cout << ans << endl;
    }

    return 0;
}
