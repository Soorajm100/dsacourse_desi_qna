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

    ll n  ; 
    cin>>n; 
    ll dp[20006][3] ; 
    vector<ll>a(n+1,0); 
    for(ll i=1;i<=n;i++)cin>>a[i] ;
    dp[1][1] = a[1] %2 ==1 ? 1 : 0 ; 
    dp[1][2] = a[1]%2==0 ? 1 : 0 ; 

    for(ll i=2;i<=n;i++){
        if(a[i]%2==0){
            dp[i][1] = dp[i-1][1] + dp[i-2][1]; 
            dp[i][2] = dp[i-1][2] + dp[i-2][2] ; 

        }
        else{

            dp[i][1] =  dp[i-1][2] + dp[i-2][2] ; 
            dp[i][2] = dp[i-1][1] + dp[i-2][1]; 

        }
    }


    cout<<dp[n][2]<<" this is even  paths"<<endl; 
    cout<<dp[n][1]<<" this is odd paths"<<endl ; 
    

    return 0 ; 
}