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
    unordered_map<ll, vector<ll>>G; 
    cin>>n; 
    ll Q; 
    cin>>Q  ; 
    vector<ll>arr(n+1, 0); 
    unordered_map<ll, vector<ll>>Goriginal; 

    for(ll i=0;i<n;i++){
        cin>>arr[i] ; 
    }

    for(ll i=0;i<n;i++){
        ll ele = arr[i] ; 
        Goriginal[ele].push_back(i); 
        G[ele].push_back(i); 
    }

    for(auto x : G){
        vector<ll> v = x.second ; 
        for(ll i =1;i<v.size();i++){
            v[i] = v[i-1] + v[i] ; 
        }

        G[x.first] = v ; 
    }

    for(ll i =0 ;i<Q;i++){
        ll l , r , k , y ; 
        cin>>l>>r>>k>>y; 
        ll ans = upper_bound(Goriginal[y].begin() ,Goriginal[y].end()  , l-1) - Goriginal[y].begin() ; 
        if (ans ==-1 or ans +k -1 > G[y].size() or G[y][ans+k-1] > r){
            cout<<-1<<endl ;
        }
        else{
            if(ans-1>=0){
                cout<<G[y][ans+k-1]-G[y][ans-1]<<endl; 
            }
        }
    }
    

    


    return 0 ; 

}