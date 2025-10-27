#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";


int RevereseNumber(int num){
    int reverse = 0; 
    while(num > 0){
        int lastDigit = num%10 ; 
        num = num/10; 
        reverse = reverse*10 + lastDigit ;    
    }
    return reverse; 
}

int main(){

    vector<int>arr; 

    arr.push_back(5); 
    arr.push_back(1); 
    for(auto  it=arr.begin() ; it!=arr.end() ; it++){
        cout<<*it<<" "; 
    }
    cout<<endl; 

    arr.pop_back(); 
     for(auto  it=arr.begin() ; it!=arr.end() ; it++){
        cout<<*it<<" "; 
    }
    cout<<endl; 
    arr.push_back(10); 
    for(auto  it=arr.begin(); it!=arr.end(); it++){
        cout<<*it<<" "; 
    }
    cout<<endl; 

    sort(arr.begin() , arr.end()); 

    for(auto it=arr.begin(); it!=arr.end(); it++){
        cout<<*it<<" "; 
    }
    cout<<endl; 

    sort(arr.begin() , arr.end() , greater<int>()); 

    for(auto it=arr.begin(); it!=arr.end(); it++){
        cout<<*it<<" ";  
    }

    cout<<endl; 


    vector<int>arr1 = {2,3,6,9,8,7,4,6};

    sort(arr1.begin() , arr1.end()); 

    //**Sum of the even and odd numbers */
    int evensum = 0; 
    int oddsum = 0; 
    for(auto x : arr1){
        if(x%2==0){
            evensum+=x; 
        }
        else{
            oddsum+=x; 
        }
    }
    cout<<"evensum : "<<evensum<<endl; 
    cout<<"oddsum : "<<oddsum<<endl; 


    //***Sum  of the even  and odd indicces */
    int oddindsum = 0; 
    int evenindsum = 0; 
    for(int i=0;i<arr1.size();i++){
        if(i%2){
            oddindsum+=arr1[i]; 
        }
        else{
            evenindsum+=arr1[i]; 
        }
    }

    cout<<"odd ind sum : "<<oddindsum<<endl ; 
    cout<<"even  ind sum : "<<evenindsum<<endl; 

   //***Sum of the pairs in  same array  */
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr1.size();j++){
            if(i!=j)cout<<" sum  : "<<arr1[i] + arr1[j]<<endl 
        }
    }

    //**Maximum  pair sum  of the arrays */

    /**O(N) solutions */
    int max1 = -1e8 ; 
    int max2 = -1e8 ; 
    for(int i=0;i<arr1.size();i++){
        if(max1 < arr1[i]){
            max2 = max1 ; 
            max1 = arr1[i] ; 
        }
    }

    cout<<"The sum  max sum pairs : " <<max1 + max2 <<endl ;


    int Lrange = 25 ; 
    int Mrange = 21;
    int count_prime = 0; 


    for(int i=Mrange ; i<=Lrange;i++){
        int count = 0; 
        for(int j=1 ;j<=i;j++){
            if(i%j==0)count++; 
        }

        if(count==2){
            count_prime++; 
            cout<<i << " : is  a prime number"<<endl ;
        }
    }

    cout<<"the count of prime numbers is : "<<count_prime<<endl; 



    int sum_number= 0; 
    for(int i=Mrange; i<=Lrange;i++){
        int revnumber = RevereseNumber(i); 
        sum_number+=revnumber ; 
    }

    cout<<"The reverse numbr sum is " <<sum_number<<endl ; 


    //***Triplet  sum  */

    cout<<endl; 

    for(int i=0;i<arr1.size()-2;i++){
        for(int j=i+1; j<arr1.size()-1;j++){
            for(int k=j+1;k<arr1.size();k++){
                cout<<"The triplet sum  is : "<<arr1[i] + arr1[j] + arr1[k]<<endl; 
            }
        }
    }

    int eventtriplet = 0; 
    int oddtriplet = 0; 
    for(int i=0;i<arr1.size()-2;i++){
        for(int j=i+1; j<arr1.size()-1;j++){
            for(int k=j+1;k<arr1.size();k++){
                int triplet_sum = arr1[i] + arr1[j] + arr1[k];

                if(triplet_sum%2==0){
                    eventtriplet++; 
                }
                else{
                    oddtriplet++; 
                }
            }
        }
    }

    cout<<"even  sum  triplet "<<eventtriplet<<endl; 
    cout<<"Odd sum triplet "<<oddtriplet<<endl; 



