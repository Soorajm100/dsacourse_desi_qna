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
    vector<ll>level(n+5 , 0) ; 

    queue<ll>q; 
    q.push(source);
    vis[source] =  1 ; 
    level[source] = 1 ; 
    while(!q.empty()){
        ll ele = q.front(); 
        cout<<"removed element : " <<ele<<" the level is : "<<level[ele]<<endl;
        q.pop(); 

        for(auto x  : gp[ele]){
            if(vis[x]==0){
                q.push(x); 
                vis[x] = 1 ; 
                level[x] = level[ele] + 1 ; 
            }   
        }
    }


    for(ll i=1;i<=n;i++){
        if(vis[i]== 1){
            cout<<"you can visit node "i<<"from  source "<<source; 
        }
        else{
            cout<<"you cannot visit node"<<i<<" from  source "<<source; 
        }
        cout<<endl; 
    }

    return 0 ;
}