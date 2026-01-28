#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vipair = vector<pair<ll, ll>>;

template <class T>
using v = vector<T>;

const int INF_INT = 1e9;
const ll INF_LL = (1LL << 60);
const int MOD = 1000000007;


int main(){
    ll n ; 
    cin>>n; 
    vector<string> s(n);
    for(ll i=0;i<n;i++) {
        cin >> s[i];
    }
    vector<ll>b(n);

    for(ll i=0;i<n;i++){
        ll mask =  0 ; 
        for(ll j=0;j<s[i].size();j++){
            ll v = s[i][j] - 'a'; 
            mask  =  mask^(1<<v); 
        }
        b[i] = mask;
    }

    map<ll , ll>mp ; 
    ll count = 0 ; 

    for(ll y=0;y<=n-1;y++){
        count = count  + mp[b[y]] ;
        ll temp = b[y] ; 
        
        
        for(ll z=0;z<26;z++){
            temp = (temp^(1<<z)) ;
            count = count + mp[temp];
             temp = (temp^(1<<z)) ;
        }

        mp[b[y]]++ ;
    }


    cout<<count<<endl; 

   


    return 0 ; 
}