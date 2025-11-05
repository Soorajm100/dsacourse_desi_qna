#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T>
using v = vector<T>;

const int INF_INT = 1e9;
const ll INF_LL = (1LL << 60);
const int MOD = 1000000007;

static bool  comp(int a , int b){
    return a > b; 
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi  a = {-1,3,2,5,4,6}; 
    vi  b = {-5,2,1,6,4,3} ; 


    sort(a.begin(), a.end());
    sort(b.begin() , b.end(), comp); 

    ll total=0; 

    for(int i=0; i<a.size(); i++){
        total += a[i] * 1LL * b[i]; 
    }
    cout <<"the minimum  sum possible from  greedy " <<total << "\n";
    
    sort(b.begin(), b.end());

    total = 0; 
    for(int i=0; i<a.size(); i++){
        total += a[i] * 1LL * b[i]; 
    }
    cout <<"the maximum  sum possible from  greedy " <<total << "\n";




    return 0; 
}




