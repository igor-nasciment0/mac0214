// https://cses.fi/problemset/task/0000

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    ll log_n = __bit_width(n);

    vector<pair<ll, ll>> queries;
    vector<vector<ll>> parent(n, vector<ll>(log_n, -1));

    for (ll i = 1; i <= n - 1; i++)
    {
        ll a;
        cin >> a;
        a--;
        parent[i][0] = a;
    }

    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        queries.push_back({a, b});
    }

    for (ll i = 1; i < log_n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll intermediate = parent[j][i - 1] == -1 ? 0 : parent[j][i - 1];
            parent[j][i] = parent[intermediate][i - 1];
        }
    }

    for (auto query : queries)
    {
        ll x = query.first, k = query.second;
        ll p = x;

        for (ll i = __bit_width(k) - 1; i >= 0; i--)
        {
            if (k - (1 << i) < 0)
                continue;

            p = parent[p][i];

            if (p == -1)
                break;

            k -= (1 << i);
        }

        if (p != -1)
            cout << p + 1 << "\n";
        else
            cout << p << "\n";
    }
}