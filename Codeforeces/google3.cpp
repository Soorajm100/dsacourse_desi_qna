#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vipair  = vector<pair<ll, ll>>; 

template <class T>
using v = vector<T>;

const int INF_INT = 1e9;
const ll INF_LL = (1LL << 60);
const int MOD = 1000000007;

void solve(){

    ll  n ; 
    cin>>n; 
    ll dp[1005][5] ; 
    vector<ll>a(n+1,0) ;
    vector<ll>b(n+1,0) ; 
    vector<ll>c(n+1 , 0); 

    for(ll i=1;i<=n;i++){
        cin>>a[i]  ; 
    }

    for(ll i=1;i<=n;i++){
        cin>>b[i]  ; 
    }

    for(ll i=1;i<=n;i++){
        cin>>c[i]  ; 
    }

    /*
       a - >0 
       b -> 1 
       c -> 2 
    */

    dp[1][0] = a[1] ; 
    dp[1][1] = b[1] ; 
    dp[1][2] = c[1] ; 

    for(ll i=2;i<=n;i++){
        dp[i][0] = a[i]  + max({dp[i-1][0] , dp[i-2][1] , dp[i-2][2]}); 
        dp[i][1] = b[i]  + max({dp[i-1][1] , dp[i-2][0] , dp[i-2][2]});
        dp[i][2] = c[i]  + max({dp[i-1][2] , dp[i-2][0] , dp[i-2][1]});
    }

    cout<< max({dp[n][0] , dp[n][1] , dp[n][2]}) <<"\n" ;
    
    return ; 
}

int main(){
    ll test ; 
    cin>>test ; 

    while(test--){
        solve(); 
    }

    return 0 ; 
}