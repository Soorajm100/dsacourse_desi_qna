#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define fo(i, start, end) for (ll i = start; i <= end; i++)
#define pfo(i, end, start) for (ll i = end; i >= start; i--)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sortall(v) sort(all(v))
#define sumv(v) accumulate(all(v), 0LL)
int main(){
    ll n;
    cin>>n; ll k1,k2;cin>>k1>>k2;
    ll a[n+1]={0};
    fo(i,1,n){
        cin>>a[i];
    } ll c = 0 ; 
    
    fo(j,2,n-2){
        ll i = j-1;ll c1 = 0 ; 
        while(i>=1){
            if((a[i] + a[j])>k1){
                c1++;
            }
            i--;
        }

        cout<<c1<<"the c1 is"<<endl; 
        ll c2 = 0 ; 
        ll k = j + 1 ; 
        ll l = n ; 
        while(k<l){
            if((a[k]+a[l])>k2){
                c2 = c2 + abs(k-l);l--;
            }else{
                k++;
            }
        }
         cout<<c2<<"the c2 is"<<endl; 
        
        c = c1*c2;
    }
    cout<<c;
    return 0;
}








