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

    ll n , k; 
    cin>>n>>k ;
    vector<ll>a(n,0); 
    for(ll i=0;i<n;i++)cin>>a[i] ;
    vector<ll>dp(n,0); 
    dp[1]= a[0]*a[1] ; 
    for(ll i=2;i<n;i++){
        for(ll j=max(0LL,i-k) ;j<=i-1 ;j++){
            dp[i] = min(dp[i] , dp[j]+a[i]*a[j]) ;
        }
    }

    cout<<dp[n-1] ;
    
    
    return 0 ;    
}