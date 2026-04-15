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
    vector<ll>arr(n+1, 0); 
    for(ll i=1;i<=n;i++)cin>>arr[i] ; 

    vector<ll>pref(n+1,1e8) ;
    bool ans = false; 
    pref[1] = arr[1]; 
    for(ll i=2;i<=n;i++){
        pref[i] = min(pref[i-1] , arr[i]) ; 
    }
    set<ll>st; 
    st.insert(arr[n]); 
    for (ll j=n ; j>=2 ; j--){
        ll arrj = arr[j] ; 
        ll arri = pref[j-1]  ; 

        auto ele = st.upper_bound(arri); 

        if(ele!=st.end()){
            ll arrk = *ele;
            if( arrj > arrk and arrk > arri){
                ans = true; 
                break ; 
            } 
        }

        st.insert(arr[j]); 
    }

    cout<<ans<<endl ;
    return 0 ; 
}