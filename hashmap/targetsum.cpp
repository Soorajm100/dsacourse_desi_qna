#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";


int main(){

    int n  = 5; 
    int target = 5;

    vector<int>b = {1,2,3,4,5}; 

    map<int, int>mp; 
    int count = 0; 

    for(int i=0;i<n;i++){
        if(mp.find(b[i])==mp.end()){
             mp[b[i]]= i ; 
        }
        if(mp.find(target-b[i])!=mp.end() and mp[target-b[i]]!=i){
            cout<<"The target sum can be met"<<endl; 
            cout<<i<< " "<<b[i]<<" "<<target-b[i]<<endl;
            count++;  
        }
    }


    cout<<"the tootal no of count"<<count<<endl; 

    

    return 0 ; 
}