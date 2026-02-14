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
   cin>>s;

   map<char, char>mp1 ; 
   map<char, int>mp2 ; 
    char t = 'z' ; 
   for(char i ='a' ; i <='z';  i++ , t-- ){
         mp1[i] = t; 
   }

   ll count = 0 ; 
   
   for(auto x : s){
       char target = mp1[x] ; 
       count+=mp2[target] ; 
       mp2[x]++; 
   }


   cout<<count<<endl; 
    return 0 ; 
}