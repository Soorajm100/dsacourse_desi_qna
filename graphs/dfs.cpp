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



void dfs(ll node , vector<vector<ll>>&gp , vector<ll>&vis , vector<ll>&parent)
{
    cout<<node<<endl; 

    vis[node] = 1 ; 

    for(auto x : gp[node]){
        if(vis[x]==0){
            parent[x] = node ; 
            dfs(x , gp ,vis , parent); 
        }
    }
}
int main(){

    
    ll n , v ; 

    cin>>n>>v; 

    vector<vector<ll>>gp(n+5); 
    for(ll i = 0 ;i<v;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }

    ll  source = 1 ; 
    vector<ll>vis(n+5 , 0); 

    vector<ll>parent(n+5 , 0); 

    cout<<endl; 

    dfs(1, gp, vis  , parent) ;

    return 0 ; 
}