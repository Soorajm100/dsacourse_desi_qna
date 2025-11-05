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

static bool  comp(pair<ll, ll> a , pair<ll, ll> b){
    return a.first > b.first; 
}

int main(){
    int n  ; 
    cin >>n ; 
    vipair  at(n); 

    for(ll i=0;i<n;i++){
        ll a, b; 
        cin>>a>>b; 
        at[i] = {a,b}; 
    }

    vector<pair<ll, ll>> threat(n); 

    for(ll i=0;i<n;i++){
        ll riskFactor =(at[i].second - at[i].first) ;
        threat[i] = {riskFactor, i};
    }

    ll  constantPart = 0; 

    for(ll i =1;i<=n;i++){
        constantPart += at[i-1].first * (n)  - at[i-1].second;
    }
    sort(threat.begin(), threat.end(), comp);
    ll  totalDissatisfaction =0 ;

    for(ll j=1 ; j<=n;j++){
        totalDissatisfaction+= threat[j-1].first * (j);
    }

    cout<< totalDissatisfaction  + constantPart<<"\n";


    return 0; 
}