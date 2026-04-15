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



int main(){

    ll  n , k ; 

    cin>>n>>k; 
    vector<ll>b(n+1 , 0) ; 
    for(ll i=1;i<=n;i++)cin>>b[i] ; 
    vector<vector<ll>>adj(n+1) ; 

    for(ll i=1;i<=n-1;i++){
        ll x ,y ; 
        cin>>x>>y ; 
        adj[x].push_back(y) ; 
        adj[y].push_back(x) ; 
    }

    queue<ll>q ; 
    vector<ll>vis(n+1 , 0); 
    vector<ll>pref(n+1 , 0) ; 
    vector<ll>maxPref(n+1, 0) ; 
    pref[1] = b[1]==0 ? 1 :  0  ; 
    maxPref[1] = pref[1] ; 
    q.push(1); 
    vis[1] = 1 ; 


 
    while(!q.empty()){
        ll node = q.front() ; 
        q.pop() ;
        for(auto x : adj[node]){
            if(vis[x]==0){
                if(b[x]==0){
                    pref[x] = pref[node] +1 ; 
                    maxPref[x] = max(maxPref[node] , pref[x] ) ; 
                }
                vis[x] = 1 ; 
                q.push(x); 
            }
        }

    }

    ll count = 0 ; 

    for(ll i=2;i<=n;i++){
        if(adj[i].size()==1){
            if(maxPref[i]<=k)count++;
        } 
    }

    cout<<"The count of paths where from  currnode till  root number of 0's <=k "<<count<<endl; 

    return 0 ; 
}