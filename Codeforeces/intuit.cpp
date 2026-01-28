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

  
    string res  ; 
    cin>>res; 

    // n  queries
    ll n ; 
    cin>>n; 
    vector<ll>queryType(n,0); 
    
    /// -1 for type1 queries because no  setting 
    vector<ll>Indice(n,0) ; 


    for(ll i =0 ;i<n;i++){
        cin>>queryType[i] ; 
        cin>>Indice[i] ; 
    }

    set<ll>st1, st2 ; 


    for(ll i =0;i<res.size();i++){

        if(res[i]=='0'){
            st1.insert(i); 
        }

        if(res[i]=='1'){
            st2.insert(i); 
        }
    }

    for(ll i =0;i<n;i++){
        if(queryType[i]==1){
            if(st1.size()>0){
            ll  initialIndex = *st1.begin();
            st1.erase(initialIndex); 
            st2.insert(initialIndex); 
            res[initialIndex] = '1';
            }
            else{
                continue; 
            }
        }

        if(queryType[i]==2){
            ll modifyIndex = Indice[i] ; 
            if(res[modifyIndex]=='0'){
                continue; 
            }
            else{
                st1.insert(modifyIndex) ; 
                st2.erase(modifyIndex); 
                res[modifyIndex] = '0'; 
            }
        }
    }


    cout<<"the final  string : "<<res<<endl; 

    return 0 ; 
}