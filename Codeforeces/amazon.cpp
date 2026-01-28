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
    cin>>n ; 
    vector<ll>a(n,0); 
    string s; 
    for(ll i =0;i<n;i++){
        cin>>a[i];
    }
    cin>>s;

    vector<ll>dp1(n+1, 0); 
    vector<ll>dp2(n+1,0); 


    dp1[0] = s[0]=='0' ? 0 : a[0]; 
    dp2[0] = a[0] ; 

    for(ll i=1;i<n;i++){

        if(s[i]=='0'){

            dp1[i] = 0 + dp1[i-1]; 
            dp2[i] = a[i] + dp1[i-1] ; 

        }
        if(s[i]=='1'){
            dp1[i] = max(a[i] + dp1[i-1] , 0 + dp2[i-1]); 
            dp2[i] = a[i] + dp2[i-1]; 

        }

    }


    cout<<"the best answer for array  of size N such  that  no  extra 1 is getting inserted from  left "<<dp1[n-1] <<endl; 


    return 0 ; 
}


