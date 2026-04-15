
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

/**
1    2
b    c
1    1
1    1
1    1



*/



int main(){

    ll n ; 
    cin>>n ; 
    vector<ll>b(n+1,0) ; 
    vector<ll>c(n+1,0) ; 


    for(ll i =1;i<=n;i++)cin>>b[i] ; 
    for(ll i=1;i<=n;i++)cin>>c[i] ; 

    ll dp[n+5][3][3] ; 
    memset(dp, 0, sizeof(dp));

    
    dp[1][1][1] = b[1] ; 
    dp[1][1][2] = b[1] ; 
    dp[1][2][1] = c[1] ; 
    dp[1][2][2] = c[1] ; 

    for(ll i=2;i<=n;i++){
        dp[i][1][1] = b[i] + b[i-1] + max(dp[i-2][2][1] , dp[i-2][2][2]) ; 
        dp[i][1][2] = b[i] + c[i-1] + max({dp[i-2][2][1] , dp[i-2][1][1] , dp[i-2][1][2]}) ; 
        dp[i][2][1] = c[i] + b[i-1] + max({dp[i-2][1][2] , dp[i-2][2][1] , dp[i-2][2][2]}) ; 
        dp[i][2][2] = c[i] + c[i-1] + max(dp[i-2][1][2] , dp[i-2][1][1]);
    }


    cout<<max({dp[n][1][1] , dp[n][1][2] , dp[n][2][1] , dp[n][2][2]}) ; 

    return 0 ; 
}