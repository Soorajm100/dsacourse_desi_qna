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
    ll k;
    cin>>k ;
    vector<vector<ll>>dp(n+1  , vector<ll>(2,0)) ; 
    vector<ll>nums(n) ; 
    for(ll i=0;i<n;i++){
        cin>>nums[i] ; 
    }
    for(ll i=1;i<=n;i++){
        dp[i][0] = nums[i-1] + max(dp[i-1][0] , dp[i-1][1]) ; 
        dp[i][1] = -nums[i-1]  + dp[i-1][0] ; 
    }

    cout<<max(dp[n][0] , dp[n][1])<<endl; 


    return 0 ; 
}