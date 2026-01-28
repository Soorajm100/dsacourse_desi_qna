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


int  main(){
    ll n ; 
    cin>>n;
    vector<ll>b(n+1, 0); 

    for(ll i=1 ; i<=n ; i++){
        cin>>b[i]; 
    }

    ll dp[n+1][5]; 

    //*  2 for forwars 
    //*  1 for backward 
    dp[1][2] =  b[1] ; 
    dp[1][1]= INT_MAX ; 
    dp[2][2] = INT_MAX; 

    dp[2][1] = dp[1][2] + b[3] + b[2]; 

    for( ll i=3;i<=n-1;i++){
        dp[i][2] = b[i] + min(dp[i-2][1] , dp[i-2][2]) ; 
        dp[i][1] = b[i] + b[i+1] + dp[i-1][2];
    }

    dp[n][2] = b[n] + min(dp[n-2][2]  , dp[n-2][1]); 
    dp[n][1] = INT_MAX ; 

    cout<<min({dp[n][2] , dp[n-1][2] , dp[n-1][1] } ) ; 

    return 0 ; 
}