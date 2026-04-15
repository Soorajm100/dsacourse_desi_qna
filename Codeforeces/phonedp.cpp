#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vipair = vector<pair<ll, ll>>;

template <class T>
using v = vector<T>;

const int INF_INT = 1e9;
const ll INF_LL = (1LL << 60);
const int MOD = 1000000007;

int main(){

    ll n ; 
    cin>>n ; 
    vector<ll>b(n+1,0) ; 
    for(ll i=1;i<=n;i++)cin>>b[i] ; 

    ll dp[n+2][4] ; 

    memset(dp ,0 , sizeof(dp));


    dp[1][2]= 0 ; 
    dp[2][2] = b[1] + b[2] ; 
    if(n>=3)dp[3][2] = b[3] + b[2] ; 


    dp[1][3]  = 0 ; 
    dp[2][3] = 0 ;
    if(n>=3)dp[3][3] = b[1] + b[2] + b[3] ; 
    if(n>=4)dp[4][3] = b[4] + b[3] + b[2] ; 
    if(n>=5)dp[5][3] = b[5] + b[4] + b[3] ; 
    vector<ll>pref2(n+1,0); 
    vector<ll>pref3(n+1,0) ;
    
    pref2[1] = dp[1][2] ; 
    pref3[1] = dp[1][3] ; 

    pref2[2] = max(dp[2][2] , pref2[1]) ; 
    pref3[2] = max(dp[2][3] , pref3[1]) ; 

    
    pref2[3] = max(dp[3][2] , pref2[2]) ; 
    pref3[3] = max(dp[3][3] , pref3[2]) ; 



    for(ll i=4;i<=n;i++){
        if(i>=4)dp[i][2] = (b[i] + b[i-1] + dp[i-3][2])%MOD ; 
        if(i>=5)dp[i][2] = max(dp[i][2] , b[i] + b[i-1] + max(pref2[i-4] , pref3[i-4])) ; 
        if(i>=6)dp[i][3] = (b[i] + b[i-1] + b[i-2] + max(pref3[i-5] , pref2[i-5]))%MOD ; 
        pref2[i] = max(dp[i][2] , pref2[i-1]); 
        pref3[i] = max(dp[i][3] , pref3[i-1]); 
    }


    ll global_ans = -1e15 ; 

    for(ll i=1;i<=n;i++){

        ll ans = max(dp[i][2] , dp[i][3]) ; 
        global_ans = max(ans , global_ans) ; 
    }


    cout<<"The maximum  robbery  is : "<<global_ans<<endl; 

    return 0 ; 
}