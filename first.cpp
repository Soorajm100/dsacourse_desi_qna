#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

void solve()
{
    ll n; 
    cin>>n;
    vector<ll>ans(n+1,0); 
    for( ll i=1;i<=n;i++){
        cin>>ans[i]; 
    }

    ll zerocount = 0 ; 
    for(ll i=1;i<=n;i++){
        if(ans[i]==(n + zerocount + 1 -i )){
            zerocount+=i-1; 
            cout<<ans[i]<<endl;
        }
    }

    cout<<n+zerocount<<endl;
   
    
}
 
int main()
{
    ll test;
    test = 1 ; 

    while(test--)
    {
        solve();
    }

     system("pause");  

    return 0;
}