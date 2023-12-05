#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int n, k;
int a[N];
void run_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    multiset <int> st;
    for (int i = 1; i <= k; ++i)
        st.insert(a[i]);
    
    auto iter = st.begin();
    // O(x);
    advance(iter, (k - 1) / 2);
    for (int i = k + 1; i <= n + 1; ++i) {
        cout << (*iter) << " ";
        debug(i);
        st.insert(a[i]);
        if (a[i] < (*iter) && iter != st.begin())
            --iter;
        if (a[i - k] <= (*iter))
            ++iter;
        st.erase(st.lower_bound(a[i - k]));
    }

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
