
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


int main(){

    ll n ; 
    cin>>n; 

    vector<ll>a(n+1,0); 
    vector<ll>b(n+1,0); 
    vector<ll>c(n+1,0); 

    for(ll i=1;i<=n;i++)cin>>a[i] ;
    for(ll i=1;i<=n;i++)cin>>b[i] ;
    for(ll i=1;i<=n;i++)cin>>c[i] ;

    ll dp[n+1][4] ; 

    memset(dp, 0, sizeof(dp));


    dp[1][0] = dp[1][1] = -1e9 ; 

    dp[1][3] = a[1] ;
    dp[1][2] = b[1] ; 

    for(ll i=2;i<=n;i++){
        dp[i][0] = max(dp[i-1][1] , dp[i-1][3]) + c[i] ; 
        dp[i][1] = max(dp[i-1][1] , dp[i-1][3]) + b[i] ;
        dp[i][2] = max(dp[i-1][0] , dp[i-1][2]) + b[i] ;
        dp[i][3] = max(dp[i-1][0] , dp[i-1][2]) + a[i] ;
    }

    dp[n][2] = -1e9 ; 
    dp[n][0] = -1e9 ; 



    ll result = max({dp[n][0] , dp[n][1]  , dp[n][2] , dp[n][3]}) ;

    cout<<result<<endl; 

    return 0 ; 
}