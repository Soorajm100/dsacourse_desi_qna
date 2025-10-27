#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";


/**Zscaler OA */
int main(){
    int n ; 
    cin>>n ; 
    vector<int>a(n,0); 
    for(int i=0;i<n;i++){
        cin>>a[i]; 
    }

    map<int, int>k; 

    for(auto x :a)k[x]++; 

    vector<int>freq; 
    bool flag = true; 
    for(auto x : k){
        if(flag ==false){
            freq.push_back(x.second); 
        }

        flag = false; 
    }

    vector<int>pref(freq.size(), 0); 

    if(freq.size()>0){
        pref[0] = freq[0]; 
        for(int i=1;i<freq.size();i++){
            pref[i] = pref[i-1] + freq[i]; 
        }

        cout<<accumulate(pref.begin() , pref.end() , 0)<<endl; 
    }

    return 0; 
}
