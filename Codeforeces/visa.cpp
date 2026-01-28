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

int main() {
    ll n;
    ll m;
    cin >> n >> m;

    vector<vector<ll>> grid(n+2, vector<ll>(m+1, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> fixed(n+2, vector<ll>(m+1,0));
    vector<vector<ll>>visited(n+2, vector<ll>(m+1, 0)); 
    vector<ll> pos;
    queue<pair<ll, ll>> q;
    for(ll i =1 ;i<=n;i++){
        for(ll j=1;j<=m;j++){

            ll currentEle = grid[i][j] ;
            ll count = 0 ;  
            if(grid[i-1][j]==currentEle){
                count++ ; 
            }
            if(grid[i+1][j]==currentEle){
                count++ ; 
            }
            if(grid[i][j+1]==currentEle){
                count++ ; 
            }
            if(grid[i][j-1]==currentEle){
                count++ ; 
            }

            if(count>=2){
                fixed[i][j] =1 ; 
            }
        }
    }

 

    for (ll i =1 ; i <= n; i++) {
        for (ll j =1; j <= m; j++) {
            if (fixed[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

       


    vector<pair<ll, ll>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };


    while (!q.empty()) {
        ll size = q.size();
        for (ll i = 0; i < size; i++) {
            auto node = q.front();
            q.pop();

            ll r = node.first;
            ll c = node.second;
            ll currentValue = grid[r][c] ; 

            for (auto x : dirs) {
                ll nr = r + x.first;
                ll nc = c + x.second;

                if (nr < 1 || nc < 1 ||
                    nr > n ||
                    nc > m||
                    visited[nr][nc] == 1 || grid[nr][nc]!=currentValue) {
                    continue;
                }

                if (grid[nr][nc] == currentValue) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                    fixed[nr][nc] = 1 ; 
                }
            }
        }
    }

    vector<vector<ll>>newGrid = grid ; 

    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            if(fixed[i][j]==1){
                newGrid[i][j] = 0 ; 
            }
        }
    }

    cout<<endl<<endl; 
    cout<<"After BFS" <<endl; 

       
    for(ll i = 1 ;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout<<newGrid[i][j]<<" "; 
        }
        cout<<endl; 
    }


    /* After  Gravity*/
    cout<<endl<<endl; 

     cout<<"After Gravity" <<endl; 




    for(ll j=1;j<=m;j++){
        vector<ll>coldata ; 
        for(ll i=n;i>=1 ; i--){

        if(newGrid[i][j] > 0){
            coldata.push_back(newGrid[i][j]); 
        }
        newGrid[i][j] = 0 ; 
       }

        ll index = 0 ; 
        for(ll i=n ; i>=1 and index<coldata.size();i--){
            newGrid[i][j] = coldata[index++]; 
        }
    }

    
    for(ll i = 1 ;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout<<newGrid[i][j]<<" "; 
        }
        cout<<endl; 
    }





    return 0;
}
