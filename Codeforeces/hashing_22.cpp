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
    cin>> n;

    vector<ll>b(n+1 , 0); 
    unordered_map<ll,ll>mp ; 
    for(ll i=1;i<=n;i++)cin>>b[i] ;


    for(ll i=1;i<=n;i++){
        mp[b[i]]++ ; 
    }


    ll ans = 0 ; 
    bool flag = false ; 

    for(auto x : mp){
        ll freq = x.second ; 
        if(freq==1){
            flag = true ; 
            break ; 
        }
        else {
            ans+=(freq/3) + (freq%3!=0 and freq%3!=1) ; 
        }
    }

    if(flag){
        cout<<-1<<endl; 
    }
    else{
        cout<<ans<<endl;
    }

    return 0 ;

}