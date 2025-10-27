#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

int main(){

    vector<int>a ={1,2,3,4,5};
    sort(a.begin() , a.end());  
    int k = 2 ; 
    int n = a.size() ; 
    int count = 0 ; 
    for(int i=0 , j=0 ; j<n;j++){
        int sum = a[j] - a[i] ; 

        if(sum  > k ){
            while(sum  > k ){
                i++ ; 
                sum  = a[j] - a[i] ; 
            }
        }
        
        count += (j-i+1);
    }

    cout<<"The count of the pairs whose sum <= k "<<count<<endl; 


    return 0 ; 
}