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
    ll n ,k ;
    cin>>n>>k; 

    vector<ll>a(n+1,0); 
    vector<ll>l(k+1,0); 
    vector<ll>s(k+1,0) ; 
    vector<vector<ll>>dp(2001, vector<ll>(2001,1e10));
    dp[0][0] = 0 ; 

    for(ll i=1;i<=n;i++)cin>>a[i] ; 
    for(ll i=1;i<=k;i++)cin>>l[i] ;
    for(ll i=1;i<=k;i++)cin>>s[i] ;


    for(ll i=1;i<=n;i++){
     
            if(a[i]==a[i-1]){
                dp[i][0] = dp[i-1][0] + s[a[i]]; 
                dp[0][i] = dp[0][i-1] + s[a[i]] ; 
            }
            else{
                dp[i][0] = dp[i-1][0] + l[a[i]]; 
                dp[0][i] = dp[0][i-1] + l[a[i]] ; 
            }
        
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(i!=j){
                if(i>j){
                    if(i==j+1){
                        ll l1 = 2 ; 
                        ll pans = 1e8 ; 
                        while(i-l1>=0){
                            if(a[i-l1]==a[i]){
                                pans = dp[i-l1][j] + s[a[i]] ; 
                            }
                            else{
                                pans = dp[i-l1][j] + l[a[i]] ; 
                            }
                            dp[i][j] = min(pans , dp[i][j]); 
                            l1++; 
                        }

                    }
                    else{
                        ll pans = 1e8 ; 

                        if(a[i]==a[i-1]){
                            pans = dp[i-1][j] + s[a[i]] ; 
                        }
                        else{
                            pans = dp[i-1][j] + l[a[i]] ; 
                        }
                         dp[i][j] = min(dp[i][j] ,pans) ; 

                    }
                }
                else{
                    if(i==j-1){
                        ll l1 = 2 ; 
                        ll pans = 1e8 ; 
                        while(j-l1>=0){
                            if(a[j-l1]==a[j]){
                                pans = dp[i][j-l1] + s[a[j]] ; 
                            }
                            else{
                                pans = dp[i][j-l1] + l[a[j]] ; 
                            }
                            dp[i][j] = min(pans , dp[i][j]); 
                            l1++; 
                        }

                    }
                    else{
                        ll pans = 1e8 ;
                         if(a[j]==a[j-1]){
                            pans = dp[i][j-1] + s[a[j]] ; 
                        }
                        else{
                            pans = dp[i][j-1] + l[a[j]] ; 
                        }

                        dp[i][j] = min(dp[i][j] ,pans) ; 

                    }
                }
            }
        }

    }



    ll ans = 1e16; 
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            ans = min(ans , dp[i][n]); 
            ans = min(ans , dp[n][i]); 
        }
    }


    cout<<ans<<endl ;


    return 0; 
}