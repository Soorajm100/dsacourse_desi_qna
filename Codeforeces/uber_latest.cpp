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

void  dfs(ll node , vector<vector<ll>>&gp ,vector<ll>&vis , vector<ll>&parent  , vector<ll>&b , vector<ll>&dp , ll k ){

    vis[node] = 1 ; 

    for(auto x : gp[node]){

        if(vis[x]==0){
            parent[x] = node ; 
            dfs(x , gp, vis , parent  , b , dp , k) ; 
        }
    }

  // bottom  up  dfs traversal 
   dp[node] = 1 ; 

    for(auto x : gp[node]){

        if(x==parent[node]){
            continue; 
        }
        else{
            ll diff = abs(b[node] - b[x]) ; 
            if(diff==k){
                dp[node] = max(dp[node] , 1 + dp[x]) ; 
            }

        }

    }
}



int main(){
    ll n ; 

    cin>>n ; 
    ll k ; 
    cin>> k ;



    vector<vector<ll>>gp(n+5) ; 
    vector<ll>parent(n+5 , 0) ; 
    vector<ll>b(n+5,  0) ; 
    vector<ll>dp(n+5, 0); 

    for(ll i=0;i<n-1;i++){

        ll x ,y ; 
        cin>>x>>y ; 
        gp[x].push_back(y) ;
        gp[y].push_back(x) ;  
    }

    for( ll i=1;i<=n;i++)cin>>b[i] ; ; 

    ll source = 1 ; 

    vector<ll>vis(n+5 , 0) ; 

    // dfs call 

    dfs(1, gp, vis  , parent  , b , dp  , k ) ;


    ll final_ans = *max_element(dp.begin() , dp.end()) ; 

    cout<<"The longest  valid vertical path :"<<final_ans<<endl; 

    return 0 ; 
}