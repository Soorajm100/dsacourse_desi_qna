#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
const int MOD = 1000000007;

ll factorial[MAXN + 1], inversefact[MAXN + 1];

// Function to compute (base^exp) % MOD using Binary Exponentiation
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute Factorial and Inverse Factorial
void precompute() {
    factorial[0] = inversefact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    inversefact[MAXN] = power(factorial[MAXN], MOD - 2, MOD); // Fermat's theorem
    for (int i = MAXN - 1; i >= 1; i--) {
        inversefact[i] = (inversefact[i + 1] * (i + 1)) % MOD;
    }
}

// Compute nCr % MOD
ll nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (factorial[n] * inversefact[r] % MOD) * inversefact[n - r] % MOD;
}


int main() {
    precompute();
    int t, n, r;
    cin >> t;
    while (t--) {
        cin >> n >> r;
        cout << nCr(n, r) << endl;
    }
    return 0;
}
