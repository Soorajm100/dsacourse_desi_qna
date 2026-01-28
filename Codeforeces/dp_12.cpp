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
    
    for(ll i=0;i<n;i++)cin>>a[i]; 
    for(ll i=0 ; i<n;i++)cin>>b[i]; 
    ll dpa_even[20006] , dpa_odd[20006] , dpb_even[20006] , dpb_odd[20006]; 

    // if a[i] is even  and dpa_even[i] is nothing but even  ssum  till  index i  by seldcting a[i] at the index i 
    // dpa_odd[i] is nothing but sum  till  index i is odd by selecint thr element at the index i is odd. 


    dpa_even[0] = a[0]%2==0 ? 1 : 0 ; 
    dpa_odd[0] = a[0]%2==1 ? 1 : 0 ; 
    dpb_even[0] = b[0]%2==0 ? 1 : 0 ; 
    dpb_odd[0] = b[0]%2==1 ? 1 : 0 ; 



    for(ll i=1;i<n;i++){

    if(a[i]%2==0){
        dpa_even[i] = dpa_even[i-1] + dpb_even[i-1]; 
        dpa_odd[i]  = dpa_odd[i-1]  + dpb_odd[i-1]; 
    }
    else{
        dpa_even[i] = dpa_odd[i-1]  + dpb_odd[i-1]; 
        dpa_odd[i] =  dpa_even[i-1] + dpb_even[i-1]; 
    }

     if(b[i]%2==0){
        dpb_even[i] = dpb_even[i-1] + dpa_even[i-1]; 
        dpb_odd[i]  = dpa_odd[i-1]  + dpb_odd[i-1]; 
    }
    else{
        dpb_even[i] = dpa_odd[i-1]  + dpb_odd[i-1]; 
        dpb_odd[i] =  dpa_even[i-1] + dpb_even[i-1]; 
    }
}

cout<<"even  sum  paths "<<dpa_even[n-1] + dpb_even[n-1]<<endl; 
cout<<"Odd  sum  paths "<<dpa_odd[n-1] + dpb_odd[n-1]<<endl; 


    return 0 ; 
}