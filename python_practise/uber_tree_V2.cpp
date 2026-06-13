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
ll dp[100005][21][2] ; 

// dfs(1, gp, vis  , parent , dp ,depth , b  ) ;

void dfs(ll node , vector<vector<ll>>&gp , vector<ll>&vis , vector<ll>&parent , vector<ll>&depth , vector<ll>&b)
{
   

    vis[node] = 1 ; 

    for(auto x : gp[node]){
        if(vis[x]==0){
            parent[x] = node ; 
            depth[x] = depth[node] +1 ; 
            dfs(x ,gp, vis  , parent  ,depth , b   ); 
        }
    }

    ll sum= 0 ; 
   //  dp[node] =  b[node]^depth[node]; 

    for(ll bit=0;bit<=20;bit++){
        for(auto x : gp[node]){
            if(x==parent[node]){
                continue; 
            }
            else{
                dp[node][bit][0] = dp[node][bit][0] + dp[x][bit][0]; 
                dp[node][bit][1] = dp[node][bit][1] + dp[x][bit][1]; ; 
            }
        }

        if(depth[node]%2==0){
            if(b[node]& (1<<bit)){
                dp[node][bit][0] = dp[node][bit][0] + 1 ; 
            }
        }

        if(depth[node]%2==1){
            if(b[node]& (1<<bit)){
                dp[node][bit][1] = dp[node][bit][1] + 1 ; 
            }
        }

    }
   

}

int main(){

    ll n ; 

    cin>>n ; 

    vector<vector<ll>>gp(n+5); 
   // vector<ll>dp(n+5, 0); 
    vector<ll>b(n+5,0); 
    vector<ll>depth(n+5,0); 
    vector<ll>vis(n+5 , 0); 
    vector<ll>parent(n+5 , 0); 

    for(ll i = 0 ;i<n-1;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }

    for(ll i=1;i<=n;i++)cin>>b[i] ; 

    dfs(1, gp, vis  , parent  ,depth , b  ) ;



    for(ll i=1;i<=n;i++){
        ll sum = 0 ; 

        for(ll j=0;j<=20;j++){
            sum = sum + dp[i][j][0]  + dp[i][j][1] ;
        }

        cout<<"node"<<" :  "<<i<<"-> "<<sum<<endl;
    }



  


    return 0;    
}