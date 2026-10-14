// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
ll min_coins(ll x, vector<ll> &coins);

ll *min_coins_memo;

int main()
{
    ll n, x;
    cin >> n;
    cin >> x;

    min_coins_memo = (ll *)calloc(x + 1, sizeof(ll));
    vector<ll> coins(n);

    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        coins[i] = a;
    }

    ll min = min_coins(x, coins);
    min = min == LONG_LONG_MAX - 1 ? -1 : min;

    cout << min << "\n";

    free(min_coins_memo);
    return 0;
}

ll min_coins(ll x, vector<ll> &coins)
{
    if (x < 0)
        return LONG_LONG_MAX - 1;

    if (x == 0)
        return 0;

    if (min_coins_memo[x] != 0)
        return min_coins_memo[x];

    ll min = LONG_LONG_MAX - 1;

    for (auto coin : coins)
    {
        ll candidate = min_coins(x - coin, coins) + 1;

        if (candidate < min)
            min = candidate;
    }

    min_coins_memo[x] = min;
    return min;
}