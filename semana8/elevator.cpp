// https://cses.fi/problemset/task/1653

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

/*
    seja r(S) a quantidade mínima de viagens,
    e l(S) o peso da última viagem mínima para o conjunto S de pessoas.

    seja add(r(S), l(S), p) = {
        (r(S) + 1, weight(p)),            se l(S) + weight(p) > x
        (r(S), l(S) + weight(p)),    otherwise
    }

    então

    (r(S), l(S)) = min_{p \in S} add (r(S - p), l(S - p), p)
*/

pair<ll, ll> add(ll rides, ll last, ll weight_p, ll max_w)
{
    if (last + weight_p > max_w)
        return {rides + 1, weight_p};
    else
        return {rides, last + weight_p};
}

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> weight(n);

    for (ll i = 0; i < n; i++)
        cin >> weight[i];

    vector<pair<ll, ll>> dp(1 << n); // rides(s), last(s)

    dp[0] = {1, 0};

    for (ll s = 1; s < dp.size(); s++)
    {
        pair<ll, ll> min_option = {LLONG_MAX, LLONG_MAX};

        for (ll p = 0; p < n; p++)
        {
            if (!(s & (1 << p)))
                continue; // tentamos apenas pessoas que estão em s

            ll s_p = s ^ (1 << p);

            auto option = add(dp[s_p].first, dp[s_p].second, weight[p], x);

            if (option < min_option)
                min_option = option;
        }

        dp[s] = min_option;
    }

    cout << dp[(1 << n) - 1].first << "\n";
}