#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";


int main(){

    string a , b; 
    cin>>a>>b;

    map<int, int>mp1,mp2 ; 
    bool flag = false ;

    for(auto x : a)mp1[x]++; 
    for(auto x : b)mp2[x]++; 

    for(char ch='a'; ch<='z';ch++){
        if(mp1[ch]!=mp2[ch]){
            flag = true ;
            break; 
        }
    }

    if(flag ==true){
        cout<<"Not an  Anagram"<<endl; 

    }
    else{
        cout<<"Its an  Anagram"<<endl; 
    }


    return 0; 
}