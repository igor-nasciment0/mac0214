// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n;
    cin >> m;

    multiset<int> prices;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        prices.insert(a);
    }


    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;

        set<int>::iterator max = prices.upper_bound(a);

        if (max == prices.begin() && max == prices.end())
        {
            cout << "-1\n";
            continue;
        }        

        if(max == prices.end())
            max--;

        while (*max > a && max != prices.begin())
            max--;

        if(max == prices.begin() && *max > a)
        {
            cout << "-1" << "\n";
            continue;
        }

        cout << *max << "\n";
        prices.erase(max);
    }
}