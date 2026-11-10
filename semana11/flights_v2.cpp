// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n);
    
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    vector<vector<ll>> dist(n, vector<ll>(2, LLONG_MAX));
    dist[0][0] = 0;

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        ll d = top.first;
        ll u = top.second.first;
        ll used = top.second.second;

        if (d > dist[u][used])
            continue;

        for (auto edge : adj[u])
        {
            ll v = edge.first;
            ll w = edge.second;

            if (dist[v][used] > d + w)
            {
                dist[v][used] = d + w;
                pq.push({dist[v][used], {v, used}});
            }

            if (used == 0 && dist[v][1] > d + w / 2)
            {
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], {v, 1}});
            }
        }
    }

    cout << dist[n - 1][1] << "\n";
}