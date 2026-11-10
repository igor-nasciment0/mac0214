// https://cses.fi/problemset/task/1195

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

// dijkstra here was not a good idea

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj_list(n, vector<pair<ll, ll>>());

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj_list[a].push_back({b, c});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> processed(n, false);

    vector<ll> price(n, LLONG_MAX);
    vector<ll> max_price(n, LLONG_MAX + 1); // -infinity
    vector<ll> without_disc(n, 0);

    price[0] = 0;
    max_price[0] = 0;

    pq.push({0, 0});

    while (!pq.empty())
    {
        ll top = pq.top().second;
        pq.pop();

        if (processed[top])
            continue;

        processed[top] = true;

        for (auto adj : adj_list[top])
        {
            ll mp = max(max_price[top], adj.second);
            ll discount = mp % 2 == 0 ? mp / 2 : mp / 2 + 1;

            ll p = without_disc[top] + adj.second - discount;

            if (price[adj.first] > p)
            {
                price[adj.first] = p;
                without_disc[adj.first] = p + discount;
                max_price[adj.first] = mp;

                pq.push({price[adj.first], adj.first});
            }
        }
    }

    cout << price[n - 1] << "\n";
}