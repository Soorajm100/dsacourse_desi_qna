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
 
void solve(){
    ll m , n ; 
    cin>>n>>m  ; 
    vector<vector<ll>>g(n) ;
    vector<ll>col(m,0);  
    map<ll , vector<ll>>mp ; 
    ll count = 0 ; 
 
    for(ll i =0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll x ; 
            cin>>x ; 
            if(x==1)count++; 
            g[i].push_back(x) ; 
        }
    }
 
    ll ans= 0 ; 
 
 
    for(ll j=0;j<m;j++){
        for(ll i=0;i<n;i++){
            col[j]+=(g[i][j]==1 ? 1 : 0) ; 
            if(g[i][j]==1){
                mp[j].push_back(i);
            }
        }
    }
    ll pref = 0 ; 
    if(count%2==0){
        ans = count/2 ;
        ll  res = ans ;  
        ans = ans*ans ; 
    }
    else{
        ans = (count/2)*(count/2 + 1) ; 
    }


      ll res = count/2; 
      string path= "" ; 
        for(ll i=0;i<m;i++){
            pref = col[i] ; 
            if(pref > res){
               ll eletaken = abs(pref - res) ; 
                 vector<ll>indices = mp[i] ; 
                 ll currind = indices[indices.size()-eletaken-1] ; 
                 ll tempind = currind ; 
                 while(currind--)path+='D' ; 
                 path+='R' ; 
                 ll downTrack = n-tempind ; 
                 while(downTrack--)path+='D'; 
                 ll rightTrack = (m - (i+1)) ; 
                 while(rightTrack--)path+='R'; 
                 break ; 
            }
            else if(pref < res){
                path+='R' ; 
                res = res - col[i] ; 
            }
            else{
                res = res - col[i] ;
            	ll downTrack = n ; 
            	while(downTrack--)path+='D'; 
                ll rightTrack = (m - (i+1)) ; 
                while(rightTrack--)path+='R'; 
                break ;
            }
        }
 
        cout<<ans<<endl; 
        cout<<path<<endl; 
 
    return  ; 
 
}
 
 
int main(){
    ll test; 
    cin>>test ; 
 
    while(test--){
        solve() ; 
    }
 
    return 0 ; 

}