#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string b;
        cin >> n >> b;
        string r = b;
        sort(r.begin(), r.end());
        r.erase(unique(r.begin(), r.end()), r.end());
        unordered_map<char, char> decode_map;
        int len = r.size();
        for (int i = 0; i < len; ++i) {
            decode_map[r[i]] = r[len - 1 - i];
        }
        string s = b;
        for (int i = 0; i < n; ++i) {
            s[i] = decode_map[b[i]];
        }
        cout << s << endl;
    }
    return 0;
}
