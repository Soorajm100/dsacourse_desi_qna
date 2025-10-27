#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

int main(){
    vector<int>a={1,2,3,4,5,6};
 
    int k1 = 1 ; 
    int k2 = 3 ; 

    //**see first loop  for the partition  bambooo */
    /*2 LOOPS  for the two pointer approach */
    /*The time complexity  should come as O(N*N)*/
    int n = a.size(); 
    ll  count = 0 ; 
    for(int j=1;j<=n-3; j++){
      
        /**Keep the one pointer  and do not count the 
         * repetitive patterns
         * Simple logic at the end  unique*repititve  = unique ; 
         * sequence generated. 
         * The first part of the loop  always generate  unique sequence or pair 
         * combined with  even  the later part generates the duplicate sequence the first  part is unique 
         * so  as a whole the sequence is unique.
         */

        ll  i = j-1 ; 
        ll count1  = 0; 
    
       while(i>=0){
        if(a[i] + a[j] > k1){
               count1++; 
        }
         i--; 
        }
       
        /**After the partition */

        ll h = j+1 , o= n-1 ; 
        ll  count2 = 0; 
         while(h<o){
        if(a[h] + a[o] > k2){
                count2+=(o-h); 
                o--; 
         
        }
        else{
            h++; 
         }
        }
        count+=(count1*count2) ; 

    }

    cout<<"The final count of the subarray in O(N^2) "<<count<<endl; 


    return 0; 
}