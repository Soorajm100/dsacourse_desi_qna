#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vipair = vector<pair<ll, ll>>;

template <class T>
using v = vector<T>;

const int INF_INT = 1e9;
const ll INF_LL = (1LL << 60);
const int MOD = 1000000007;


int main(){

    ll n , m  ; 
    cin>>n>>m ; 
    vector<vector<ll>>grid(n , vector<ll>(m,0)) ; 
    queue<pair<ll,ll>>q ; 
    vector<vector<ll>>level(n , vector<ll>(m,0)) ;
      vector<vector<ll>>vis(n , vector<ll>(n,0)) ;
    for(ll i=0;i<=n-1;i++){
        for(ll j=0;j<=m-1;j++){
            ll x ; 
            cin>>x ; 
            grid[i][j] = x ; 
            if(x==2){
                q.push({i,j}) ; 
                vis[i][j] = 1; 
            }
        }
    }

    vector<vector<ll>>dirs = {{-1,0} , {1,0} , {0,-1} , {0,1}} ;

  

    while(!q.empty()){
        
        ll nodex = q.front().first ; 
        ll nodey = q.front().second ; 

        q.pop() ; 


        for(auto x : dirs){

            ll ndx = nodex + x[0] ; 
            ll ndy = nodey + x[1] ; 

            if(ndx >= 0 && ndx < n && ndy >= 0 && ndy < n && !vis[ndx][ndy]){
                vis[ndx][ndy] = 1 ; 
                q.push({ndx,ndy}) ; 
                level[ndx][ndy] = level[nodex][nodey] + 1 ;
            }
        }

    }

    ll ans = 1e8 ;
    for(ll i=0;i<=n-1;i++){
        for(ll j=0;j<=m-1;j++){
              if(grid[i][j]==3){
                ans = min(ans , level[i][j]) ; 
              }
        }
    }


    cout<<"Shortest  distance of blue node from  red node is : "<<ans<<endl;


    return 0 ;  
 }