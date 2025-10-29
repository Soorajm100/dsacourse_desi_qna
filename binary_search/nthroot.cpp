#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T>
using v = vector<T>;

const int INF_INT = 1e9;
const ll INF_LL = (1LL << 60);
const int MOD = 1000000007;

double CalculateBinomialPower(double base, int n, double m)
{
    double val = 1.00;

    /**Binomial  exponentition */
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            val = val * base;
            n = n - 1;
        }
        else
        {
            base = base * base;
            n = n / 2;
        }
    }

    return val;
}

int main()
{

    double start = 1.00;
    double end = 1e8;

    double m = 50.00;
    int n = 2;

    while (end - start > 1e-8)
    {
        double mid = ((start + end) * 1.00) / (2 * 1.00);

        /**Finding the power by using the normal  O(N) approach */
        // double val = 1.0000;
        // for(ll i = 0; i < n; i++){
        //     val = val * mid;
        // }

        /**Finding the power by using the normal  O(logN) approach */
        double val = CalculateBinomialPower(mid, n, m);

        if (abs(val - m) <= 1e-6)
        {
            cout << "the nth root of m is " << mid << endl;
            break;
        }
        else if (val > m)
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }
    return 0;
}
