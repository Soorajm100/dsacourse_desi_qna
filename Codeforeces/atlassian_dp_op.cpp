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

    ll n , m ; 
    cin>>n>>m ; 
    vector<ll>a(n+1,0) ; 
    vector<ll>b(m+1,0) ; 

    for(ll i = 1 ;i<=n;i++)cin>>a[i] ; 
    for(ll j=1 ; j<=m ; j++)cin>>b[j] ; 
    
    ll dp[n+1][m+1]  ; 
    memset(dp, 0, sizeof(dp));

    ll dp2[n+1][m+1] ; 
    memset(dp2 , 0 , sizeof(dp2));
    ll ans = 0 ; 
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){

            dp[i][j] = a[i]*b[j] ; 

                for(ll t=1;t<=j-1;t++){
                    dp[i][j]  = max(dp[i][j] , a[i]*b[j] + dp[i-1][t])  ;
                }


                for(ll k=1;k<=i;k++){
                    dp2[i][j] = max(dp2[i][j] , dp[k][j]) ; 
                }


            ans = max(ans , dp[i][j]) ; 
        }
    }
    
    cout<<ans<<endl; 

    return  0 ; 
}