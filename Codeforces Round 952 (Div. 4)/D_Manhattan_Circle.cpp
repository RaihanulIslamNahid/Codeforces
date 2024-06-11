#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        
        int minRow = n, maxRow = -1, minCol = m, maxCol = -1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '#') {
                    if (i < minRow) minRow = i;
                    if (i > maxRow) maxRow = i;
                    if (j < minCol) minCol = j;
                    if (j > maxCol) maxCol = j;
                }
            }
        }
        
        int centerRow = (minRow + maxRow) / 2 + 1;
        int centerCol = (minCol + maxCol) / 2 + 1;
        
        cout << centerRow << " " << centerCol << endl;
    }
    
    return 0;
}
