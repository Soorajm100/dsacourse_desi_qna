// File: binary_search_google.cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi a = {1, 2,3,4,5,6};
    ll k1 = 1;
    ll k2 = 3;
    ll n = a.size();
    ll count = 0;

    vi preCount(n, 0);
    vi SufCount(n, 0);

    for (int i = 1; i < a.size(); i++)
    {
        ll j = i - 1;
        ll count1 = 0;
        while (j >= 0)
        {
            if (a[i] + a[j] > k1)
            {
                count1++;
            }
            j--;
        }

        preCount[i] = count1;
    }

    ll j = 0; // start  from  the left  to  precalculate the right count
    for (ll i = 0; i < n - 1; i++)
    {
        if (j <= i or j>=n)
            j = i + 1; 
      
        while (i<j and j <n && a[i] + a[j] <= k2)
        {
            j++; 
        }


        if (j < n)
            SufCount[i] = n - j;
        else
            SufCount[i] = 0;
    }

    SufCount[n - 1] = 0; 

    vi Suffinal(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        Suffinal[i] = Suffinal[i + 1] + SufCount[i];
    }

    for (auto x : SufCount)
        cout << x << " ";

    for (ll i = 0; i < n - 1; i++)
    {

        count += (preCount[i] * Suffinal[i + 1]);
    }

    cout << "The final  count is : " << count << endl;

    return 0;
}