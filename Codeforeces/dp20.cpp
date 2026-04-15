
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
    /// 1 2  4 6 

    // 4 atmost 2 

    ll dp[n+1][3][3] ; 

    memset(dp, 0, sizeof(dp));


    dp[0][0][0] = 1 ; 
    if(n>0)dp[1][0][0] = 1 ; 

    for(ll i=2;i<=n;i++){

        dp[i][0][0] = dp[i-1][0][0] + dp[i-2][0][0]  ;
        dp[i][0][1] = dp[i-1][0][1] + dp[i-2][0][1]  ;
        dp[i][0][2] = dp[i-1][0][2] + dp[i-2][0][2]  ;


        dp[i][1][0] = dp[i-1][1][0] + dp[i-2][1][0]  ;
        dp[i][1][1] = dp[i-1][1][1] + dp[i-2][1][1]  ;
        dp[i][1][2] = dp[i-1][1][2] + dp[i-2][1][2]  ;

        dp[i][2][0] = dp[i-1][2][0] + dp[i-2][2][0]  ;
        dp[i][2][1] = dp[i-1][2][1] + dp[i-2][2][1]  ;
        dp[i][2][2] = dp[i-1][2][2] + dp[i-2][2][2]  ;


        if(i>=4){
            dp[i][1][0] += dp[i-4][0][0]  ;
            dp[i][1][1] += dp[i-4][0][1]  ;
            dp[i][1][2] += dp[i-4][0][2]  ;
            dp[i][2][0] += dp[i-4][1][0]  ; 
            dp[i][2][1] += dp[i-4][1][1]  ; 
            dp[i][2][2] += dp[i-4][1][2]  ;
        }

          if(i>=6){
            dp[i][0][1] += dp[i-6][0][0]  ;
            dp[i][0][2] += dp[i-6][0][1]  ;
            dp[i][1][1] += dp[i-6][1][0]  ;
            dp[i][1][2] += dp[i-6][1][1]  ; 
            dp[i][2][1] += dp[i-6][2][0]  ; 
            dp[i][2][2] += dp[i-6][2][1]  ;
        }

    }

    ll result = dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2] + dp[n][2][0] + dp[n][2][1] + dp[n][2][2];
    cout << result << endl;
    return 0 ; 
}