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



void dfs(ll node , vector<vector<ll>>&gp , vector<ll>&vis , vector<ll>&parent , vector<ll>&sum_node , vector<ll>&b)
{
   

    vis[node] = 1 ; 

    for(auto x : gp[node]){
        if(vis[x]==0){
            parent[x] = node ; 
            dfs(x , gp ,vis , parent , sum_node , b ); 
        }
    }

    ll sum= 0 ; 

    for(auto x : gp[node]){
        if(x==parent[node]){
            continue; 
        }
        else{
           sum = sum +  sum_node[x] ; 
        }
    }
    sum_node[node] = sum + b[node];

}
int main(){

    
    ll n ; 

    cin>>n ; 

    vector<vector<ll>>gp(n+5); 
    vector<ll>sum_node(n+5, 0); 
    vector<ll>b(n+5,0); 

    for(ll i = 0 ;i<n-1;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }


    for(ll i=1;i<=n;i++)cin>>b[i] ; 

    ll  source = 1 ; 
    vector<ll>vis(n+5 , 0); 

    vector<ll>parent(n+5 , 0); 

    cout<<endl; 

    dfs(1, gp, vis  , parent , sum_node , b ) ;

    ll  max_sum = -1e8; 
    for(ll i=1;i<=n;i++){

        max_sum = max(max_sum , sum_node[i]) ;
        cout<<"Sum of Subtree of node "<<i<<" is "<<sum_node[i]<<endl; 
    }

    cout<<"Maximum Subtree Sum is "<<max_sum<<endl;

    return 0 ; 
}