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

struct Node{
    ll x , y ; 
    ll sx , sy ; 
};

int main(){

    ll n , m  ; 
    cin>>n>>m ; 
    vector<vector<ll>>grid(n , vector<ll>(m,0)) ; 
    queue<Node>q ; 
    vector<vector<ll>>level(n , vector<ll>(m,0)) ;
   

    for(ll i=0;i<=n-1;i++){
        for(ll j=0;j<=m-1;j++){
            ll x ; 
            cin>>x ; 
            grid[i][j] = x ; 
            if(x==2){
                q.push({i,j , i, j}) ; 
                level[i][j]=1;
            }
        }
    }

    vector<vector<ll>>dirs = {{-1,0} , {1,0} , {0,-1} , {0,1}} ;
    ll c = 0 ; 

    ll ans = 1e8 ;
    ll i1, j1 , iend , jend ; 
    while(!q.empty() and c==0){
        
        ll nodex = q.front().x ; 
        ll nodey = q.front().y ; 
        ll xx = q.front().sx; 
        ll yy = q.front().sy ; 

        q.pop() ; 
        for(auto x : dirs){

            ll ndx = nodex + x[0] ; 
            ll ndy = nodey + x[1] ; 
            if(ndx >= 0 && ndx < n && ndy >= 0 && ndy < n && level[ndx][ndy]==0){
               
                q.push({ndx,ndy , xx , yy}) ; 
                level[ndx][ndy] = level[nodex][nodey] + 1 ;
                if(grid[ndx][ndy]==3){
                    iend = ndx; 
                    jend = ndy ; 
                    ans = min(ans , level[ndx][ndy]) ; 
                    i1 = xx; 
                    j1 = yy ;
                    c = 1 ; 
                    break; 
                }
            }
        }
    }


    cout<<"Shortest  distance of blue node from  red node is : "<<ans-1<<endl;
    cout<<"Start :"<<i1<< "  "<<j1<<endl; 
    cout<<"End :" <<iend<<" "<<jend<<endl; 


    return 0 ;  
 }