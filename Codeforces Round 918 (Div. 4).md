# Codeforces Round 918 (Div. 4)

**Problem A:** [A. Odd One Out](https://codeforces.com/contest/1915/problem/A)

Solution: **To solve this problem, you can use a simple logic that takes advantage of the fact that two of the three digits are equal**

Code:
````
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b)
        {
            cout << c << endl;
        }
        else if (a == c)
        {
            cout << b << endl;
        }
        else
        {
            cout << a << endl;
        }
    }
}
````

**Problem B:**[B. Not Quite Latin Square](https://codeforces.com/contest/1915/problem/B)

Solution: **
