// https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main()
{
    ll n, t;

    cin >> n >> t;

    vector<ll> machines;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        machines.push_back(a);
    }

    ll biggest_time = machines[0];

    for (auto m : machines)
        if (m > biggest_time)
            biggest_time = m;

    ll l = 0;                // lowest time "possible"
    ll r = biggest_time * t; // biggest time possible

    ll needed = 0;

    while (l < r - 1)
    {
        ll mid_time = (l + r) / 2;

        ll num_products = 0;

        for (ll i = 0; i < (ll)machines.size(); i++)
            num_products += (mid_time / machines[i]);

        if (num_products >= t)
            r = mid_time;
        else
            l = mid_time;
    }

    needed = r;

    cout << needed << "\n";
}