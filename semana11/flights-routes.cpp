// https://cses.fi/problemset/task/0000

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<ll, ll>>> adj_list(n, vector<pair<ll, ll>>());

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj_list[a].push_back({b, c});
    }

    vector<priority_queue<ll>> dist(n, priority_queue<ll>());
    vector<ll> pop_count(n, 0);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[0].push(0);
    pq.push({0, 0});

    while (!pq.empty())
    {
        ll top = pq.top().second;
        ll weight = pq.top().first;
        pq.pop();

        if (pop_count[top] >= k)
            continue;

        pop_count[top] += 1;

        for (auto adj : adj_list[top])
        {
            if (dist[adj.first].size() < k)
            {
                dist[adj.first].push(weight + adj.second);
                pq.push({weight + adj.second, adj.first});
            }
            else if (dist[adj.first].top() > weight + adj.second)
            {
                dist[adj.first].pop();
                dist[adj.first].push(weight + adj.second);
                pq.push({weight + adj.second, adj.first});
            }
        }
    }

    vector<ll> result;

    for (ll i = 0; i < k; i++)
    {
        result.push_back(dist[n - 1].top());
        dist[n - 1].pop();
    }

    for (ll i = k - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }

    cout << "\n";
}