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


// dfs(1 , parent , vis , b  ,dp , gp ,ways) ; 


void dfs(ll node , vector<ll>&parent , vector<ll>&vis, vector<ll>&b , vector<vector<ll>>&dp , vector<vector<ll>>&gp , vector<vector<ll>>&ways){

    vis[node] = true ; 

    for(auto x :gp[node]){
        if(!vis[x]){
            parent[x] = node ;
            dfs(x , parent , vis , b , dp , gp , ways ) ;   
        }
    }

    ll notconsider = 0 ; 
    ll  consider = 0 ; 
    ll wayconsider = 1 ; 
    ll waynotconsider = 1 ; 
    for(auto x : gp[node]){
        ll wayco = 0 ; 
        ll waynot = 0 ; 

        if(x!=parent[node]){

            consider+=dp[x][0] ; 
            notconsider+=max(dp[x][0] , dp[x][1]); 

            if(dp[x][0]==dp[x][1]){
                waynot +=ways[x][1] + ways[x][0] ; 
            }
            else{
                if(dp[x][0]>dp[x][1]){
                    waynot = waynot + ways[x][0]; 
                }
                else{
                     waynot = waynot + ways[x][1]; 
                }
            }

            wayco = wayco  + ways[x][1] ; 
            wayconsider = wayconsider*wayco ; 
            waynotconsider = waynotconsider*waynot ; 
        }
    }

    ways[node][0] = waynotconsider; 
    ways[node][1] = wayconsider; 
    dp[node][1] = b[node]  + consider ; 
    dp[node][0] = notconsider ; 

}



int main(){

    ll n ; 
    cin>>n; 
    vector<vector<ll>>ways(n+1 , vector<ll>(5,0)); 
    vector<vector<ll>>dp(n+5 , vector<ll>(4,0)); 
    

    vector<vector<ll>>gp(n+5) ; 

    vector<ll>b(n+2, 0); 
    vector<ll>vis(n+1,0); 
    vector<ll>parent(n+1, 0);

    for(ll i=1;i<=n;i++)cin>>b[i] ; 

    for(ll i=0;i<n-1;i++){
        ll x ,y ; 
        cin>>x>>y ; 
        gp[x].push_back(y);
        gp[y].push_back(x); 
    }

    dfs(1 , parent , vis , b  ,dp , gp ,ways) ; 

    ll ans = max(dp[1][0] , dp[1][1]); 

    cout<<endl;
    cout<<ans<<" "; 

    if(dp[1][0]==dp[1][1]){
        cout<<(ways[1][0] + ways[1][1] ); 
    }
    else{
         if(dp[1][0]>dp[1][1]){
                   cout<<ways[1][0]; 
                }
          else{
                  cout<<ways[1][1]; 
        }
    }

    return 0 ; 
}