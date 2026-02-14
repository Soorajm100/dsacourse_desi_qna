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

vector<ll>dijkstra(ll  src ,  vector<vector<pair<ll, ll>>>&adj , ll n ){
    vector<ll>dist(n+1 , INF_INT);
    priority_queue<pair<ll, int> , vector<pair<ll, int>> , greater<pair<ll, int>>>pq; 
    dist[src] = 0 ; 
    pq.push({0,src});
    while(!pq.empty()){
        auto compact = pq.top() ; 
        ll len = compact.first ; 
        ll node = compact.second; 
        pq.pop() ; 

        if(len > dist[node])continue ; 

        for(auto x : adj[node]){
            if(dist[x.first] > len + x.second){
                dist[x.first] = len +  x.second;  
                pq.push({dist[x.first] , x.first}) ; 
            }
        }

    }
    return dist; 
}


int main(){

    ll n , m ; 

    cin>>n>>m ;

    ll a ,b ,c ; 
    cin>>a>>b>>c ; 

    vector<vector<pair<ll, ll>>>adj(n+1) ;

    for(ll i=0;i<m;i++){
        ll u , v ; 
        ll w ; 
        cin>>u>>v>>w ; 
        adj[u].push_back({v,w}) ; 
        adj[v].push_back({u,w}) ; 
    }

    vector<ll>dista = dijkstra(a , adj , n ) ; 
    vector<ll>distb  = dijkstra(b, adj , n  ) ; 
    vector<ll>distc = dijkstra(c , adj , n ) ; 

    ll ans = 1e9 ; 

    for(ll i=0;i<n;i++){
        ll distA = dista[i] ; 
        ll distB = distb[i] ; 
        ll distC = distc[i] ; 
        ans = min(ans , distA + distB + distC) ; 
    }
    if(ans==-1e9)cout<<-1<<endl; 
    cout<<"the minimum  distance is : "<<ans<<endl; 
    return 0 ; 
}