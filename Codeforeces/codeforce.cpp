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



void solve(){
    ll n ; 
    cin>>n; 

    vector<ll>res(n+1 , 0) ; 
    res[n] = 1 ; 

    for(ll i=2;i<=n-1;i++){
        res[i] = i^1 ; 
    }

    res[1] =n ; 

    if(n%2!=0)res[1] = n-1 ; 

    for(ll i=1;i<=n;i++)cout<<res[i]<<" "; 

    cout<<endl; 

}


int main(){

    ll test ; cin>>test ; 
    while(test--){
        solve() ; 
    }

    return 0 ;
}