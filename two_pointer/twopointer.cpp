#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";


int main(){

    vector<int>a={1,1,2,2,3,4,4,5,5,6}; 
    int k = 3 ; 

    unordered_map<int, int>g ; 
    int count= 0; 
    for(int i=0 ,j=0 ; j<a.size();j++){

        g[a[j]] = g[a[j]] + 1; 

        int d = g.size(); 

        if(d > k){
            while(d > k){
                g[a[i]] = g[a[i]]-1 ; 
                if(g[a[i]]==0){
                    g.erase(a[i]); 
                }
                i++; 
                d = g.size(); 
            }
        }

        count+=(j-i+1); 

    }


    cout<<"The total  count of Subarrays include"<<count<<endl; 

    return 0 ; 
}