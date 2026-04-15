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

ll  get_sub_arr(vector<ll>&a , ll n ){

   ll prefix = 0 ; 
   ll even_sub_arr = 1 ; 
   ll odd_sub_arr = 0 ; 
   ll count = 0; 


   for(ll i=1;i<=n;i++){
     prefix+= a[i] ; 
     ll parity = -1 ; 

     if(prefix%2==0){
        parity = 0 ; 
     }
     else{
        parity = 1 ; 
     }

     if(parity==0){
        count+=even_sub_arr; 
        even_sub_arr++; 
     }
     else if(parity==1){
        count+=odd_sub_arr ;
        odd_sub_arr++; 

     }
   }

   return count; 

}

int main(){


     ll n ; 

    cin>>n ; 

    vector<ll>a(n+1,0); 
    for(ll i=1;i<=n;i++)cin>>a[i] ; 
    ll global_ans = get_sub_arr(a , n ) ; 
    for(ll i=1;i<=n;i++){
            ll prev_val = a[i]; 
            a[i]+=1; 
            ll valid_sb_arr = get_sub_arr(a , n ) ; 
            global_ans = max(global_ans,valid_sb_arr );
            a[i] = prev_val; 
    }

    cout<<"The max subarray  count for even  after chaning only one ele in arr in all  combinations : "<<global_ans<<endl; 
    return  0 ; 
}