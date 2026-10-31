// https://cses.fi/problemset/task/1093

#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

/*
    let dp[i][x] be the number of subsets of {1, 2, ..., i} with sum x

    then

    dp[i][x] = dp[i - 1][x] + dp[i - 1][x - i]

    base: dp[1][1] = 1
*/

const ll big = 1e9 + 7;
const ll INV2 = 500000004; // modular inverse of 2 modulo 1e9+7

int main()
{
    ll n;
    cin >> n;

    ll S = n * (n + 1) / 2;

    if (S % 2 == 1)
    {
        cout << 0 << "\n";
        return 0;
    }

    ll target = S / 2;

    vector<vector<ll>> dp(n + 1, vector<ll>(target + 1));

    for (ll i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll t = 1; t <= target; t++)
        {
            if (t >= i)
                dp[i][t] = dp[i - 1][t] + dp[i - 1][t - i];
            else
                dp[i][t] = dp[i - 1][t];

            dp[i][t] = dp[i][t] % big;
        }
    }

    cout << dp[n][target] * INV2 % big << "\n";
}