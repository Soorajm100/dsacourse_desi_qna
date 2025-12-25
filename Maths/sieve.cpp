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



vector<ll>sieveRange(ll l , ll r){
    ll st = sqrt(r) ; 
    vector<ll>prime(r+1 , 1);
    prime[0] = 0; 
    prime[1] = 0 ;

    for(ll i=2; i<=st;i++){
        if(prime[i]==1){
            for(ll j=i*i; j<=r;j+=i){
                prime[j] = 0 ; 
            }
        }
    }

    vector<ll>ans; 

    for(ll i =0;i<=r;i++){
        if(prime[i]==1 and i>=l){
            ans.push_back(i); 
        }
    }



    return ans; 
}

int main(){

    //vector<ll>sieve(MOD,0); 
    ll l , r ; 

    cin>>l>>r; 

    ll start  = l ; 
    ll  end = r ;

    vector<ll>ans = sieveRange(start ,end) ; 

    for(auto x : ans){
        cout<<x<<" "; 
    }

    return 0 ; 
}