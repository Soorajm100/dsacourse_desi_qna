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


unordered_map<ll , ll>factorize(ll number , vector<ll>&prime){
    unordered_map<ll, ll>mp; 

    while(number!=1){
        ll prime_factor = prime[number];
        mp[prime_factor]++ ;
        number = number / prime_factor ;
        
    }
    return mp;
}



int main(){

   
    ll MD = 1e6 ; 
    vector<ll>prime(MD+1 , 0); 

    for(ll i=2; i<=MD;i++){
        prime[i] = i ; 
    }


    for(ll  i = 2; i<=MD;i++){
        if(prime[i]==i){
            for(ll j =i*i;j<=MD;j+=i){
                if(prime[j]==j){
                    prime[j] = i ;
                } 
            }
        }
    }

    ll n ; 
    cin>>n ; 


    vector<ll>ans(n+1 , 0); 

    for(ll i =1 ;i<=n;i++){
        cin>>ans[i]; 

        unordered_map<ll , ll>mp  = factorize(ans[i] , prime);
        cout<<"For the number : "<<ans[i]<<" these are the factors "<<endl; 
        for(auto x : mp){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    
    return 0 ; 
}