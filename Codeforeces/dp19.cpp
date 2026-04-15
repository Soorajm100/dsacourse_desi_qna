
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
    cin>>n;
    vector<ll>a(n+1, 0); 
    vector<ll>b(n+1 , 0) ; 

    ll dpa[n+1][2] ;
    ll dpb[n+1][2] ; 
    
    for(ll i=1;i<=n;i++)cin>>a[i] ;
    for(ll i=1;i<=n;i++)cin>>b[i] ;


    dpa[1][0] = a[1]%2==0 ? 1 : 0 ; 
    dpa[1][1] = a[1]%2==1 ? 1:0 ; 
    dpb[1][0] = b[1]%2==0 ? 1 : 0 ; 
    dpb[1][1] = b[1]%2==1 ? 1 : 0 ; 


    for(ll i=2 ; i<=n;i++){

        if(a[i]%2==0){
            dpa[i][0]  = dpa[i-1][0]  + dpb[i-1][0] ;
            dpa[i][1]  = dpa[i-1][1] + dpb[i-1][1] ; 
        }
        else{
            dpa[i][0] = dpa[i-1][1] + dpb[i-1][1] ; 
            dpa[i][1]  = dpa[i-1][0] + dpb[i-1][0] ; 
        }

        if(b[i]%2==0){

            dpb[i][0] = dpb[i-1][0] + dpa[i-1][0] ;
            dpb[i][1] = dpb[i-1][1] + dpa[i-1][1] ;
        }
        else{
            dpb[i][0] = dpb[i-1][1] + dpa[i-1][1] ; 
            dpb[i][1] = dpb[i-1][0] + dpa[i-1][0] ;

        }
    }

    cout<<"the even journey  numbers : "<<dpa[n][0] + dpb[n][0]<<endl;
    cout<<"the odd journey numbers  :"<<dpa[n][1] + dpb[n][1]<<endl;

    return 0 ; 
}