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

bool checkPalidrome(string &s){

    map<char, ll>freq ; 

    for(ll i=0;i<s.size();i++){
        freq[s[i]]++ ; 
    }

    ll evenCount = 0 ; 
    ll  oddCount = 0 ; 
    for(char i='a';i<='z';i++){
        if(freq[i]%2==0){
            evenCount++; 
        }
        else{
            oddCount++ ; 
        }
    }

    if(evenCount>=25)return  true; 

    return false ; 
}


int main(){


    //*  the brute force approach*/
    ll n ; 
    cin>>n; 
    vector<string> s(n);
    for(ll i=0;i<n;i++) {
        cin >> s[i];
    }
    ll count = 0 ; 
    for(ll i=0;i<n;i++){
        for( ll j=i+1;j<n;j++){
            string res  =s[i] + s[j] ; 
            if(checkPalidrome(res)==true){
               count++; 
            }
        }
    }

    cout<<count<<endl; 

    return 0 ; 
}