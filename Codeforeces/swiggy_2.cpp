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

/////
/*****
          
       1(5) 
   
    2(7)     5(15) 
   
  3(-10) 
 
4(4)

-6 -27 = -33

-10 - (31) = -41 

total = 21 


*/

void  dfs(ll node , vector<vector<ll>>&gp ,vector<ll>&vis , vector<ll>&parent , vector<ll>&sum_node , vector<ll>&b){

    vis[node] = 1 ; 

    for(auto x : gp[node]){

        if(vis[x]==0){
            parent[x] = node ; 
            dfs(x , gp, vis , parent , sum_node , b) ; 
        }
    }

  // bottom  up  dfs traversal 
    ll sum = 0 ; 

    for(auto x : gp[node]){

        if(x==parent[node]){
            continue; 
        }
        else{
            sum = sum + sum_node[x] ; 
        }

    }

    sum_node[node] = sum   + b[node]; 
}



int main(){
    ll n ; 

    cin>>n ; 

    vector<vector<ll>>gp(n+5) ; 
    vector<ll>sum_node(n+5 , 0) ; 
    vector<ll>parent(n+5 , 0) ; 
    vector<ll>b(n+5,  0) ; 

    for(ll i=0;i<n-1;i++){

        ll x ,y ; 
        cin>>x>>y ; 
        gp[x].push_back(y) ;
        gp[y].push_back(x) ;  
    }

    for( ll i=1;i<=n;i++)cin>>b[i] ; 


    ll total_sum = accumulate(b.begin() , b.end() , 0) ; 

    ll source = 1 ; 

    vector<ll>vis(n+5 , 0) ; 

    // dfs call 

    dfs(1, gp, vis  , parent , sum_node , b ) ;


    ll min_sum = 1e9 ; 

   

    for(ll i=1;i<=n;i++){
        ll t1 = sum_node[i] ; 
        ll t2 =  total_sum - t1 ;
        cout<<t1<<" "<<t2<<endl;  
        ll diff = t1-t2 ; 
        min_sum = min(min_sum , diff) ; 

    }


    cout<<"Minimum  difference with  one detached node is : "<<min_sum<<endl; 

    return 0 ; 
}