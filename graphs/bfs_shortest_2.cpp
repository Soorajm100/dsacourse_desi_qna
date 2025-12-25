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

    
    vector<ll> val(n+5);
    for (ll i = 1; i <= n; i++) {cin >> val[i];}

    vector<vector<ll>>gp(n+5); 
    for(ll i = 0 ;i<v;i++){
        ll x ,y  ; 
        cin>>x>>y; 
        gp[x].push_back(y); 
        gp[y].push_back(x); 
    }



    ll  source = 1 ; 
    vector<ll>vis(n+5 , 0); 
    vector<ll>ways(n+5 , 0); 
    vector<ll>level(n+5 , 0) ; 
    queue<ll>q; 
    q.push(source);
    vis[source] =  1 ; 
    level[source] = 0 ; 
   
 
    vector<ll>fives(n+5, 0 ); 
    vector<ll>fives_second_round(n+5, 0) ; 
      if(val[1]==5)fives[1] = 1 ; 
    while(!q.empty()){
        ll ele = q.front(); 
        q.pop(); 

        for(auto x  : gp[ele]){
            if(vis[x]==0){
               
                vis[x] = 1 ; 
                level[x] = level[ele] + 1 ; 
                if(val[x]==5){
                    fives[x] = fives[ele]  + 1 ;
                  
                }
                else{
                    fives[x] = fives[ele] + 0 ; 
                }
                 q.push(x); 
            } 
            else{
                if(level[ele] + 1 == level[x]){
                    ll  temp; 
                    if(val[x]==5){
                       temp =fives[ele] +1  ;  
                    }
                    else{
                        temp = fives[ele]; 
                    }

                    if(temp > fives[x]){
                        fives[x] = temp; 
                    }
                }
            }
        }
    }



    //**Second round required to  get the final  value of 5's for the node x */

    cout<<endl ; 
    vis.assign(n+5,0); 
    level.assign(n+5,0); 

    q.push(source) ; 
    vis[source] =  1 ; 
    level[source] = 0 ; 
      ways[1] = 1 ; 
      if(val[1]==5){
        fives_second_round[1] = 1 ;
      }
       while(!q.empty()){
        ll ele = q.front(); 

        cout<<ele<<" "<<ways[ele]<<endl;//printing that node with its number of ways to visit 
        q.pop(); 
       
        for(auto x  : gp[ele]){
            if(vis[x]==0){
                vis[x] = 1 ; 
                level[x] = level[ele] + 1 ; 
                if(val[x]==5){
                    fives_second_round[x] = fives_second_round[ele]  + 1 ;  
                }
                else{
                    fives_second_round[x] = fives_second_round[ele] + 0 ;
                }
                if(fives_second_round[x] == fives[x])ways[x] = ways[ele] + ways[x]; 
                 q.push(x); 
            } 
            else{
                if(level[ele] + 1 == level[x]){
                    ll  temp; 
                    if(val[x]==5){
                       temp =fives_second_round[ele] +1  ;  
                    }
                    else{
                        temp = fives_second_round[ele]; 
                    }

                    if(temp > fives_second_round[x]){
                        fives_second_round[x] = temp; 
                       
                    }
                    if(temp == fives[x]){
                        ways[x] = ways[ele] + ways[x] ; 
                    }
                }
            }
        }
    }








    return 0 ;
}