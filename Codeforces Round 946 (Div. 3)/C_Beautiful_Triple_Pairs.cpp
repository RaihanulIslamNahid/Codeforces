#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<pair<int, int>, int> cnt1, cnt2, cnt3;
  map<pair<int, int>, map<int, int>> mp1, mp2, mp3;

  long long ans = 0;
  for (int i = 1; i + 2 <= n; i++) {
    ans += cnt1[make_pair(a[i], a[i + 1])];
    ans -= mp1[make_pair(a[i], a[i + 1])][a[i + 2]];
    ans += cnt2[make_pair(a[i], a[i + 2])];
    ans -= mp2[make_pair(a[i], a[i + 2])][a[i + 1]];
    ans += cnt3[make_pair(a[i + 1], a[i + 2])];
    ans -= mp3[make_pair(a[i + 1], a[i + 2])][a[i]];

    mp1[make_pair(a[i], a[i + 1])][a[i + 2]]++;
    cnt1[make_pair(a[i], a[i + 1])]++;
    mp2[make_pair(a[i], a[i + 2])][a[i + 1]]++;
    cnt2[make_pair(a[i], a[i + 2])]++;
    mp3[make_pair(a[i + 1], a[i + 2])][a[i]]++;
    cnt3[make_pair(a[i + 1], a[i + 2])]++;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}