/*To  get the last and ffirst index in  one loop itself*/
    vector<int>sample_array ={1,2,5,7,8,8};
    int target = 8 ; 


    bool firsttime_encountered = false; 
    int n = sample_array.size(); 
    int first_index = -1 ; 
    int last_index =  - 1 ; 

    for(int i=0;i<sample_array.size();i++){
        if(sample_array[i]==target and firsttime_encountered){
            last_index = i ; 
          
        }
        if(sample_array[i]==target and !firsttime_encountered){
            firsttime_encountered= true; 
            first_index = i ; 
        }
    }

    cout<<"the first index" <<first_index<<endl; 
    cout<<"the last index" <<last_index<<endl;


    //**Single loop  approach */
    vector<int>arrayt={2,3,4,2,5,6,6,6,5};
    int max_ele = *max_element(arrayt.begin() , arrayt.end()); 
    vector<int>freq(max_ele+1, 0) ;
    vector<bool>vis(max_ele, 0) ; 
    int distint_ele_count= 0 ; 
    for(auto x : arrayt){
        freq[x]++; 

        if(!vis[x]){
            distint_ele_count++; 
        }
         vis[x] = true; 
    } 
    vis.assign(max_ele, false); 
    for(auto x : arrayt){
        if(!vis[x])cout<<"the frequency  of "<<x<<" is "<<freq[x]<<endl; 
        vis[x] = true; 
    }

    cout<<"the distinct element count is " <<distint_ele_count<<endl; 


    int arrNew[4][4] = {{1,2,3,4},{5,6,7,8},{4,8,9,8}};
    int row = sizeof(arrNew)/sizeof(arrNew[0]);
    int col = sizeof(arrNew[0])/sizeof(arrNew[0][0]); 

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arrNew[i][j]<<" "; 
        }
        cout<<endl ; 
    }


    //**Diagonal  of a matrix print the elements */

    cout<<"the right diagonal"<<endl ; 
    for(int i=0 ; i<row ;i++){
        for(int j=0;j<col ;j++){
            if(i+j==row-1 and i!=j){
                cout<<arrNew[i][j]<<" "; 
            }
        }
    }
   cout<<endl; 
    cout<<"the left  diagonal"<<endl ; 
    for(int i=0;i<row;i++){
        for(int j=0;j<col ; j++){
            if(i==j){
                cout<<arrNew[i][j]<<" "; 
            }
        }
    }
    cout<<endl;

    int Newrow = row;
     int Newcol = col ; 
     int startrow = 0; 
     int startcol = 0 ; 
     int endrow = row-1 ; 
     int endcol =col-1; 




    /**Going in  a pattern  */

    while(startcol < endcol and startrow < endcol){

        for(int j=startcol ; j<=endcol; j++){
            cout<<arrNew[startrow][j]<<" "; 
        }
    

       for(int j=startrow+1; j<=endrow;j++ ){
            cout<<arrNew[j][endcol]<<" ";  
       }

       for(int j=endcol-1; j>=startcol;j--){
            cout<<arrNew[endrow][j]<<" "; 
       }

       for(int j=endrow-1; j>=startrow+1;j--){
            cout<<arrNew[j][startcol]<<" "; 
       }

       startrow++; 
       startcol++; 
       endcol--; 
       endrow--; 
    }


   int arrty[3][3]={{1,2,3},{4,5,6},{7,8,9}};

   cout<<endl;
   for(int i=0;i<3; i++){
    if(i%2==0){
        for(int j=0 ; j<3 ; j++){
            cout<<arrty[i][j]<<" "; 
        }
        cout<<endl; 
    }
    else{
         for(int j=2 ; j>=0 ; j--){
            cout<<arrty[i][j]<<" "; 
        }
         cout<<endl; 
    }
   }

   /*Z pattern */
     int zarrty[3][3]={{1,2,3},{4,5,6},{7,8,9}};
     int zrow = sizeof(zarrty)/sizeof(zarrty[0]); 
     int zcol = sizeof(zarrty[0])/sizeof(zarrty[0][0]); 

     cout<<endl; 

   for(int i=0;i<zcol;i++){
       cout<<zarrty[0][i]<<" "; 
   }

   for(int i=0;i<zrow;i++){
    for(int j=0;j<zcol ;j++){
        if(i+j==zcol-1 and (i!=0 and i!=zrow-1)){
            cout<<zarrty[i][j]<<" "; 
        }
    }
   }

    for(int i=0;i<zcol;i++){
       cout<<zarrty[zrow-1][i]<<" ";
   }

   cout<<endl;


   //**Transpose of a matrix */

   /**
    * 
    *  1 2 3        1 4 7 
    *  4 5 6   - >  2 5 8 
    *               3 6 9 
    *  7 8 9 
    */

    int zfine[3][3]={{1,2,3},{4,5,6},{7,8,9}};
     int zrowt = sizeof(zfine)/sizeof(zfine[0]); 
     int zcolt = sizeof(zfine[0])/sizeof(zfine[0][0]); 


   for(int i=0;i<zrowt;i++){
    for(int j=i+1 ; j<zrowt;j++){
        swap(zfine[i][j] , zfine[j][i]); 
    }
   }

   for(int i=0;i<zrowt;i++){
    for(int j=0;j<zcolt;j++){
        cout<<zfine[i][j]<<" "; 
    }
    cout<<endl;
   }



   



   




































    return 0; 
}