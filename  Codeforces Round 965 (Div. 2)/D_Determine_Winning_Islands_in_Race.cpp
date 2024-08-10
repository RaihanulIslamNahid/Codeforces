#include <bits/stdc++.h>
using namespace std;
void testCase()
{
    int n, m;
    cin >> n >> m;
    vector<int> ad[n];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ad[u].push_back(v);
    }
    for (int i = 0; i < n - 1; i++)
    {
        ad[i].push_back(i + 1);
    }
    vector<int> d(n);
    iota(d.begin(), d.end(), 0);
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(i - d[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        st.erase(st.find(i - d[i]));
        cout << (*st.rbegin() > i ? "0" : "1");
        for (auto v : ad[i])
        {
            st.erase(st.find(v - d[v]));
            d[v] = min(d[v], d[i] + 1);
            st.insert(v - d[v]);
        }
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        testCase();
    }
    return 0;
}