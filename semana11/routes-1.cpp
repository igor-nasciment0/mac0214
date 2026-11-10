// https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj_list(n, vector<pair<ll, ll>>());

    vector<ll> distance(n, LLONG_MAX);
    vector<bool> processed(n, false);
    distance[0] = 0;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj_list[a].push_back({b, c});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        pair<ll, ll> top = pq.top();
        pq.pop();

        if (processed[top.second])
            continue;

        processed[top.second] = true;

        for (auto  adj : adj_list[top.second])
        {
            if (distance[top.second] + adj.second < distance[adj.first])
            {
                distance[adj.first] = distance[top.second] + adj.second;
                pq.push({distance[adj.first], adj.first});
            }
        }
    }

    for (ll i = 0; i < n; i++)
        cout << distance[i] << " ";

    cout << "\n";
}