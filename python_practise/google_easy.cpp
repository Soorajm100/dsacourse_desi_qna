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



void dfs(ll node ,vector<vector<ll>>&gp, vector<ll>&vis  ,  vector<ll>&parent  , vector<ll>&dp  , vector<ll>&color , vector<ll>&c ){

    vis[node] = true ;
    

    for(auto x : gp[node]){
        if(vis[x]==false){
            parent[x] = node;
            dfs(x , gp, vis, parent , dp, color , c ) ; 
        }
    }


    for(auto x : gp[node]){
        if(x!=parent[node]){
            dp[node] = dp[node] + dp[x] + c[x] ; 
            c[node] = c[node] + c[x] ; 
        }
    }


    if(color[node]==1){
        c[node] = c[node] +1 ; 
    }

    return ;

}


int main(){


    ll n ; 

    cin>>n ; 

    vector<vector<ll>>gp(n+5); 
    vector<ll>dp(n+5, 0); 
    vector<ll>c(n+5,0); 
    vector<ll>color(n+1, 0); 

    for(ll i = 0 ;i<n-1;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }


    for(ll i=1;i<=n;i++)cin>>color[i] ; 

    ll  source = 1 ; 
    vector<ll>vis(n+5 , 0); 

    vector<ll>parent(n+5 , 0); 

    cout<<endl; 



    dfs(1, gp, vis  , parent , dp , color  , c) ;


    for(ll i=1;i<=n;i++){
		cout<<i<<" "<<dp[i]<<"\n";
	}


    return 0 ; 
}