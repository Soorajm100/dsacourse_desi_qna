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

    vector<ll>easy(n+1 , 0) , hard(n+1,0) , medium(n+1,0) ;
    
    for(ll i=1;i<=n;i++)cin>>easy[i] ; 
    for(ll i=1;i<=n;i++)cin>>medium[i] ;
    for(ll i=1;i<=n;i++)cin>>hard[i] ;

    vector<ll>dp_easy(n+1,0) , dp_medium(n+1,0) , dp_hard(n+1,0)  ;

    dp_easy[1] = easy[1] ; 
    dp_medium[1] = medium[1] ;
    dp_hard[1] = hard[1] ;


    /**
    *  rules :  on day i  hard task  can be done if the day  i-2 day  you did easy  task  
    *           on day  i  you  do  medium  task  only if i-1 easy  taask  and i-2 medium task 
    */

    dp_easy[2] = easy[2] + max({easy[1] , medium[1] , hard[1]}) ;
    dp_medium[2] = medium[2] + max({easy[1] , medium[1] , hard[1]}) ;
    dp_hard[2] = hard[2] + max({easy[1] , medium[1] , hard[1]}) ;

    dp_easy[3] = easy[3] + max({dp_easy[2] , dp_medium[2] , dp_hard[2]}) ;
    dp_medium[3] = medium[3] + easy[2] + dp_medium[1] ; 
    dp_hard[3] = hard[3] + easy[1]  + max({easy[1] , medium[1] , hard[1]}) ;

    for(ll i=4;i<=n;i++){
        dp_easy[i] = easy[i] + max({dp_easy[i-1] , dp_medium[i-1] , dp_hard[i-1]}) ;
        dp_medium[i] = medium[i] + easy[i-1] + dp_medium[i-2] ; 
        dp_hard[i] = max({dp_hard[i] , hard[i] + medium[i-1]  + easy[i-2] + dp_medium[i-3] , hard[i] + easy[i-2]  + hard[i-1] + dp_easy[i-3]  , hard[i] , easy[i-1]  + dp_easy[i-2]  }) ; 
    }

    cout<<max({dp_easy[n] , dp_medium[n] , dp_hard[n]})<<endl;

    return 0 ; 
}