#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 1000000007;

long long calculateBalancedSubstrings(const string &s)
{
    int n = s.size();
    vector<int> a(n);
    vector<int> p(n + 1, 0);

    // Convert binary string to array `a`
    for (int i = 0; i < n; ++i)
    {
        a[i] = (s[i] == '0') ? -1 : 1;
    }

    // Compute prefix sums
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + a[i - 1];
    }

    // Use a hashmap to count occurrences of prefix sums
    unordered_map<int, int> count;
    long long total_count = 0;
    long long sum_right = 0;

    // Traverse prefix sums
    for (int i = 0; i <= n; ++i)
    {
        if (i > 0)
        {
            count[p[i - 1]]++;
        }
        sum_right += n - i + 1;
        total_count = (total_count + count[p[i]] * sum_right) % MOD;
    }

    return total_count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        cout << calculateBalancedSubstrings(s) << endl;
    }

    return 0;
}