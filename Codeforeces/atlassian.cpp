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

    ll b ;
    cin>>b;  
    ll dp1[b+1] ; 
    ll dp2[b+1]; 

    dp1[0] = 1 ; 
    dp2[0] = dp1[0] ; 
    
    for(ll i=1 ;i<=b;i++){

    char ch ; 
    cin>>ch ; 

    if(ch=='+'){
        ll val ; 
        cin>>val; 
        dp1[i] = max({dp1[i-1] + val ,dp2[i-1] + val  , dp1[i-1] }); 
        dp2[i] = min({dp2[i-1] + val , dp1[i-1] + val , dp2[i-1]});
    }
    else if(ch=='-'){
        ll val ; 
        cin>>val; 
        dp1[i] = max({dp1[i-1] - val ,dp2[i-1] - val  , dp1[i-1] }); 
        dp2[i] = min({dp2[i-1] - val , dp1[i-1] - val , dp2[i-1]});
    }
    else if(ch=='*'){
        ll val ; 
        cin>>val; 
        dp1[i] = max({dp1[i-1]*val , dp2[i-1]*val , dp1[i-1]}); 
        dp2[i] = min({dp1[i-1]*val , dp2[i-1]*val , dp2[i-1]});
    }
    else if(ch=='/'){
        ll val ; 
        cin>>val; 
        dp1[i] = max({dp1[i-1]/val , dp2[i-1]/val , dp1[i-1]}); 
        dp2[i] = min({dp1[i-1]/val , dp2[i-1]/val , dp2[i-1]});
    }
    else{
        dp1[i] =  max({dp1[i-1]*-1 , dp2[i-1]*-1 , dp1[i-1]});
        dp2[i] =  min({dp1[i-1]*-1 , dp2[i-1]*-1 , dp2[i-1]});

    }
 }

 cout<<dp1[b]<<endl; 

 return ; 


}



int main(){

    ll test; 
    cin>>test; 

    while(test--){
        solve(); 
    }

    return 0;  
}