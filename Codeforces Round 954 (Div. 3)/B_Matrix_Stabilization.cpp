/*
Problem B:
Take left=right=up=down=-69, 
and take left,right,up,down, elements of a[i][j] (if they exist). like if the a[i][j] is top left element then its top and left element doesn't exist hence left and up's will value will remain -69.
Now check if a[i][j] is greater than all of them, if it is then make a[i][j] = max of all of them. And do the same for all elements.
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> a(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        
        int left = -69, right = -69, up = -69, down = -69;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j > 0) left = a[i][j-1];
                if (j < m-1) right = a[i][j+1];
                if (i > 0) up = a[i-1][j];
                if (i < n-1) down = a[i+1][j];
                
                if (a[i][j] > left && a[i][j] > right && a[i][j] > up && a[i][j] > down) {
                    a[i][j] = max({left, right, up, down});
                }
                
                left = -69, right = -69, up = -69, down = -69;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
