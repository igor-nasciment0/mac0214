// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = pow(10, 9) + 7;

int main()
{
    ll n;
    cin >> n;

    vector<ll> num_ways(n + 1);

    for (int i = 1; i <= min(n, (ll)6); i++)
        num_ways[i] = 1;

    for (ll i = 1; i <= n; i++)
    {
        ll num = 0;

        for (ll k = 1; k <= 6 && k <= i; k++)
            num += num_ways[i - k];

        num_ways[i] += num;
        num_ways[i] %= BIG;
    }

    cout << num_ways[n] << "\n";

    return 0;
}