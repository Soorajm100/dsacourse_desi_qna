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
    cin>>n ; 
    vector<ll>a(n+1, 0); 
    vector<ll>b(n+1,0); 
    ll m = 0;
    for(ll i=1;i<=n;i++)cin>>a[i] ; 
    for(ll i=1;i<=n;i++)cin>>b[i] ;
    for(ll i=1;i<=n;i++) m = max(m, a[i]);
    for(ll i=1;i<=n;i++) m = max(m, b[i]);
    ll S[205][205];
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=m;j++){
            cin >> S[i][j];
        }
    }
  vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(2, 0)));
  dp[1][1][0] = S[b[1]][a[1]];
  dp[1][1][1] = S[a[1]][b[1]];

for(ll i=2;i<=n;i++){
    dp[i][1][0] = max(
        dp[i-1][1][0] + S[a[i-1]][a[i]],
        dp[i-1][1][1] + S[b[1]][a[i]]
    );
}

for(ll j=2;j<=n;j++){
    dp[1][j][1] = max(
        dp[1][j-1][1] + S[b[j-1]][b[j]],
        dp[1][j-1][0] + S[a[1]][b[j]]
    );
}
  
    for(ll i=2;i<=n;i++){
        for(ll j=2;j<=n;j++){
            dp[i][j][0] = max(dp[i-1][j][0]  + S[a[i-1]][a[i]], dp[i-1][j][1] + S[b[j]][a[i]]) ;
            dp[i][j][1] = max(dp[i][j-1][1] + S[b[j-1]][b[j]] , dp[i][j-1][0] + S[a[i]][b[j]]) ;
        }
    }

    ll ans = max(dp[n][n][0] , dp[n][n][1]) ;


    cout<<ans<<endl; 

    return 0 ; 
}