### Codeforces Round 932 (Div. 2)
#### [A.Entertainment in MAC](https://codeforces.com/contest/1935/problem/A)

#### Make a new string t which is the reversed version of s. Now if t is lexicographically smaller than s, then simply print t, else print t + s.
#### code:
```
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        reverse(t.begin(), t.end());
        if (t < s)
        {
            cout << t + s << endl;
            continue;
        }
        cout << s << endl;
    }
    return 0;
}

```

### [B.Informatics in MAC](https://codeforces.com/contest/1935/problem/B)

#### Find the mex of the whole array (say x). Now try to divide the array into 2 parts only. Fill the first vector until the mex of the vector is not x. Now fill the remaining elements in the another vector. If mex of both the vector is same, then print the answer as 2 and both the vector, else print -1.

#### code:
```
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;

// Function to calculate the Minimum Excludant (mex) of a set of integers
int mex(const vi& a) {
    set<int> s(a.begin(), a.end());
    for (int i = 0; ; ++i) {
        if (!s.count(i)) {
            return i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int x = mex(a);
    int idx = -1;
    set<int> st;
    vi ans1, ans2;

    // Finding ans1
    for (int i = 0; i < n; ++i) {
        if (a[i] <= x) {
            st.insert(a[i]);
            ans1.push_back(a[i]);
        }
        if (st.size() == x) {
            idx = i;
            break;
        }
    }

    // Finding ans2
    for (int i = idx + 1; i < n; ++i) {
        ans2.push_back(a[i]);
    }

    // Checking if mex(ans1) == mex(ans2)
    if (mex(ans1) == mex(ans2)) {
        cout << 2 << endl << "1 " << idx + 1 << endl << idx + 2 << ' ' << n << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
```


### [C.Messenger in MAC](https://codeforces.com/contest/1935/problem/C)

#### Binary Search + DP on the answer. DP vector will be maintained for index and count of the element. After sorting the message vector in descending order w.r.t. b[i], the equation can be summarised as (a[0] + a[1] + a[2] .... + a[k]) + (b[0] - b[k]).

#### Code:
```
#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l;
        cin >> n >> l;
        vector<pair<int, int>> vp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            vp.push_back({b, a});
            if (a <= l)
            {
                ans = 1;
            }
        }
        sort(vp.begin(), vp.end());

        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(vp[i].first-vp[j].first+vp[i].second+vp[j].second<=l)
                {
                    ans=2;
                }
            }
        }
        
        

        for (int i = 1; i < n; i++)
        {
            
            multiset<pair<int,int>> ms;
            for(int j=1;j<i;j++)
            {
                ms.insert({vp[j].second,j});
            }
            int inc=0;
            int sum=0;
            for(int j=0;j<i;j++)
            {
                int left=l-(vp[i].first-vp[j].first+vp[i].second+vp[j].second+sum);
                while(ms.size()>0 && left>=(*(ms.begin())).first)
                {
                    left-=(*(ms.begin())).first;
                    inc++;
                    sum+=(*(ms.begin())).first;
                    auto itr=ms.begin();
                    ms.erase(itr);
                }
                if(left>=0)
                {
                    ans=max(ans,2+inc);
                }
                auto itr=ms.find({vp[j+1].second,j+1});
                if(itr!=ms.end())
                {
                    ms.erase(itr);
                }
                else
                {
                    inc--;
                    sum-=(vp[j+1].second);
                }
                
            }
        }
        cout<<ans<<endl;
    }
}
```

### [D.Exam in MAC](https://codeforces.com/contest/1935/problem/D)

#### Medium level combinatorics. First count all the total no of pairs possible. Divide your set into two vector : Odd and Even. Now for an integer p in the set, the pairs forming (y - x = p) will range from (0, p) to (d - p, d). You can count that in O(1). Now integers containing (x + y = p) will range from (0, p) to (p / 2, p / 2). Now it is possible that you've removed two pair twice which can be taken care by doing a binary search on odd or even array depending upon your p.

#### Code:
```
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define endl "\n"
#define mod 1000000007
int32_t main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n>>c;
        int a[n],ans=(((c+1)*(c+2))/2),sum=0,s=0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum+=a[i];
            s+=((a[i]+2)/2);
        }
        ans-=s;
        ans-=(((c+1)*n)-sum);
        int e=0,o=0;
        for(int i=n-1; i>=0; i--){
            if(a[i]%2){
                o++;
                ans+=(o);
            }
            else{
                e++;
                ans+=(e);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
```