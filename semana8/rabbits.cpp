// https://atcoder.jp/contests/dp/tasks/dp_u?lang=en

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<ll>> comp(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> comp[i][j];

    vector<ll> cost(1 << n, 0);
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        for (ll i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                for (ll j = i + 1; j < n; j++)
                {
                    if (mask & (1 << j))
                        cost[mask] += comp[i][j];
                }
            }
        }
    }

    vector<ll> dp(1 << n, 0);
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        for (ll submask = mask; submask > 0; submask = (submask - 1) & mask)
        {
            dp[mask] = max(dp[mask], cost[submask] + dp[mask ^ submask]);
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}