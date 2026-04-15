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


void dfs(ll node ,vector<ll>&vis , ll &green_count , ll &components , vector<vector<ll>>&adj  , set<ll>&greenNodes){

    vis[node] = 1 ; 
    components++; 

    if(greenNodes.find(node)!=greenNodes.end()){
        green_count++; 
    }

    for(auto x : adj[node]){
        if(vis[x]==0){
           dfs(x ,vis , green_count , components , adj ,greenNodes) ; 
        }
    }
}

int main(){

    ll n  , m ; 
    cin>>n>>m  ; 
    vector<vector<ll>>edges(m+1) ; 
    ll gs; ; 
    cin>>gs ; 
    set<ll>greenNodes ; 


    ll final_res=  1e9 ; 
    ll minNode = -1 ; 

    for(ll i=1;i<=m;i++){
        ll x , y ; 
        cin>>x>>y ; 
        edges[i].push_back(x) ;
        edges[i].push_back(y) ;  
    }

    for(ll i=0;i<gs;i++){
        ll tk ; 
        cin>>tk ; 
        greenNodes.insert(tk); 
    }

    for(ll x=1;x<=n;x++){
        ll currnode = x ; 

        // adjacency  list
        vector<vector<ll>>adj(n+1) ; 
        for(ll i=1;i<=m;i++){
            ll u = edges[i][0] ; 
            ll v = edges[i][1] ; 
            
            if(u==currnode || v==currnode){
            }
            else{
                adj[u].push_back(v) ; 
                adj[v].push_back(u) ; 
            }
        }

        vector<ll>vis(n+1, 0) ; 

        ll answer = 0 ;
       
        for(ll k=1;k<=n;k++){


            if(currnode==k) continue ; 

            ll green_count = 0 ; 
            ll components = 0 ; 
              
            if(vis[k]==0){

          
                ll node = k ; 
                dfs(node  , vis , green_count , components , adj , greenNodes); 
                if(green_count>=1){
                    answer+=components ; 
                }
            }
        }

        cout<<"the node and answer: "<<currnode<<" "<<answer<<endl; 
        if(final_res > answer){
            final_res = answer ; 
            minNode = currnode ; 

        }

    }


    cout<<"The minmum  number of components that  might not be affected is : "<<final_res <<" node is : "<<minNode<<endl;  

    return 0 ; 
}