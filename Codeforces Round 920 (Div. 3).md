# Codeforces Round 920 (Div. 3)
It was a perfect 6 from A to F.

A: Find min and max for each x and y

B: It is best to combine 01 and 10 first.

C: Choose the best option independently for each section

D: Sort by preprocessing → cumulative sum. Determine the boundaries of A, and make the smaller side of A correspond to the larger side of B, and the larger side of A correspond to the smaller side of B.

F. Square division

# code

A. Square

```
#include <bits/stdc++.h>
using namespace std;
// define
#define lln int int
#define llu unsigned lln
#define li __int128
#define lol long long
#define pi (3.141592653589)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define fi first
#define se second
// #define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define endl '\n'
#define all(arr) sort(arr.begin(), arr.end());
#define rall(n) n.rbegin(), n.rend()
#define f2(i, n) for (int i = n - 1; i >= 0; i--)
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define f3(i, n) for (int i = 0; i <= n; i++)
#define f4(i, n) for (int i = 0; i < n; i--)
#define f5(i, n) for (int i = 0; i <= n; i--)
#define f6(i, n) for (int i = 1; i < n; i--)
#define f7(i, n) for (int i = 1; i <= n; i++)

// run_case
void run_case()
{
    int x, y;
    int minX = INT_MAX, minY = INT_MAX;
    int maxX = INT_MIN, maxY = INT_MIN;

    f0(i, 4)
    {
        cin >> x >> y;
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }

    int temp = max(maxX - minX, maxY - minY);
    int ans = temp * temp;

    cout << ans << endl;
}

// Just Do It
void just_do_it()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        run_case();
    }
}

/*Main*/
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    just_do_it();
    return 0;
}
```

B. Arranging Cats

```

#include <bits/stdc++.h>


using namespace std;
// define
#define lln int int
#define llu unsigned lln
#define li __int128
#define lol long long
#define pi (3.141592653589)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define fi first
#define se second
// #define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define endl '\n'
#define all(arr) sort(arr.begin(), arr.end());
#define rall(n) n.rbegin(), n.rend()
#define f2(i, n) for (int i = n - 1; i >= 0; i--)
#define f0(i, n) for (int i = 0; i < n; ++i)
#define f1(i, n) for (int i = 1; i <= n; ++i)
#define f3(i, n) for (int i = 0; i <= n; i++)
#define f4(i, n) for (int i = 0; i < n; i--)
#define f5(i, n) for (int i = 0; i <= n; i--)
#define f6(i, n) for (int i = 1; i < n; i--)
#define f7(i, n) for (int i = 1; i <= n; i++)
/*
lol floor(lol str1, lol str2)
{
    if (str2 < 0)
        str1 *= -1, str2 *= -1;
    if (str1 >= 0)
        return str1 / str2;
    else
        return -((-str1 + str2 - 1) / str2);
}
lol ceil(lol str1, lol str2)
{
    if (str2 < 0)
        str1 *= -1, str2 *= -1;
    if (str1 >= 0)
        return (str1 + str2 - 1) / str2;
    else
        return -((-str1) / str2);
}
lol modulo(lol str1, lol str2)
{
    str2 = abs(str2);
    return str1 - floor(str1, str2) * str2;
}
lol sgn(lol n)
{
    if (n > 0)
        return 1;
    if (n < 0)
        return -1;
    return 0;
}
int gcd(int str1, int str2)
{
    if (str2 == 0)
        return str1;
    return gcd(str2, str1 % str2);
}
lol lcm(lol str1, lol str2) { return str1 / gcd(str1, str2) * str2; }
#define fast \
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
void dbg_out()
{
    cerr << endl;
}
*/
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/*code*/

// run_case
void run_case()
{
    int n;
    cin >> n;

    string str1, str2;
    cin >> str1 >> str2;

    int cnt01 = 0;
    int cnt10 = 0;

    f0(i, n)
    {
        if (str1[i] == '0' and str2[i] == '1')
        {
            cnt01++;
        }
        else if (str1[i] == '1' and str2[i] == '0')
        {
            cnt10++;
        }
    }

    cout << max(cnt01, cnt10) << endl;
}

// Just Do It
void just_do_it()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        run_case();
    }
}

/*Main*/
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    just_do_it();
    return 0;
}
```

C. Sending Messages

```
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f0(i, n) for (int i = 0; i < n; ++i)

int calculateNeededCharge(int M, int Temp2, int Temp3, int Temp4)
{
    return min((M - Temp2) * Temp3, Temp4);
}

vector<int> readInput(int n)
{
    vector<int> array(n);
    f0(i, n)
    {
        cin >> array[i];
    }
    return array;
}

bool processTestCase(int n, int &m, int a, int b, const vector<int> &array)
{
    int Temp2 = 0;
    f0(i, n)
    {
        int cnt1 = calculateNeededCharge(array[i], Temp2, a, b);

        if (m <= cnt1)
        {
            return false;
        }
        else
        {
            m -= cnt1;
        }

        Temp2 = array[i];
    }
    return true;
}

void printOutput(bool flag)
{
    cout << (flag ? "YES" : "NO") << endl;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<int> array = readInput(n);

        bool flag = processTestCase(n, m, a, b, array);

        printOutput(flag);
    }

    return 0;
}

```

D. Very Different Array

```
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f0(i, n) for (int i = 1; i < n; ++i)
#define f1(i, n) for (int i = 0; i < n; ++i)
#define f2(i, n) for (int i = n - 2; i >= 0; i--)

#define all(arr) sort(arr.begin(), arr.end());

vector<int> cps(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    f0(i, n)
    {
        prefixSum[i] = arr[i] + prefixSum[i - 1];
    }
    return prefixSum;
}

vector<int> css(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> suffixSum(n, 0);
    suffixSum[n - 1] = arr[n - 1];
    f2(i, n)
    {
        suffixSum[i] = arr[i] + suffixSum[i + 1];
    }
    return suffixSum;
}

vector<int> rsa(int size)
{
    vector<int> arr(size);
    f1(i, size)
            cin >>
        arr[i];
    all(arr);
    return arr;
}

int cts(const vector<int> &arr)
{
    return accumulate(arr.begin(), arr.end(), 0LL);
}

int ca(int n, int m, const vector<int> &array1, const vector<int> &array2)
{
    vector<int> pref1 = cps(array1);
    vector<int> pref2 = cps(array2);
    vector<int> array3 = css(array1);
    vector<int> array4 = css(array2);

    int ans = 0;

    ans = max(ans, array4[m - n] - pref1[n - 1]);

    f0(i, n)
    {
        int sum = array3[n - i] + array4[m - n + i] - pref1[n - i - 1] - pref2[i - 1];
        ans = max(ans, sum);
    }

    ans = max(ans, array3[0] - pref2[n - 1]);

    return ans;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> array1 = rsa(n);
        vector<int> array2 = rsa(m);

        int ans = ca(n, m, array1, array2);

        cout << ans << "\n";
    }

    return 0;
}

```
