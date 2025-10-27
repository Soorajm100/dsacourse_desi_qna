#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n";

template <class X>

void swapy(X &a, X &b)
{
    X temp;
    temp = a;
    a = b;
    b = temp;

    cout << "The swapped elements a and b respectively are :" << a << " " << b << endl;
}

int main()
{

    // template main  concept
    int a = 10, b = 20;

    swapy(a, b);

    // string main concept

    string aty = "geeksforgeeks";
    cout << aty.substr(0, 2) << " " << aty.substr(2) << endl;

    // pair main  concept

    pair<int, int> pt;

    pt.first = 1;
    pt.second = 10;

    cout << pt.first << " " << pt.second << endl;

    pt = make_pair(2, 6);

    cout << "after changing the values are" << pt.first << " " << pt.second << endl;

    map<char, int> mp;
    map<char, int> mp1;

    mp['a'] = 20;
    mp['b'] = 30;

    // erase the key  value pair of the map;
    mp.erase('b');
    for (auto x : mp)
        cout << x.first << ' ' << x.second << endl;

    // swap  the elements of the two mapsll

    mp1['b'] = 30;

    mp1.swap(mp);

    cout << endl;
    cout << "the contents of the map" << endl;
    for (auto x : mp)
        cout << x.first << " " << x.second << endl;

    cout << endl;
    cout << "the contents of the map2" << endl;
    for (auto x : mp1)
        cout << x.first << " " << x.second << endl;

    cout << "The number of elements with  count a " << mp1.count('a') << " " << endl;
    cout << "The number of elements with  count b " << mp.count('b') << " " << endl;

    /// usage of stacks.

    stack<int> st;

    vector<int> at = {1, 2, 3, 4, 5, 6};

    for (auto x : at)
        st.push(x);

    while (!st.empty())
    {
        int ele = st.top();
        cout << ele << " ";

        st.pop();
    }

    cout << endl;
    queue<int> q;
    for (auto x : at)
        q.push(x);

    cout << "Contents from  queue" << endl;

    while (!q.empty())
    {
        int ele = q.front();
        cout << ele << " ";
        q.pop();
    }

    cout << endl;

    priority_queue<int> pq;
    vector<int> ty = {5, 4, 6, 1, 2, 30};
    for (auto x : ty)
        pq.push(x);

    cout << "the contents of priority_queue 1 max heap" << endl;
    while (!pq.empty())
    {
        int ele = pq.top();
        cout << ele << " ";

        pq.pop();
    }

    cout << endl;

    priority_queue<int, vector<int>, greater<int>> pq1;

    for (auto x : ty)
        pq1.push(x);

    cout << "the contents of priority_queue 2 min heap" << endl;
    while (!pq1.empty())
    {
        int ele = pq1.top();
        cout << ele << " ";

        pq1.pop();
    }

    



    return 0;
}
