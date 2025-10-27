#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

int main(){
    vector<int>a={1,2,3,4,5,6,79,8}; 

    int player1 = 0 ; 
    int player2 = 0 ; 
    bool  reversed = false ; 

    int start = 0; 
    int end = a.size()-1 ; 
    int turn = 0; 
    int selected  =0 ; 

    while(start < end){

        if(turn%2==0){
            if(reversed==false){
                p1+= a[start]; 
                selected = a[start] ; 
                start++; 
            }
            else{

                p1+=a[end]; 
                selected=a[end]; 
                end--; 

            }

        }
        else{
             if(reversed==false){
                p2+= a[start]; 
                selected = a[start] ; 
                start++; 
            }
            else{

                p2+=a[end]; 
                selected=a[end]; 
                end--; 
            }

        }
        if(selected%2==0){
            reversed=!reversed; 
        }
        turn++; 
    }



    return 0 ; 
}