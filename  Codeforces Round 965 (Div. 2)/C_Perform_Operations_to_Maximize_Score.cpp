#include <bits/stdc++.h>
using namespace std;

namespace std
{
    template <int D, typename T>
    struct Vec : public vector<Vec<D - 1, T>>
    {
        static_assert(D >= 1, "Dimension must be positive");
        template <typename... Args>
        Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
    };

    template <typename T>
    struct Vec<1, T> : public vector<T>
    {
        Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
    };

    /* Example
        Vec<4, int64_t> f(n, k, 2, 2); // = f[n][k][2][2];
        Vec<2, int> adj(n); // graph
    */
} // namespace std

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j)
             { return a[i] > a[j]; });

        int need = ((n - 1) >> 1) + 1;
        int64_t low = 0, high = 1e10;

        while (low < high)
        {
            int64_t mid = (low + high + 1) >> 1;
            bool ok = false;

            // Check for elements with b[i] == 1
            for (int i : ord)
            {
                if (b[i] == 1)
                {
                    if (a[i] + k >= mid)
                        ok = true;
                    int64_t x = mid - a[i] - k;
                    int rem = need;
                    for (int j : ord)
                    {
                        if (j == i)
                            continue;
                        if (rem == 0)
                            break;
                        if (a[j] >= x)
                            rem--;
                    }
                    if (rem == 0)
                        ok = true;
                    break;
                }
            }

            // Check for elements with b[i] == 0
            for (int i : ord)
            {
                if (b[i] == 0)
                {
                    int64_t rem = need;
                    int64_t sum = 0;
                    int64_t x = mid - a[i];
                    for (int j : ord)
                    {
                        if (j == i)
                            continue;
                        if (rem == 0)
                            break;
                        if (a[j] >= x)
                        {
                            rem--;
                        }
                        else if (b[j])
                        {
                            sum += x - a[j];
                            rem--;
                        }
                    }
                    if (rem == 0 && sum <= k)
                    {
                        ok = true;
                    }
                    break;
                }
            }

            if (ok)
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << low << '\n';
    }
}
