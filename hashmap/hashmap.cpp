#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";


int main(){

    map<int, int>mp; 

    vector<int>v; 
    int k = 3 ; 
    int n ; 
    cout<<"Enter the n"; 
    cin >> n; 
    int maxFreq = 0, maxFreqEle = 0 , minFreq = 1e8, minFreqEle = 0; 


    for(int i=0;i<n;i++){
        int t; 
        cin>>t;
        v.push_back(t); 
    }

    for(auto x : v){
        mp[x]++; 

        if(maxFreq < mp[x]){
            maxFreq = mp[x]; 
            maxFreqEle = x; 
        }
    }


    for(auto x : mp){
        if(x.second < minFreq){
            minFreq = x.second; 
            minFreqEle = x.first; 
        }

    }

    cout<<"The  max freq count and element "<<maxFreq<<" "<<maxFreqEle<<endl; 
    cout<<"Then min  freq count and element "<<minFreq <<" "<<minFreqEle<<endl; 



    //***check if  there is a distance <=k  elements */

    ///*/**Still  we can reduce the distance without ysing the map<int, vector> */

  //* this is a flawed approach  since you do not consider each  eleemtn seperately i mean they do  have  different index/*/


    map<int, vector<int>>mp3; 

    for(int i=0;i<n;i++){
        mp3[v[i]].push_back(i); 
    }

    cout<<"the elements are"<<endl ;
    bool flag = 0; 
    for(auto x : mp3){
        vector<int> v = x.second ; 

        for(int i=0;i<v.size()-1;i++){
            if(abs(v[i] - v[i+1])<=k){
                cout<<x.first<<" "; 
                 flag = 1;  
                break ;
               
            }
        }
    }

    if(flag==0)cout<<"None"<<endl; 


    /*/*Without using the map<int, vector<int>> */

    cout<<endl; 
    cout<<"from  other way out"<<endl; 
    map<int,int>mp4 ; 

    for(int i=0;i<v.size();i++){

       if(mp4.find(v[i])!=mp4.end()){
           int dist = i- mp[v[i]]; 
           if(abs(dist)<=k){
            cout<<v[i]<<" "; 
           }
       }

       mp4[v[i]] = i;
    }

    


    



    return 0; 
}