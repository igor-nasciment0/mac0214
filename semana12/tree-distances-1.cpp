// https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

pair<ll, ll> find_deepest(ll node, ll parent, vector<vector<ll>> &adj_list)
{
    pair<ll, ll> deepest = {node, 0};

    for (auto adj : adj_list[node])
    {
        if (adj == parent)
            continue;

        pair<ll, ll> deep = find_deepest(adj, node, adj_list);

        if (deep.second + 1 > deepest.second)
            deepest = {deep.first, deep.second + 1};
    };

    return deepest;
}

void compute_distances(ll node, ll parent, vector<vector<ll>> &adj_list, vector<ll> &distances)
{
    for (auto adj : adj_list[node])
    {
        if (adj == parent)
            continue;

        distances[adj] = distances[node] + 1;

        compute_distances(adj, node, adj_list, distances);
    };
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<ll>> adj_list(n, vector<ll>());

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    pair<ll, ll> a = find_deepest(0, -1, adj_list);
    pair<ll, ll> b = find_deepest(a.first, -1, adj_list);

    vector<ll> distances_a(n, 0);
    vector<ll> distances_b(n, 0);

    distances_a[a.first] = 0;
    distances_b[b.first] = 0;

    compute_distances(a.first, -1, adj_list, distances_a);
    compute_distances(b.first, -1, adj_list, distances_b);

    for (ll i = 0; i < n; i++)
    {
        cout << max(distances_a[i], distances_b[i]) << " ";
    }

    cout << "\n";
}