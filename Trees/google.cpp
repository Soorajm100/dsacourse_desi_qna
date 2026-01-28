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

     ll n ; 

    cin>>n;

    vector<vector<ll>>gp(n+5); 
    for(ll i = 0 ;i<n-1;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }

    ll  source = 1 ; 
    vector<ll>vis(n+5 , 0); 
    vector<ll>child(n+5 , 0) ; 

    queue<ll>q; 
    q.push(source);
    vis[source] =  1 ; 
    
    while(!q.empty()){
        ll ele = q.front(); 
        q.pop(); 
        ll count = 0 ; 
        for(auto x  : gp[ele]){
            if(vis[x]==0){
                q.push(x); 
                vis[x] = 1 ; 
                count++; 
            }   
        }
         child[ele] = count ; 
    }

    for(ll i=1;i<=n;i++){
        if(child[i]== 0){
            cout<<"Node "<<i<<" is "<<"Lead Node"<<endl; 
        }
    }

    return  0;

}