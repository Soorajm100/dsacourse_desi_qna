
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

    ll n; 
    cin>>n ; 
    ll v ; 
    cin>>v ; 
    vector<ll>easy(n+1, 0) ; 
    vector<ll>hard(n+1 , 0) ; 

    for(ll i=1;i<=n;i++){
        cin>>easy[i] ;
        cin>>hard[i] ; 
    } 



    ll dp[n+2][4] ; 
    memset(dp ,0 , sizeof(dp)) ; 

    dp[1][1] = easy[1] ; 
    dp[1][2] = hard[1] ; 
    dp[1][3] = 0 ;                     // do  nothing ; 
    
    
    for(ll i=2;i<=n;i++){
        dp[i][1] = easy[i]  + max({dp[i-1][1] , dp[i-1][2] , dp[i-1][3]}) ; 
        dp[i][2] = hard[i] + dp[i-1][3] ; 
        dp[i][3] =  0 +  max({dp[i-1][1] , dp[i-1][2] , dp[i-1][3]}) ; 
    }


    cout<<"the max salary : "<<max({dp[n][1] , dp[n][2] , dp[n][3]})<<endl;  

    return 0 ; 
}