#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    for (int i = 40; i >= 0; --i)
    {
        long long here = 1LL << i;
        if (l <= here and here <= r)
        {
            cout << i << endl;
            break;
        }
    }
  }  
  return 0;
}

