#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif
bool check(int a[], int n, int t, ll treehight){
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > treehight){
            ans += a[i] - treehight;
        }
    }
    return ans >= t;
}
ll mod = 1e9 + 7;
int main(){
    int x, l; cin >> x >> l;
    int a[x];
    int _max = -1;
    ll res = 0;
    for (int i = 0; i < x; i++) {
        cin >> a[i];
        _max = max(_max, a[i]);
    }
    ll left = 0; ll right = _max;
    while(left <= right){
       ll mid = (left + right) / 2;
       if(check(a, x, l, mid)){
            res = mid;
            left = mid + 1;
       }
       else{
            right = mid - 1;
       }
    }
    cout << res;
}       