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

void four_parition_kadane(){

     ll n ; 
    cin>>n ; 
    ll sum = 0 ; 
    vector<ll>nums(n,0); 
    for(ll i=0;i<n;i++){
        cin>>nums[i] ; 
        sum = sum + nums[i] ; 
        nums[i] = nums[i]*-1 ; 
       
    }

    vector<ll>pref_max(n+1,0); 
    vector<ll>suff_sum(n+1,0) ; 
    vector<ll>suff_max(n+1,0) ; 

    for(ll i=1;i<=n-3;i++){
        pref_max[i] = max(nums[i] , nums[i] + pref_max[i-1]) ;
    }

    suff_sum[n-1] = nums[n-1]; 
    for(ll i=n-2;i>=0;i--){
        suff_sum[i] = suff_sum[i+1] + nums[i] ; 
    }

    suff_max[n-1] = nums[n-1]; 
    for(ll i=n-1;i>=0;i--){
        suff_max[i] = max(suff_sum[i] ,suff_max[i+1]) ; 
    }

    ll max_sum = -1e18 ; 

    for(ll i=1;i<=n-3;i++){
        ll sum_temp = pref_max[i] ; 
        ll fourth_temp = suff_max[i+2] ;
        max_sum = max(max_sum , sum_temp + fourth_temp) ;
    }

    cout<<"The final  ans"<<endl;
    cout<<sum<<" "<<sum - 2*(-1*max_sum)<<endl;

}


void three_paritition_kadane(){
    ll n ; 
    cin>>n ; 
    ll sum = 0 ; 
    vector<ll>nums(n,0); 
    for(ll i=0;i<n;i++){
        cin>>nums[i] ; 
        sum = sum + nums[i] ; 
        nums[i] = nums[i]*-1 ; 
       
    }


    ll max_sum = -1e18 ; 
    ll  sum_temp =  0 ; 

    for(ll i=1;i<=n-2;i++){
        sum_temp  = sum_temp + nums[i] ; 
        if(sum_temp < 0){
            sum_temp = 0 ; 
        }
        else{
            max_sum = max(max_sum , sum_temp ) ; 
        }

        max_sum = max(max_sum , nums[i]) ; 
    }
    cout<<"The final  ans"<<endl;
    cout<<sum<<" "<<max_sum<<endl;
    cout<<sum - 2*(-1*max_sum) <<endl; 


}

int main(){


    //three_paritition_kadane() ; 

    four_parition_kadane() ;




    return 0 ; 
}