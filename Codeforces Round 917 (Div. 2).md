# Codeforces

<h4>Codeforces Round 917 (Div. 2)</h4>
Problem A:

[A. Least Product](https://codeforces.com/contest/1917/problem/A)

Editorial : We can always make the product as small as possible with at most 1
 operation.
 code:
 ````
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	int N;
	cin >> N;
	vector<ll> A(N);
	for(ll& x : A) cin >> x;
	int sgn = 1;
	for(ll x : A){
		if(x == 0) sgn = 0;
		if(x < 0) sgn *= -1;
	}
	if(sgn == -1 || sgn == 0){
		cout << 0 << '\n';
	} else if(sgn == 1){
		cout << 1 << '\n';
		cout << 1 << ' ' << 0 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
````

Problem B:

[B - Erase First or Second Letter](https://codeforces.com/contest/1917/problem/B)https://codeforces.com/contest/1917/problem/B)

Editorial : Try to consider the first occurrence for each letter.

code:
```
#include <bits/stdc++.h>
using namespace std;
void testCase() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> done(26);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (done[s[i] - 'a']) continue;
    done[s[i] - 'a'] = 1;
    ans += n - i;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    testCase();
  }
  return 0;
}
```

Problem C:

[C - Watering an Array](https://codeforces.com/contest/1917/problem/C)

Editorial :Try fixing the first day you make reset operation on.

```
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nn "\n"
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1int << k))
#define ClearBit(x, k) (x &= ~(1int << k))
#define CheckBit(x, k) ((x>>k)&1)
#define mod 998244353
#define N 1000006


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll n, k, d;
        cin >> n >> k >> d;

        ll a[n+1];
        for(int i = 1; i <= n; i++) cin >> a[i];

        int v[k];
        for(int i = 0; i < k; i++) cin >> v[i];

        ll ans = 0;

        for(int i = 1; i <= n; i++){
            if(a[i] == i) ans++;
        }
        ans += (d-1)/2;

        for(int i = 0; i < 3*n; i++){
            if(i == d-1) break;
            int cnt = 0;
            for(int j = 1; j <= v[i%k]; j++){
                a[j]++;
            }

            for(int j = 1; j <= n; j++){
                if(a[j] == j) cnt++;
            }

            ll res = cnt;
            ll rem = d-i-2;
            res += (rem/2);
            ans = max(ans, res);
        }

        cout << ans << nn;
    }

    return 0;
}
```

Problem D:

[D - Yet Another Inversions Problem](https://codeforces.com/contest/1917/problem/D)

Editorial : Consider splitting array 𝑎 into subarrays of the length 𝑘.

```
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nn "\n"
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1int << k))
#define ClearBit(x, k) (x &= ~(1int << k))
#define CheckBit(x, k) ((x>>k)&1)
#define mod 998244353
#define N 1000006

ll bit[N];
int _n = N-1;

ll get(int i){
    ll sum = 0;
    while (i){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

void update(int i, ll x){
    while (i <= _n){
        bit[i] += x;
        i += (i & -i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        memset(bit, 0, sizeof(bit[0])*(2*n+5));
        _n = 2*n+3;

        vector<int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            update(p[i], 1);
        }

        ll ans = 0;

        for(int i = 0; i < n; i++){
            update(p[i], -1);
            for(int j = 0; j < k; j++){
                ll a = p[i];
                ll z = (a+(1<<j)-1)/(1<<j);
                if(z <= 1) break;
                ll cnt = get(z-1);
                // cout << "--->" << a << " : " << (1<<j) << " : " << cnt << nn;
                ans += cnt*(k-j);
                ans %= mod;
            }
            for(int j = 1; j < k; j++){
                ll a = p[i];
                ll z = (1<<j)*p[i];
                if(z > 2*n+1) z = 2*n+1;
                ll cnt = get(z-1);
                ans += cnt*(k-j);
                ans %= mod;
                if(z==2*n+1){
                    ll tot = (ll)(k-j-1)*(k-j)/2;
                    if(tot > 0){
                        ans += tot*cnt;
                        ans %= mod;
                    }
                    break;
                }
            }
            // cout << ans << " ";
        }
        // cout << nn;

        memset(bit, 0, sizeof(bit[0])*(k+2));
        _n = k+1;

        ll ans2 = 0;

        vector<int> q(k);
        for(int i = 0; i < k; i++){
            cin >> q[i];
            q[i]++;
            ans2 += get(k+1) - get(q[i]);
            update(q[i], 1);
        }

        // cout << ans << nn;

        ans += ans2*n;
        ans %= mod;

        cout << ans << nn;
    }

    return 0;
}
```

Problem E:

[E - Construct Matrix](https://codeforces.com/contest/1917/problem/E)

Editorial : Try to merge ideas of Hint 3 and Hint 4 together.


```
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	int K;
	cin >> K;
	int sw = 0;
	if(K > N * N - K){
		K = N * N - K;
		sw = 1;
	}
	if(K % 2 == 1 || (N > 2 && K == 2)){
		cout << "No" << '\n';
		return;
	}
	vector<vector<int> > a(N, vector<int>(N));
	if(K == 2){
		assert(N == 2);
		a[0][0] = a[1][1] = 1;
		K -= 2;
	} else {
		if(K % 4 == 2){
			assert(K >= 6);
			a[1][0] = a[0][1] = a[1][2] = a[2][1] = a[0][2] = a[2][0] = 1;
			K -= 6;
		}
		assert(K % 4 == 0);
		for(int i = 0; i < N; i += 2){
			for(int j = 0; j < N; j += 2){
				if(a[i][j] || a[i+1][j]) continue;
				if(K){
					K -= 4;
					a[i][j] = a[i+1][j] = a[i][j+1] = a[i+1][j+1] = 1;
				}
			}
		}
	}
	if(sw){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				a[i][j] = 1 - a[i][j];
			}
		}
	}
	assert(K == 0);
	cout << "Yes" << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << a[i][j] << " \n"[j+1 == N];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
```

Problem F:

[F - Construct Tree](https://codeforces.com/contest/1917/problem/F)

Editorial : Knapsack with bitset.

```
#include <bits/stdc++.h>
using namespace std;

using bs = bitset<2001>;

void solve(){
	int N, D;
	cin >> N >> D;
	vector<int> l(N);
	for(int& x : l) cin >> x;

	int sum = 0;
	for(int x : l){
		if(x == D){
			cout << "No" << '\n';
			return;
		}
		sum += x;
	}
	if(sum == D){
		cout << "Yes" << '\n';
		return;
	}
	sort(l.rbegin(), l.rend());
	{
		bs A;
		A[l[0] + l[1]] = 1;
		for(int i = 2; i < N; i++){
			A = A | (A << l[i]);
		}
		if(A[D]){
			cout << "Yes" << '\n';
			return;
		}
	}
	{
		vector<bs> dp(D+1, 0);
		dp[0][0] = 1;
		for(int i = 2; i < N; i++){
			vector<bs> ndp = dp;
			for(int d = 0; d + l[i] <= D; d++){
				ndp[d+l[i]] |= dp[d];
			}
			for(int d = 0; d <= D; d++){
				ndp[d] |= (dp[d] << l[i]);
			}
			dp = ndp;
		}
		for(int d1 = 0; d1 <= D; d1++){
			int d2 = D - d1;
			if(d1 < l[1] || d2 < l[1]) continue;
			if(d2 >= l[0] && dp[d1][d2-l[0]]){
				cout << "Yes" << '\n';
				return;
			}
		}
		for(int i = 1; i < 2; i++){
			vector<bs> ndp = dp;
			for(int d = 0; d + l[i] <= D; d++){
				ndp[d+l[i]] |= dp[d];
			}
			for(int d = 0; d <= D; d++){
				ndp[d] |= (dp[d] << l[i]);
			}
			dp = ndp;
		}
		for(int d1 = 0; d1 <= D; d1++){
			int d2 = D - d1;
			if(d1 < l[0] || d2 < l[0]) continue;
			if(dp[d1][d2]){
				cout << "Yes" << '\n';
				return;
			}
		}
	}
	cout << "No" << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
```
