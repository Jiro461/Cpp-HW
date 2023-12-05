#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
ll n = 10000000;
int prime[10000001];
void sang(){
    for(int i = 0; i < n; i++){
        prime[i] = 1;
    }
    prime[0] = 0; prime[1] = 0;
    for(int i = 2; i < sqrt(n); i++){
        if(prime[i] == 1){
            for(int j = i * i; j < sqrt(n); j += i)
                prime[j] = 0;
        }
    }
}
void sang2(ll r, ll l){
    int p[r - l + 1];
    for(int i = 0; i < r - l + 1; i++) p[i] = 1;
    for(ll i = 2; i <= sqrt(r); i++){       
        for(ll j = max(i * i, (l + i - 1) / i * i); i <= r; j += i){
            p[j - l] = 0;
        }
        for(ll i = max(2ll, l); i <= r; i++){
            if(p[i - 1]){
                cout << i << ' ';
            }
        }
    }
}
int main(){
    sang();
    for(int i = 0; i < 50; i++){
        if(prime[i]) cout << i << ' ';
    }
}