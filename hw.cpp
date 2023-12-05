#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
ll mod = 1e9 + 7;
#ifdef JASPER
#include "debug.h"
#else
#define debug(x...) 166
#endif
int n = 8, X[1000];
int cot[1000], xuoi[1000], nguoc[1000];
int a[100][100];
int ans = INT_MIN;
void Try(int i){
    ++tong;
    for(int j = 1; j <= n; j++){
        if(visited[j] == 0){
            X[i] = j;
            visited[j] = 1;
            cp += c[X[i - 1]][X[i]];
            if(i == n){
                res = min(res, cp + c[X[n]][1]);
            }
            else if(cp + (n - i + 1) * cmin < res){
                Try(i + 1);
            }
            //backtrack
            visited[j] = 0;
            cp -= c[X[i - 1]][X[i]];
        }   
    }
}
long long gt[1000006];
int main() {
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << ans;
}