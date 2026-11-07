// https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

ll prim(vector<vector<pair<ll, ll>>> &neighboors)
{
    ll cost = 0;

    ll n = neighboors.size();
    vector<bool> reached(n, false);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});

    pair<ll, ll> top = pq.top();

    while (!pq.empty())
    {
        top = pq.top();
        pq.pop();

        if (reached[top.second])
            continue;

        reached[top.second] = true;
        cost += top.first;

        for (auto neigh : neighboors[top.second])
        {
            if (!reached[neigh.first])
                pq.push({neigh.second, neigh.first});
        }
    }

    for (auto node : reached)
        if (!node)
            return -1;

    return cost;
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> neighboors(n, vector<pair<ll, ll>>());

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        neighboors[a].push_back({b, c});
        neighboors[b].push_back({a, c});
    }

    ll cost = prim(neighboors);

    if (cost == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << cost << "\n";

    return 0;
}