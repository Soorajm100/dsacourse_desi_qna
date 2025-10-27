#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

int main(){

    int target = 0 ; 
    vector<int>b = {7 ,7,7,2,4,1}; 
    map<int,int>mp;
    int count = 0; 
    int n = b.size(); 
    for(int i=0;i<n;i++){
     int sum = target + b[i]; 

     if(mp.find(sum)!=mp.end()){
        count+=mp[sum] ; 
     }

     mp[b[i]]++ ; 
    }

    cout<<"the total nnumber of pairs with  condition  given "<<count<<endl; 




    return 0 ; 
}