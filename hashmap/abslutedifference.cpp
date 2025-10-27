#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

int main(){
    int target = 2 ; 

    vector<int>a = {1,5,3,4,2}; 
    int n = a.size(); 
    map<int, int>mp ; 
    int count = 0; 
    for(int i=0;i<n;i++){
        int ele = a[i]; 
        if(mp.find(target + a[i])!=mp.end()){
           count+=mp[target + a[i]]; 
        }
        if(mp.find(a[i]- target)!=mp.end()){
           count+=mp[a[i]-target]; 
        }
        mp[a[i]]++;
    }

    cout<<"Total  count for this conditin  to work"<<count<<endl; 


    /**Prefix sum  vector */

   cout<<endl; 
   cout<<" Prefix sum implementation "<<endl ; 

   vector<int>pref(n+1, 0) ; 
   pref[0] = a[0] ; 

   for(int i=0;i<n;i++){
    pref[i] = pref[i-1] + a[i]; 
   }

   int l = 0 , r= 4  ;

   cout<<pref[r]-  pref[l] + a[l]<<endl; 






    return 0 ; 
}