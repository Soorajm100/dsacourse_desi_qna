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
    cin>>n ;
    
    ll k ; 
    cin>>k ; 

    vector<ll>b(1e6 , 0) ; 

    vector<ll>a(n+1, 0);

    for(ll i=0;i<n;i++)cin>>a[i] ; 
    
    for(ll i=0;i<n;i++){

        ll l =  a[i] -k ; 
        ll r = a[i] + k ; 
        b[l] = b[l] + 1 ; 
        if(r+1<=1e6)b[r+1] = b[r+1]-1 ; 
    }

    ll ans = -1e6 ; 
    for(ll i=1;i<b.size();i++){
        b[i] = b[i-1] + b[i] ; 
        ans = max(ans , b[i]) ; 
    }

    cout<<ans<<endl; 

    return 0 ; 
}