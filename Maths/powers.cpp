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

    unordered_map<ll , ll>mp; 
    ll n ; 
    cin>>n; 


   while(n%2==0){
      mp[2]++; 
      n =n/2 ; 
   }

	for(ll i =3 ; i<=sqrt(n);i+=2){
        while(n%i==0){
            mp[i]++; 
            n = n /i ; 
        }
    }

	if (n > 2){
		mp[n]++;
    }
    
    for(auto x : mp){
        cout<<x.first<<" "<<x.second<<endl; 
    }
    
    return 0 ; 
}