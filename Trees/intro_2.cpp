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

    cin>>n;

    vector<ll>color(n+5, 0);; 

    vector<vector<ll>>gp(n+5); 
    for(ll i = 0 ;i<n-1;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }

    for(ll i=1;i<=n;i++){
        cin>>color[i]; 
    }

    ll  source = 1 ; 
    vector<ll>vis(n+5 , 0); 
    vector<ll>count_ones(n+5 , 0) ; 


    queue<ll>q; 
    q.push(source);
    vis[source] =  1 ; 
    count_ones[source] = color[source] ; 
    
    while(!q.empty()){
        ll ele = q.front(); 
        q.pop(); 
        ll count = 0 ; 
        for(auto x  : gp[ele]){
            if(vis[x]==0){
                q.push(x); 
                vis[x] = 1 ; 
                if(color[x]==1){
                    count_ones[x] = count_ones[ele] + 1 ;
                }
                else{
                    count_ones[x] = count_ones[ele] ;
                }
            }   
        }
    }




    for(ll i=1;i<=n;i++){
      
       cout<<count_ones[i]<<" "; 
    }
    cout<<endl; 

   

    return  0;

}