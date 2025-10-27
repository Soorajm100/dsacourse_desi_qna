// File: binary_search_google.cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

/**1 1 1 1 2 2  */
ll ApplyBinarySearchRight(const vi &a, ll start, ll end, ll k, ll j)
{
    ll ans = -1;
    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (a[mid] + a[j] > k)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

ll ApplyBinarySearchLeft(const vi &a, ll start, ll end, ll k, ll j)
{
    ll ans = -1;
    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (a[mid] + a[j] > k)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi a = {1, 1, 1, 1, 2, 2};
    ll k1 = 1;
    ll k2 = 3;
    ll n = a.size();
    ll count = 0;

    vi suffixArray(n, 0);
    vi suffixFinal(n, 0);

    /**O(NLogn) */
    for (int k = n - 1; k >= 0; k--)
    {
        int start = k;
        int end = n - 1;
        ll index = ApplyBinarySearchRight(a, start, end, k2, k);
        if (index == -1)
        {
            suffixArray[k] = 0;
        }
        else
        {
            suffixArray[k] = index - k;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffixFinal[i] = suffixFinal[i + 1] + suffixArray[i];
    }

    for (ll j = 1; j <= n - 3; j++)
    {
        //**   Approach is to find the index from  the left for the current index j  where the condition *
        /*   for the right ppart of it the same logic holds and sum  it up and multiply.
         */

        ll start = 0;
        ll end = j - 1;
        ll index = ApplyBinarySearchLeft(a, start, end, k1, j);
        ll count1 = j - index;
        if (index == -1)
        {
            count1 = 0;
        }

        ll count2 = suffixFinal[j + 1];

        /***
         * For the right part same logic through  the binary  search
         */

        count += (count1 * count2);
    }

    cout << "The final count of the subarray in  O(NlogN) " << count << endl;

    return 0;
}
