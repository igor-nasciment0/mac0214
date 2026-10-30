#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> h(n);
    vector<ll> s(n);

    for (ll i = 0; i < n; i++)
        cin >> h[i];

    for (ll i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<ll>> dp(n, vector<ll>(2));

    for (ll i = 0; i <= n; i++)
    {
        for (ll Y = 0; Y <= x; Y++)
        {
            if (i == 0 || Y == 0)
                dp[i][Y] = 0;
            else
            {
                if((Y - h[i - 1] < 0) || (dp[i - 1][Y] > dp[i - 1][Y - h[i - 1]] + s[i - 1]))
                    dp[i][Y] = dp[i - 1][Y];
                else
                    dp[i][Y] = dp[i - 1][Y - h[i - 1]] + s[i - 1];
            }
        }
    }

    cout << dp[n - 1][x];
}