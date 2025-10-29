#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;

using vi  = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

template<class T> using v = vector<T>;

const int INF_INT = 1e9;
const ll  INF_LL  = (1LL<<60);
const int MOD = 1000000007;


int main() {
    vi  a = {10,20,30,40,50,60,70,80,90,100};
    int n = a.size();


    ll  start = 0 ; 
    ll  target = 60 ; 
    ll  end = n- 1; 
    ll  ans = -1 ; 

    while(start<=end){

        ll mid = (start + end)/2 ; 
        if(a[mid]<=target){
            start = mid+1 ; 
        }
        else if (a[mid] > target){
            ans = mid ; 
            end = mid -1 ; 
        }

    }



    cout<<"The upper bound index for "<< target <<" is: "<< ans << "The element is "<<a[ans]<< endl;

    return 0;
}