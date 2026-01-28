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
    ll n; 
    cin>>n; 
    vector<ll>a(n,0); 
    vector<ll>b(n,0); 
    vector<ll>c(n,0); 

    for(ll i =0;i<n;i++){
        cin>>a[i];
    }

      for(ll i =0;i<n;i++){
        cin>>b[i];
    }

      for(ll i =0;i<n;i++){
        cin>>c[i];
    }

    ll count = 0 ; 
    ll countFirstPart = 0; 

    //***  so  the function  of the second loop  is to  get the start  index in  first array  finding for all cmbinatins of i , j 
    //     now start  does the good work  of holding the condition  for all the lelements of ai<bi so  for all  the elements in  ai , start  does the good work  of checking whwther the pa
    //     pattern  follows for all  element in  bi as well. 
    // 
    //   */

    for(ll i=0;i<n;i++){

         ll valid = 1 ; 
         ll start = i ; 

        for(ll j=0;j<n;j++){
               
                if(a[j] < b[start]){

                }
                else{
                    valid = 0 ; 
                }

                start++; 

                if(start >= n )start = 0;
              
            }

        if(valid==1){
            countFirstPart++; 
        }
    } 
     //***  so  the function  of the second loop  is to  get the start  index in  first array  finding for all cmbinatins of i , j 
    //     now start  does the good work  of holding the condition  for all the lelements of bi<ci so  for all  the elements in  ai , start  does the good work  of checking whwther the pa
    //     pattern  follows for all  element in  ci as well. 
    // 
    //   */

        ll countSecondPart = 0;

    for(ll i=0;i<n;i++){

        ll valid = 1 ; 
        ll start = i ; 

        for(ll j=0;j<n;j++){
               
                if(b[j] < c[start]){

                }
                else{
                    valid = 0 ; 
                }

                start++; 

                if(start >= n )start = 0;
         }

        if(valid==1){
                    countSecondPart++; 
        }
    } 
    


    //*****
    //     for every  i,j find the number of ci possible and  also  find the count of unique (i,j) pairs possible  , the answer  would be  count(i,j)*count(ci)*n  , n is multiplied for a 
    //     reasin  as every  unique pair has n rotations possible  , i mean (1 , 2) follows the same rotations as (2,3) , (3,4) ... (n,1)
    //  */
    

    cout<<n*countFirstPart*countSecondPart<<endl; 

}

int main(){

    ll  test; 
    cin>>test; 


    while(test--){
        solve(); 
    }



    return 0 ; 
}