// https://cses.fi/problemset/task/1133

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

void get_subtree_sizes(ll node, ll parent, vector<ll> &subtree_sizes, vector<vector<ll>> &adj_list, vector<ll> &sum_dist, ll depth)
{
    ll subtree_size = 1;
    sum_dist[0] += depth;

    for (auto adj : adj_list[node])
    {
        if (adj == parent)
            continue;

        get_subtree_sizes(adj, node, subtree_sizes, adj_list, sum_dist, depth + 1);
        subtree_size += subtree_sizes[adj];
    }

    subtree_sizes[node] = subtree_size;
}

void get_sum_distances(ll node, ll parent, ll n, vector<vector<ll>> &adj_list, vector<ll> &subtree_sizes, vector<ll> &sum_dist)
{
    if (parent != -1)
        sum_dist[node] = sum_dist[parent] + n - 2 * subtree_sizes[node];

    for (auto adj : adj_list[node])
    {
        if (adj == parent)
            continue;

        get_sum_distances(adj, node, n, adj_list, subtree_sizes, sum_dist);
    }
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
        a--; b--;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<ll> subtree_sizes(n, 0);
    vector<ll> sum_dist(n, 0);

    get_subtree_sizes(0, -1, subtree_sizes, adj_list, sum_dist, 0);
    get_sum_distances(0, -1, n, adj_list, subtree_sizes, sum_dist);

    for (ll i = 0; i < n; i++)
    {
        cout << sum_dist[i] << " ";
    }

    cout << "\n";
}