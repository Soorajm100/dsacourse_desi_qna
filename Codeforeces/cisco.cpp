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


     ll n ; 

    cin>>n ; 

    vector<vector<ll>>gp(n+5); 
    vector<ll>sum_node(n+5, 0); 
    vector<ll>b(n+5,0); 

    for(ll i=1;i<=n;i++)cin>>b[i] ; 

    for(ll i = 0 ;i<n-1;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }


   
    vector<ll>degree(n+1,0); 

    queue<ll>q; 
    vector<ll>vis(n+1,0);  

    for(ll i=1;i<=n;i++){
        degree[i] = gp[i].size() ; 
        if(degree[i]==1 and b[i]==0){
            q.push(i); 
            vis[i] = 1 ; 
        }
    }



    ll count = 0 ; 
   
    while(!q.empty()){

        ll node = q.front() ; 
        q.pop() ; 
        count++; 
        ll parent =-1; 
        for(auto x : gp[node]){

            if(vis[x]==0){
            degree[x]--; 
            parent = x ; 
            if(degree[x]==1 and b[x]==0){
                q.push(x); 
            }
            vis[x] = 1 ; 
        }

        }

  
        if(parent!=-1){
            gp[parent].erase(find(gp[parent].begin() , gp[parent].end() , node)); 
            gp[node].erase(find(gp[node].begin() , gp[node].end() , parent)) ; 

        }
    }


    for(ll i=1;i<=n;i++){
        degree[i] = gp[i].size(); 
        if(degree[i]==1){
            q.push(i); 
        }
    }



    vis.assign(n+1,0) ; 

     while(!q.empty()){

        ll node = q.front() ; 
        q.pop() ; 
        count++; 
        ll parent =-1; 
        for(auto x : gp[node]){

            if(vis[x]==0){
            degree[x]--; 
            parent = x ; 
            vis[x] = 1 ; 
        }

        }

       
        if(parent!=-1){
            gp[parent].erase(find(gp[parent].begin() , gp[parent].end() , node)); 
            gp[node].erase(find(gp[node].begin() , gp[node].end() , parent)) ; 

        }
    }


    vis.assign(n+1,0) ; 

    for(ll i=1;i<=n;i++){
        degree[i] = gp[i].size(); 
        if(degree[i]==1){
            q.push(i); 
        }
    }


      while(!q.empty()){

        ll node = q.front() ; 
        q.pop() ; 
        count++; 
        ll parent =-1; 
        for(auto x : gp[node]){

            if(vis[x]==0){
            degree[x]--; 
            parent = x ; 
            vis[x] = 1 ; 
        }

        }

        if(parent!=-1){
            gp[parent].erase(find(gp[parent].begin() , gp[parent].end() , node)); 
            gp[node].erase(find(gp[node].begin() , gp[node].end() , parent)) ; 

        }
    }



    ll remaining = n - count ; 
    cout<<"The path length for special  nodes : "<<2*(remaining-1)<<endl; 

    return  0 ; 
}