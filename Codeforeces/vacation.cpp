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
    cin>>n; 
    vector<ll>a(n,0); 
    vector<ll>b(n,0); 
    vector<ll>c(n,0); 

    vector<ll>dpa(n,0); 
    vector<ll>dpb(n,0); 
    vector<ll>dpc(n,0); 

    for(ll i=0;i<n;i++){
        cin>>a[i]; 
        cin>>b[i] ; 
        cin>>c[i] ; 
    }


    dpa[0] = a[0]; 
    dpb[0] = b[0]; 
    dpc[0] = c[0] ; 
    for(ll i=1;i<n;i++){

        dpa[i] = a[i] + max(dpb[i-1] ,  dpc[i-1]); 
        dpb[i] = b[i] +  max(dpc[i-1] ,  dpa[i-1]); 
        dpc[i] = c[i] +  max(dpb[i-1] ,  dpa[i-1]); 
    }


    // for(auto x  :dpa)cout<<x<<" "; 
    // cout<<endl; 
    //  for(auto x  :dpb)cout<<x<<" "; 
    // cout<<endl; 
    //  for(auto x  :dpc)cout<<x<<" "; 
    // cout<<endl; 


    cout<<max({dpa[n-1] , dpb[n-1] , dpc[n-1]})<<endl ; 



    return 0; 
}