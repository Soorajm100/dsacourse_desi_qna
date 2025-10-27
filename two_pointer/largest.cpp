#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

int main(){

    vector<int>a ={1,2,3,4,5,6,7,8};
    int k = 10 ; 
    int n = a.size() ; 
    int count = 0 ; 
    int sum =  0 ; 
    int maxLen = -1e8 ; 
    for(int i=0 , j=0 ; j<n;j++){
        sum = sum + a[j] ; 
        if(sum > k){
            while(sum > k ){
                sum = sum  - a[i] ; 
                i++; 
            }
        }

        maxLen = max(maxLen , j-i+1) ; 
        
    }

    cout<<"The largest  subarray  length whose sum <= k "<<maxLen<<endl; 


    return 0 ; 
}