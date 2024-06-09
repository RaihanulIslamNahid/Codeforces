#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long ans = 0;
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> map1;
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> map2;
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> map3;

        unordered_map<int, unordered_map<int, int>> map1a;
        unordered_map<int, unordered_map<int, int>> map2a;
        unordered_map<int, unordered_map<int, int>> map3a;

        for (int i = 0; i < n - 2; ++i) {
            int x = a[i], y = a[i + 1], z = a[i + 2];

            // Calculate get(map1, map1a, x, y, z)
            if (map1.count(x) && map1[x].count(y)) {
                ans += map1a[x][y] - map1[x][y].get(z, 0);
            }

            // Calculate get(map2, map2a, y, z, x)
            if (map2.count(y) && map2[y].count(z)) {
                ans += map2a[y][z] - map2[y][z].get(x, 0);
            }

            // Calculate get(map3, map3a, z, x, y)
            if (map3.count(z) && map3[z].count(x)) {
                ans += map3a[z][x] - map3[z][x].get(y, 0);
            }

            // Add to map1 and map1a
            map1[x][y][z]++;
            map1a[x][y]++;

            // Add to map2 and map2a
            map2[y][z][x]++;
            map2a[y][z]++;

            // Add to map3 and map3a
            map3[z][x][y]++;
            map3a[z][x]++;
        }

        cout << ans << "\n";
    }

    return 0;
}
