#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    bool all = true;
    int big = a.back();
    for (int &x : a) if (big % x) {
      all = false;
      break;
    }
    if (!all) {
      cout << n << '\n';
      continue;
    }
    vector <int> cand;
    for (int i = 1; i * i <= big; ++i) if (big % i == 0) {
      cand.emplace_back(i);
      if (i * i != big) cand.emplace_back(big / i);
    }
    sort(cand.begin(), cand.end());
    int ans = 0;
    for (int &d : cand) {
      if (find(a.begin(), a.end(), d) != a.end()) continue;
      int here = 1, take = 0;
      for (int &x : a) if (d % x == 0) here /= gcd(here, x), here *= x, ++take;
      if (here == d) ans = max(ans, take);
    }
    cout << ans << '\n';
  }  
  return 0;
}

