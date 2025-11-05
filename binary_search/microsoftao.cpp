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

vi getExtraStock(vi composition, vi stock)
{
    vi extraStock;
    int n = composition.size();
    for (int i = 0; i < n; i++)
    {
        if (composition[i] > stock[i])
        {
            extraStock.push_back(composition[i] - stock[i]);
        }
        else
        {
            extraStock.push_back(0);
        }
    }
    return extraStock;
}

vi getNewComposition(vi composition, ll mid)
{
    vi newComposition;
    int n = composition.size();
    for (int i = 0; i < n; i++)
    {
        newComposition.push_back(composition[i] * mid);
    }
    return newComposition;
}

int main()
{

    ll start = 0;
    ll end = 1e9;
    ll budget = 3;
    vi cost = {1, 1};
    vi composition = {1, 2};
    vi stock = {0, 1};
    ll ans = - 1; 

    /*O(logN)*/
    while (start <= end)
    {
        ll mid = (start + end) / 2;

        ll totalCost = 0;

        //*O(N)/
        vi newComposition = getNewComposition(composition, mid);
        vi extra = getExtraStock(newComposition, stock);

        for (int i = 0; i < extra.size(); i++)
        {
            totalCost += extra[i] * cost[i];
        }

       

        if (totalCost <= budget)
        {
            ans = mid; 
            start = mid+1;
        }
        else if (totalCost > budget)
        {
            end = mid-1;
        }
    }

    cout << "The maximum number of cakes that can be made is: " << ans << endl;

    return 0;
}