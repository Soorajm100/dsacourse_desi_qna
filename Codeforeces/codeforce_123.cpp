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


void dfs_2(ll node , vector<vector<ll>>&gp  , vector<ll>&parent , vector<ll>&dp ,vector<pair<ll,ll>>&ghash  , vector<ll>&storage)
{


    for(auto x : gp[node]){
            if(parent[x]==node)dfs_2(x , gp, parent , dp , ghash , storage); 
    }

    ghash[node] = {1e20 , -1e20} ; 

    
    for(auto x : gp[node]){
      
         if(x==parent[node]){
            continue ; 
         }
         else{
            ghash[node].first = min(ghash[node].first , ghash[x].first) ; 
            ghash[node].second = max(ghash[node].second , ghash[x].second) ; 
         }
        
    }


    if(gp[node].size()==1 && node!=1){
    	ghash[node].first = storage[node];
    	ghash[node].second = storage[node];
    }


    cout<<"Node : "<<node<<"  "<<ghash[node].first<<"  "<<ghash[node].second<<endl;

}

void dfs(ll node , vector<vector<ll>>&gp , vector<ll>&vis , vector<ll>&parent , vector<ll>&dp , vector<ll>&b, vector<ll>&level , vector<ll>&leaf )
{
   

    vis[node] = 1 ; 

    if(gp[node].size()==1 and node!=1){
        leaf.push_back(node) ; 
    }

    for(auto x : gp[node]){
        if(vis[x]==0){
            parent[x] = node ; 
            level[x] = level[node] +1 ; 
            dfs(x , gp ,vis , parent , dp , b, level  , leaf); 
        }
    }
    for(auto x : gp[node]){
        if(x==parent[node]){
            continue; 
        }
        else{
           dp[node] = dp[node] +  dp[x] ; 
        }
    }
    dp[node] += b[node]*level[node];


}

ll get_deepest_node(ll start , ll end ,vector<ll>&level ,vector<ll>&prefMaxlevel ,vector<ll>&suffMaxlevel ,ll n ,vector<ll>&leaf) 
{
      ll ans = -1e12;

      if(start == 0 && end == leaf.size() - 1)
          return -1e12;

      if(start > 0)
          ans = max(ans, prefMaxlevel[start - 1]);

      if(end + 1 < leaf.size())
          ans = max(ans, suffMaxlevel[end + 1]);

      return ans;
}


int main(){

    
    ll n ; 

    cin>>n ; 

    vector<vector<ll>>gp(n+5); 
    vector<ll>dp(n+1, 0); 
    vector<ll>b(n+5,0);
    vector<ll>level(n+1, 0);  
    vector<ll>leaf ; 


    for(ll i=1;i<=n;i++)cin>>b[i] ; 

    for(ll i = 1 ;i<=n-1;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }

    vector<ll>vis(n+5 , 0); 
    vector<ll>parent(n+5 , 0); 
    vector<pair<ll,ll>>ghash(n+1); 
    dfs(1, gp, vis  , parent , dp , b , level  , leaf  ) ;


    vector<ll>storage(n+1, 0); 


    ll total_sum  = accumulate(dp.begin() , dp.end() , 0LL) ;

    for(ll i=0;i<leaf.size();i++){
        ll node = leaf[i] ; 
        storage[node] = i ; 
    }

    dfs_2(1 , gp  ,parent ,dp , ghash , storage ) ; 


    vector<ll>prefMaxlevel(leaf.size(),-1e5); 
    vector<ll>suffMaxlevel(leaf.size(),-1e5); ; 
    prefMaxlevel[0] = level[leaf[0]] ;
    for(ll i=1;i<=leaf.size()-1;i++){
        prefMaxlevel[i] = max(prefMaxlevel[i-1], level[leaf[i]]) ; 
    }

    suffMaxlevel[leaf.size()-1] = level[leaf[leaf.size()-1]] ;
    for(ll i=leaf.size()-2;i>=0;i--){
        suffMaxlevel[i] = max(suffMaxlevel[i+1], level[leaf[i]]) ; 
    }


    ll globl_ans = -1e12 ; 


    for(ll i=2;i<=n;i++){

        //**dont eant to  include the range [start , end] */
        ll start = ghash[i].first ;
        ll end = ghash[i].second ;
        ll ans = total_sum  + (get_deepest_node(start , end , level , prefMaxlevel, suffMaxlevel , n  , leaf)-level[i]+1)*dp[i] ; 
        globl_ans = max(globl_ans, ans) ; 
    }


    cout<<"Maxiumum  new sum  :"<<globl_ans<<endl;

    return 0 ; 
}