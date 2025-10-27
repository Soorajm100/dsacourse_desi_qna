#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

int main(){

    string a = "dgzdgabbab"; 
    int k = 2 ; 
    int n = a.size() ; 
    int count = 0 ; 
    int sum =  0 ; 
    int maxLen = -1e8 ; 
    multiset<char>s; 
    for(int i=0 , j=0 ; j<n;j++){
        s.insert(a[j]) ; 
        int diff = *s.rbegin() - *s.begin() ; 
        if(diff > k){
            while(diff > k ){
                 
                s.erase(s.find(a[i])); 
                i++; 
                diff = *s.rbegin() - *s.begin() ;
               
            }
        }
        maxLen = max(maxLen , j-i+1) ; 
        
    }

    cout<<"The largest length of substring whose  any pair of characters have diff <=k "<<maxLen<<endl; 


    return 0 ; 
}