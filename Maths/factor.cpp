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

    vector<ll>factors ; 

    ll n ; 
    cin>>n ; 

    for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            factors.push_back(i) ; 
            if(i!=n/i){
                factors.push_back(n/i) ; 
            }
        }
    }

    sort(factors.begin(),factors.end()) ;
    for(auto x : factors){
        cout<<x<<" " ; 
    }


    return 0 ; 

}