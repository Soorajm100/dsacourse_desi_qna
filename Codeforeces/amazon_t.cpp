#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vipair  = vector<pair<ll, ll>>; 

template <class T>
using v = vector<T>;

const int INF_INT = 1e9;
const ll INF_LL = (1LL << 60);
const int MOD = 1000000007;


void solve(){
    
    string s ; 
    cin>>s; 

    ll  count = 0 ; 

    string temp = s; 

    //**for 0 different operations */
    sort(temp.begin() , temp.end()); 

    if(temp==s){
        cout<<0<<endl; 
        return  ; 
    }



    //**for 1 different operations */
    string tempFirst = s ;
    sort(tempFirst.begin() + 1 , tempFirst.end() ); 

    if(tempFirst == temp){
        cout<<1<<endl; 
        return  ; 
    }
    tempFirst = s ;
    sort(tempFirst.begin() , tempFirst.end()-1 ); 
    if(tempFirst == temp){
        cout<<1<<endl; 
        return ; 
    }


    //**for 2 different operations */
    string tempSecond = s; 

    sort(tempSecond.begin() , tempSecond.end() -1 );
    sort(tempSecond.begin()+1 , tempSecond.end()  );
    if(tempSecond == temp){
        cout<<2<<endl; 
        return ; 
    }


    tempSecond = s; 
    sort(tempSecond.begin()+1 , tempSecond.end() );
    sort(tempSecond.begin() , tempSecond.end()-1);
    if(tempSecond == temp){
        cout<<2<<endl; 
        return ; 
    }



    //***for 3 different operations **/

    string tempThird = s;
    sort(tempThird.begin() , tempThird.end() -1 );
    sort(tempThird.begin()+1 , tempThird.end()  );
    sort( tempThird.begin() , tempThird.begin() +2 );
    if(tempThird == temp){
        cout<<3<<endl; 
        return ; 
    }

    tempThird = s;
    sort(tempThird.begin() , tempThird.end() -1 );
    sort(tempThird.begin()+1 , tempThird.end()  );
    sort( tempThird.begin()+s.size()-2 , tempThird.end());
    if(tempThird == temp){
        cout<<3<<endl; 
        return  ; 
    }


    return ; 
}

int main(){


    ll test ; 
    cin>>test ; 
    while(test--){
        solve(); 
    }

}