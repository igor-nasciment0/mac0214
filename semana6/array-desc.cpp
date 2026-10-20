// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> vec;

    for (size_t i = 0; i < n; i++)
    {
        ll l;
        cin >> l;
        vec.push_back(l);
    }

    vector<vector<ll>> num_ways(n, vector<ll>(m + 1));

    for (ll k = 1; k <= m; k++)
    {
        if (vec[0] == k || vec[0] == 0)
        {
            num_ways[0][k] = 1;
        }
        else
        {
            num_ways[0][k] = 0;
        }
    }

    for (ll i = 1; i < n; i++)
    {
        for (ll k = 1; k <= m; k++)
        {
            if(vec[i] != 0 && vec[i] != k)
            {
                num_ways[i][k] = 0;
                continue;
            }

            if(k > 1)
                num_ways[i][k] += num_ways[i - 1][k - 1];
            
            if(k < m)
                num_ways[i][k] += num_ways[i - 1][k + 1];

            num_ways[i][k] += num_ways[i - 1][k];
            num_ways[i][k] %= BIG;
        }
    }

    ll num = 0;

    for (ll k = 1; k <= m; k++)
        num += num_ways[n - 1][k] % BIG;

    cout << num % BIG << "\n";
}