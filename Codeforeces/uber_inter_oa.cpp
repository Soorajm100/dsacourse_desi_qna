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


void dfs(vector<vector<ll>>&grid, ll i,ll j , vector<vector<ll>>&vis ,vector<pair<ll,ll>>&c1 , ll &count , vector<pair<ll,ll>>&c2){
    
    if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or vis[i][j]==1 or grid[i][j]!=1){
        return ; 
    }

    if(count==0){
        c1.push_back({i,j});
    }
    else{
        c2.push_back({i,j}) ; 
    }

    vis[i][j] = 1 ;
    
    dfs(grid, i+1 , j , vis, c1 , count, c2); 
    dfs(grid, i-1 , j , vis, c1 , count, c2); 
    dfs(grid, i , j+1 , vis, c1 , count, c2); 
    dfs(grid, i , j-1 , vis,  c1 , count, c2); 
    
}


int main(){

    ll n , m  ; 
    cin>>n>>m ; 
    vector<vector<ll>>grid(n , vector<ll>(m,0)) ; 
    queue<pair<ll,ll>>q ; 
   
    vector<vector<ll>>vis(n , vector<ll>(m,0)) ;
    for(ll i=0;i<=n-1;i++){
        for(ll j=0;j<=m-1;j++){
            ll x ; 
            cin>>x ; 
            grid[i][j] = x ; 
        }
    }
 
    vector<vector<ll>>dirs = {{-1,0} , {1,0} , {0,-1} , {0,1}} ;

    vector<pair<ll, ll>>c1 ; 
    vector<pair<ll, ll>>c2 ; 
    ll count= 0 ; 
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(vis[i][j]==0 and grid[i][j]==1){
                dfs(grid, i, j , vis,c1 , count , c2) ; 
                count++; 
                
            }
        }
    }

    vis.assign(n , vector<ll>(m,0)); 
    vector<vector<ll>>level(n , vector<ll>(m,0)) ;

    for(ll i=0;i<c1.size();i++){
        ll x = c1[i].first ; 
        ll y =c1[i].second ; 

        if(x+1 < grid.size() and x-1  > 0 and y+1 < grid[0].size() and y-1>0 and grid[x+1][y]==1 and grid[x-1][y]==1 and grid[x][y-1]==1 and grid[x][y+1]==1){
        
        }
        else{
                q.push({x,y}); 
                vis[x][y] = 1 ; 
        }
    }

   
    while(!q.empty()){

        auto  node = q.front() ;
        ll x1 = node.first ; 
        ll y1 = node.second ; 
        q.pop();

        for(auto x : dirs){
            ll ndx = x1 + x[0] ; 
            ll ndy = y1 + x[1] ; 

            if(ndx>=0 and ndy>= 0 and ndx < grid.size() and ndy <grid[0].size() and  vis[ndx][ndy]==0){
                q.push({ndx , ndy}); 
                vis[ndx][ndy] = 1 ; 
                level[ndx][ndy] = level[x1][y1] + 1 ; 
            }
        }
    }

    ll ans = 1e15; 
    for(ll i=0;i<c2.size();i++){
        ll x = c2[i].first ; 
        ll y = c2[i].second; 
        ans = min(ans , level[x][y] ) ; 

    }

    cout<<ans<<endl; 

    return 0 ; 
}