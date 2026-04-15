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

ll digit_sum(ll n ){

    ll sum = 0 ; 
    while(n>0){
        sum+=n%10 ; 
        n = n/10 ; 
    }
    return sum; 

}


int main(){

    ll n ; 
    cin>>n ; 
    vector<ll>b(n+1,0) ; 
    unordered_map<ll , ll>mp ;

    for(ll i=1;i<=n;i++)cin>>b[i] ; 

    ll maxySum = -1 ; 

    ll digitSum = 0 ; 

    for(ll i=1;i<=n;i++){

        ll currnum = b[i] ; 
        ll sum = digit_sum(currnum) ;
        if(mp.find(sum)!=mp.end()){

            ll previousNum = mp[sum] ; 

            if(previousNum <  currnum){
                mp[sum] = currnum ;
            }
            if(currnum + previousNum > maxySum){
                maxySum = currnum + previousNum ; 
                digitSum = sum ;
            }
        }
        else{
            mp[sum] = currnum ; 
        }
        }

        mp.clear() ; 

        ll maxySum2 = -1 ; 
        ll count = 0 ; 

        unordered_map<ll , vector<ll>>mp2 ;


        for(ll i=1;i<=n;i++){
            ll currnum = b[i] ; 
            ll sum = digit_sum(currnum) ;

            if(digitSum == sum){
              mp2[sum].push_back(currnum) ; 
            }
        }

        vector<ll>filteredRes = mp2[digitSum] ;

        for(ll i=0;i<filteredRes.size();i++){
            ll target = maxySum - filteredRes[i] ;
            if(mp.find(target)!=mp.end()){
                count+= mp[target] ; 
            }
            mp[filteredRes[i]]++ ;
        }

    cout<<"the maximum Sum is :"<<maxySum<<endl;

    cout<<"the count of pairs with maximum sum is : "<<count<<endl;


    return 0 ; 
}