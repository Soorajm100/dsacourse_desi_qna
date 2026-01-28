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


struct Node {
    int data; 
    struct Node *left; 
    struct Node *right; 
    Node(int val) {
        data = val; 
        left = NULL; 
        right = NULL; 
    }
};

ll postTraversal(Node* root , ll k ) {
    if(root == NULL) return 0; 

    ll leftpath = postTraversal(root->left , k ); 
    ll rightpath = postTraversal(root->right , k ); 

    ll totalPath = 1 ; 
    ll Vpath = 0 ; 
    ll vglobal = -1e8 ; 

    if(root->left!=NULL){
        if((abs(root->left->data - root->data)==k)){
            totalPath += leftpath; 
        }
    }

     if(root->right!=NULL){
        if((abs(root->right->data - root->data)==k)){
            totalPath = max(totalPath, 1+ rightpath); 
        }
    }

    if( root->right!=NULL and root->left!=NULL){
        if((abs(root->right->data - root->data)==k) and (abs(root->left->data - root->data)==k)){
            Vpath = 1 + leftpath + rightpath; 
            vglobal = max(vglobal , Vpath);

        }
    }

    vglobal = max(vglobal , totalPath);

    return vglobal; 
}

int main(){

    ll k ; 
    cin>>k ; 
    Node* root = new Node(1); 

    // root->left= new Node(2); 
    // root->right = new Node(3); 
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    
    root->left = new Node(2);
    root->right = new Node(2);
 
    root->left->left = new Node(3);
    root->left->right = new Node(5);
 
    root->right->right = new Node(3);

    ll ans = postTraversal(root , k ); 
    
    cout<<ans<<endl; 
    
    return 0; 
}