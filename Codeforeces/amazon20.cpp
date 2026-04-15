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



//***
// need clarity  on this question 
// 
//  */

unordered_map<ll , ll>factorize(ll number , vector<ll>&prime){
    unordered_map<ll, ll>mp; 
 
    while(number!=1){
        ll prime_factor = prime[number];
        mp[prime_factor]++ ;
        number = number / prime_factor ;
 
    }
    return mp;
}


vector<ll>calculate_res(ll x , string s){
    vector<ll>res(s.size()+1, -1) ; 
    vector<ll>freqfirst(26 , 0); 
    vector<ll>freqsecond(26 , 0);    
    ll global = 0 ; 
    while(global<=s.size()-x-1){
       ll j = global ; 
        while(j<=global+x-1 and j<s.size()){
            freqfirst[s[j]-'a']++ ; 
            j+=1 ; 
        }

        ll k=global+x ; 
        while(k<=global+2*x-1 and k<s.size()){
            freqsecond[s[k]-'a']++ ; 
            k+=1 ;
        }

        if(freqfirst==freqsecond){
            res[global] =x ;  
        }
        freqfirst = freqsecond ; 
        freqsecond.clear() ; 
        freqsecond.assign(26, 0) ;
        global+=x ;
    }
      
    
    return res ; 
}

int main(){

    ll MD = 1e5 ; 
    vector<ll>prime(MD+1, 0); 
    string s ; 
    cin>>s ; 

    for(ll i=2; i<=MD;i++){
        prime[i] = i ; 
    }

    for(ll i=2;i<=MD;i++){
        if(prime[i]==0){
            for(ll j=i*i;j<=MD;j+=i){
                prime[j]= i; 
            }
        }
    }


    vector<vector<ll>>adj(s.size()+1) ; 


    for(ll i=1 ;i<=s.size();i++){
        unordered_map<ll, ll>mp = factorize(i, prime) ; 
        for(auto x : mp){
            adj[i].push_back(x.first) ; 
        }
    }

    vector<ll>ans(s.size()+1,-1) ; 
    for(ll i=1;i<adj.size();i++){
        vector<ll>groups = adj[i] ; 
        for(auto x : groups){
            vector<ll>res = calculate_res(x , s.substr(0,i)) ; 
            for(ll j=0;j<res.size();j+=x){
                if(res[j]!=-1 and ans[j]!=-1){
                    ans[j] = min(ans[j], res[j]) ;
                }
                else if(res[j]!=-1){
                    ans[j] = res[j] ; 
                }
            }
        }
    }




    for(ll i=0;i<ans.size();i++){
        cout<<ans[i]<<" "; 
    }

    cout<<endl;
    return 0 ; 
}