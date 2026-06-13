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

    vector<ll>b(n+1,0); 
    for(ll i=1;i<=n;i++)cin>>b[i] ;


    ll dp[n+2][2] ; 

    memset(dp, 0, sizeof(dp)) ;

    dp[1][0] = 1 ; 
    dp[2][0] = 1 ; 

    for(ll i=3;i<=n;i++){
        dp[i][0] = dp[i-1][0] ; 


        if(b[i-2]==2){
            dp[i][0] += dp[i-2][0] ; 
        }

        dp[i][1] = dp[i-1][1] ; 

        if(b[i-2]==2){
            dp[i][1] +=dp[i-2][1] ; 
        }

        if(b[i-3]==2 and b[i-2]==2){
            dp[i][1]+=dp[i-3][0] ; 
        }
    }


    cout<<dp[n][0]  + dp[n][1] <<endl; 
    
    return 0 ; 
}