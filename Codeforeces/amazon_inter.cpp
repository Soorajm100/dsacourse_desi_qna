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

    string s ; 
    string target ; 
    cin>>s>>target ; 

    unordered_map<char ,ll>mp ; 
    unordered_map<char, ll>mp2 ; 

    for(auto x : s){
        mp[x]++ ; 
    }

    for(auto x : target){
        mp2[x]++; 
    }

    ll  ans = 1e9 ; 
    for(auto  x : target){
        ans = (int)(mp[x]/mp2[x]) ; 
    }

    cout<<ans<<endl; 

    return 0 ; 
}