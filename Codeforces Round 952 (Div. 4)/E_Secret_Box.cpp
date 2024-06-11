#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        long long k;
        cin >> x >> y >> z >> k;
        
        long long max_ways = 0;

        for (long long a = 1; a * a * a <= k; ++a) {
            if (k % a != 0) continue;
            long long k2 = k / a;
            for (long long b = 1; b * b <= k2; ++b) {
                if (k2 % b != 0) continue;
                long long c = k2 / b;
                if (a <= x && b <= y && c <= z) {
                    long long ways = (x - a + 1) * (y - b + 1) * (z - c + 1);
                    max_ways = max(max_ways, ways);
                }
                if (a <= x && c <= y && b <= z) {
                    long long ways = (x - a + 1) * (y - c + 1) * (z - b + 1);
                    max_ways = max(max_ways, ways);
                }
                if (b <= x && a <= y && c <= z) {
                    long long ways = (x - b + 1) * (y - a + 1) * (z - c + 1);
                    max_ways = max(max_ways, ways);
                }
                if (b <= x && c <= y && a <= z) {
                    long long ways = (x - b + 1) * (y - c + 1) * (z - a + 1);
                    max_ways = max(max_ways, ways);
                }
                if (c <= x && a <= y && b <= z) {
                    long long ways = (x - c + 1) * (y - a + 1) * (z - b + 1);
                    max_ways = max(max_ways, ways);
                }
                if (c <= x && b <= y && a <= z) {
                    long long ways = (x - c + 1) * (y - b + 1) * (z - a + 1);
                    max_ways = max(max_ways, ways);
                }
            }
        }
        
        cout << max_ways << endl;
    }
    return 0;
}
