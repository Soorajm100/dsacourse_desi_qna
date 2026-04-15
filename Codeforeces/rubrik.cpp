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
ll modfunc(ll num , ll p ){
    ll val= 1 ; 
    for(ll i=1;i<=4;i++){
        val  = val*num ; 
        val = val% p ; 
    }

    return val ; 
}


int main(){
    ll n ,p ,k  ; 
    cin>>n>>p>>k ; 

    vector<ll>a(n+1, 0); 
    unordered_map<ll,ll>mp; 
    for(ll i=0;i<n;i++)cin>>a[i] ; 

    for(ll i=0;i<n;i++){
        ll res = (modfunc(a[i] ,p)  - (k*a[i])%p + p )%p ;  
        mp[res]++ ;  
    }

    ll ans = 0 ; 
    for(auto x : mp){
        ll total = x.second; 
        ll pairs = total*(total-1)/2 ; 
        ans+=pairs ; 
    }

    cout<<ans<<endl; 
    



    return 0 ; 
}