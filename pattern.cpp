#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";



//***All the pattern  based questions solved here */
int main()
{

    int row = 4;
    int col = 5;

    // out put in the below format
    // 00000
    // 00000
    // 00000
    // 00000

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << "0";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "0";
        }
        cout << endl;
    }

    cout << endl;

    int n = 6;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }

    cout << endl;

    int nrow = 13;
    for (char a = 'A'; a <= 'A' + nrow - 1; a++)
    {
        for (char b = 'A'; b <= a; b++)
        {
            cout << a;
        }
        cout << endl;
    }

    cout << endl;
    int i = 1;
    for (char a = 'A'; a <= 'A' + nrow - 1; a++, i++)
    {
        for (char b = a; b <= a + i - 1; b++)
        {
            cout << b;
        }
        cout << endl;
    }

    cout << endl;

    int nfinal = 10;
    int j = 0;
    for (char a = 'A' + nfinal; a >= 'A'; a--, j++)
    {
        for (char b = 'A' + nfinal - j; b <= 'A' + nfinal; b++)
        {
            cout << b;
        }
        cout << endl;
    }

    cout << endl;
    int nnumbers = 6;

    for (int i = 1; i <= nnumbers; i++)
    {
        int t = 1;
        for (int j = 1; j <= nnumbers; j++)
        {
            if (i + j >= nnumbers + 1)
            {
                cout << t;
                t++;
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    cout << endl;
    int nrowanswer = 6;
    for (int i = 1; i <= nrowanswer; i++)
    {
        for (int j = 1; j <= nrowanswer; j++)
        {
            if (i + j - 1 <= nrowanswer)
            {
                cout << nrowanswer - i + 1;
            }
        }
        cout << endl;
    }

    cout << endl;

    int nrowfine = 4;

    for (int i = 1; i <= nrowfine; i++)
    {
        int t = 1;
        int count = 1;
        for (int j = 1; j <= nrowfine; j++)
        {
            if (i + j >= nrowfine + 1)
            {
                cout << nrowfine - j + t;
                t += 2;
                count++;
            }
            else
            {
                cout << " ";
            }
        }
        t = t - 2;
        count--;
        while (t > 1 and count > 1)
        {
            t -= 1;
            count--;
            cout << t;
        }
        cout << endl;
    }


    cout<<endl;
    int nt =  5 ; 

    int x = (nt / 2) + 1;

    // First part

    // till  the first half you just get the 
    for (int i = 0; i < x; i++) {
        for (int j = 1; j <= x - i - 1; j++) {
            cout << ".";
        }
        for (int j = 1; j <= 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Second part
    for (int i = 1; i <= (nt - x); i++) {
        for (int j = 1; j <= i; j++) {
            cout << ".";
        }
        for (int j = 1; j <= nt - (2 * i); j++) {
            cout << "*";
        }
        cout << endl;
    }


  

    cout << endl;
    int Nt = 4 ; 
    int t =0 ; 
    for(int i=0;i<Nt ; i++){

        for(int a=0;a<t;a++){
            cout<<"."; 
        }
        t++;

        for(int j=1;j<=Nt;j++)cout<<"*"; 
        cout<<endl; 
    }


    cout<<endl; 

    long long int Nh = 5 ; 


    for(int i=1;i<=Nh;i++){

        string res= ""; 
        int sum = 0; 
        for(int j=1;j<=i;j++){
            sum+=j;
            res+="+" + to_string(j);
        }
        res+=("=" + to_string(sum)); 
        res.erase(res.begin());

        cout<<res<<endl;  
    }


    cout<<endl ; 

    int Noddsquare = 4 ; 

    for(int i=0 ; i<=Noddsquare ; i++){
        int t = i ; 
        for(int a= 1; a<=Noddsquare ; a++){
            cout<<(2*t+1)%(2*Noddsquare);
            t++;
        }
        cout<<endl ; 
    }



   cout<<endl; 

   int    Starrow= 5 ; 
   int spacecount = Starrow-1; 
   for(int i=1;i<=Starrow; i++){
         for(int j=spacecount-i;j>=0;j--){
            cout<<" "; 
         }
         for(int j=1;j<=2*i-1;j++){

            if(i==0 or i==Starrow){
                cout<<"*"; 
            }
            else{
            if(j==1 or j==2*i-1){
                cout<<"*"; 
            }
            else{
                cout<<" ";
            }
            }
         }
         cout<<endl; 
   }


   cout<<endl; 
   









    cout << endl;
    return 0;
}