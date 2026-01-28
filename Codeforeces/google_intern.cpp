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


    ll dp[200006]; 
    ll x ,y, z ,b;  
    ll n ; 
    cin>>n; 

    cin>>y>>x>>z>>b; 
    

    dp[1] = 0 ; 
    for(ll i=2;i<=n;i++){

        ll v1 , v2, v3 .v4 ; 
        
        if(i%7==0){
            v1 = dp[i/7] + x ; 
        }
        else if(i%5==0){
           v2 = dp[i/5] + b; 
        }
        else if(i%3==0){
           v3 = dp[i/3 ] + b; 
        }
        else{
             v4 = dp[i-1] + y; 
        }

        dp[i] =  min({v1 , v2 , v3 , v4}) ; 
    }

    cout<<dp[n]<<endl; 
    
    return 0 ; 
}