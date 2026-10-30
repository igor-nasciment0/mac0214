// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    ll t;
    cin >> t;

    ll row = 1;
    vector<vector<ll>> dp(1e6, vector<ll>(2, -1));
    dp[0][0] = 1; // joined
    dp[0][1] = 1; // divided

    while (t--)
    {
        ll n;
        cin >> n;

        if(dp[n-1][0] != -1)
        {
            cout << (dp[n - 1][0] + dp[n - 1][1]) % BIG << "\n";
            continue;
        }

        for (; row < n; row++)
        {
            dp[row][0] = (dp[row - 1][0] * 2 + dp[row - 1][1]) % BIG;
            dp[row][1] = (dp[row - 1][0] + dp[row - 1][1] * 4) % BIG;
        }

        cout << (dp[n - 1][0] + dp[n - 1][1]) % BIG << "\n";
    }

    return 0;
}