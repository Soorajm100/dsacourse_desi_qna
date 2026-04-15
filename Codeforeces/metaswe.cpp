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
using v3  = vector<vector<vector<ll>>> ; 
template <class T>
using v = vector<T>;

const int INF_INT = 1e9;
const ll INF_LL = (1LL << 60);
const int MOD = 1000000007;


ll dfs(ll i , ll j , ll dir , v3 &dp , vector<vector<ll>>&arr , ll n ,ll m){


    if(i<0 or i>=n or j<0 or j>=m){
        return -1e18 ; 
    }


    if(arr[i][j]==1){
        return -1e18 ; 
    }

   
    if(dp[i][j][dir]!=0){
        return dp[i][j][dir] ; 
    }

    if(i==0 and j==0){
        if(dir == 0){
            return dp[i][j][dir] = 1 ; 
         }
         if(dir==2){
            return dp[i][j][dir] = 1 ; 
         }
         if(dir==1){
            return dp[i][j][dir] = -1e18 ; 
         }    
    }

    if(dir==0){
        return dp[i][j][dir] = 1 + max(dfs(i , j-1 , 0 , dp , arr , n , m  ) , dfs(i , j-1 , 2 , dp , arr , n , m  ));
    }
    else if(dir==2){
         return dp[i][j][dir] = 1 + max({dfs(i-1 , j , 0 , dp , arr , n , m  ) , dfs(i-1 , j , 2 , dp , arr , n , m  ) ,  dfs(i-1 , j , 1 , dp , arr , n , m  )});
    }
    else if(dir==1){
        return dp[i][j][dir] = 1 + max(dfs(i , j+1 , 1 , dp , arr , n , m  ) , dfs(i , j+1 , 2 , dp , arr , n , m  ));
    }

    return 0 ; 
}


int main(){

    ll n , m ; 
    cin>>n>>m ; 
    vector<vector<ll>>arr(n, vector<ll>(m,0)); 

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            char s; 
            cin>>s ; 
            if(s=='.'){
                arr[i][j] =  0 ; 
            }
            else{
                arr[i][j] = 1 ; 
            }
        }
    }

    v3 dp ;
    dp.assign(n, vector<vector<ll>>(m, vector<ll>(3, 0))); 
    ll ans = max(dfs(n-1 , m-1 , 0 , dp , arr , n , m ) , dfs(n-1 , m-1 , 2 , dp , arr , n , m ));

    cout<<ans<<endl; 


}