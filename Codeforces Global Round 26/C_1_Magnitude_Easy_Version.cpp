#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;

    while(t--){
        int n; 
        cin >> n;
        vector<int> arr(n); 

        for (int i = 0; i < n; ++i) 
            cin >> arr[i];

        ll sum = 0, mn = 0;
        for (int i = 0; i < n; ++i) 
            sum += arr[i], mn = min(mn, sum);
        
        cout << sum - 2 * mn << '\n';
    }
}
