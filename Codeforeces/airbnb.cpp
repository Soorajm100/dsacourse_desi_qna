
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


    for(ll i=1;i<=n;i++)cin>>a[i] ; 
    for(ll i=1;i<=n;i++)cin>>b[i] ;

    ll dp[n+1][3] ; 


    dp[2][1] = a[2] ; 
    dp[2][2] = a[1] ; 

    dp[1][2]  = 0 ; 
    dp[1][1] = 0 ;
    
    
    
    // i-2 i-1 i 
    //  i-1 i i-2 

   
    for(ll i=3;i<=n;i++){

        dp[i][1] = a[i] + min(dp[i-1][1] , dp[i-1][2]) ; 
        
        ll v1 = b[i-1] + min(dp[i-2][1] , dp[i-2][2]) ; 
        ll  v2 = dp[i-1][2]  + a[i-1] ; 

        dp[i][2] = min(v1, v2) ; 

    }



    cout<<min(dp[n][1] , dp[n][2]) ; 

    return 0 ; 
}