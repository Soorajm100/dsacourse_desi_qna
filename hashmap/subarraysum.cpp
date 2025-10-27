#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

int main(){
    vector<int>a={1, 0 ,  1 , 2 ,10,5};


    /*1 3 6 
    
    

    */
    int n = a.size();  
    vector<int>pref(n,0);
    pref[0] = a[0];  
    map<int, int>mp; 
    int sum = 3 ; 
    int count = 0; 

    for(int i=1;i<n;i++){
        pref[i]=  pref[i-1]+ a[i];
    }

    for(auto x :pref)cout<<x<<" "; 
    cout<<endl; 
    for(int i=0;i<n;i++){
       int element = pref[i] - sum ; 
       if(mp.find(element)!=mp.end()){
           count +=mp[element]; 
       }
       mp[pref[i]]++ ;  
    }

    cout<<"Total count of subarrays include "<<count<<endl; 



    return 0; 
}