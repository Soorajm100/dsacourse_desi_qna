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
    ll ans = 0 ; 
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){

            dp[i][j] = a[i]*b[j] ; 

            for(ll i1=1;i1<=i-1 ;i1++){
                for(ll j1=1;j1<=j-1 ;j1++){
                    dp[i][j]  = max(dp[i][j] , a[i]*b[j] + dp[i1][j1])  ;
                }
            }

            ans = max(ans , dp[i][j]) ; 

        }
    }


    cout<<ans<<endl; 

    return  0 ; 
}