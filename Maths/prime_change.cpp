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
    unordered_map<ll ,ll>mp1 ; 
    unordered_map<ll,ll>mp2 ; 
    ll n ; 
    cin>>n; 

    vector<ll>A(n); 
    vector<ll>B(n); 

    for(ll i=0 ; i<n;i++){
        cin>>A[i]; 
        mp1[A[i]]++ ; 
    }
    for(ll i=0 ; i<n;i++){
        cin>>B[i]; 
        mp2[B[i]]++ ; 
    }


    ll countFinal = 0 ; 
  
    for(auto x : mp1){

        ll key = x.first ; 
        ll countB = 0 ; 

        for(ll j=key ; j<=1e6;j+=key){
            countB = countB + mp2[j] ; 
        }

        ll countcurrent = countB*x.second ; 
        countFinal = countFinal + countcurrent ; 

    }


    cout<<countFinal<<endl;

    return 0 ; 
}