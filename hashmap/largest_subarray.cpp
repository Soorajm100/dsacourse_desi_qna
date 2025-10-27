#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

/**Covers both largest  subarray  length and smallest Subarray length */
int main(){
    vector<int>a={3,0,1,3,-2,2}; 
    map<int, int>mp; 
    int n =a.size(); 
    int ps = 0; 
    int k = 4 ;
    int maxLength = -1e8;  
    mp[0] = 1;
    pair<int, int> minPair,maxPair ; 
    map<int, int>mp2; 
    int minLength= 1e8 ; 
    for(int j=0;j<n;j++){
        ps+=a[j];
        int x = ps-k; 
        if (mp.find(x) != mp.end()) {
            int i = mp[x] + 1;
            int curLength = j - i + 1;
            if (curLength > maxLength) {
                maxLength = curLength;
                maxPair = {j+1, i+1}; 
            }
        }
 
        if (mp2.find(x) != mp2.end()) {
            int i = mp2[x] + 1;
            int curLength = j - i + 1;
            if (curLength < minLength) {
                minLength = curLength;
                minPair = {j+1, i+1}; 
            }
        }
        if(mp.find(ps)==mp.end()){
            mp[ps] = j ; 
        }
        mp2[ps] = j ; 
    }

    cout<<"The largest subarray  length "<<maxLength<<endl; 
    cout<<"The smallest subarray  length "<<minLength<<endl; 
    cout<<"the minPair "<<minPair.first<<" "<<minPair.second<<endl;
    cout<<"the maxPair "<<maxPair.first<<" "<<maxPair.second<<endl;
    return 0; 
}