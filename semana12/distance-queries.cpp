// https://cses.fi/problemset/task/1135

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

class UnionFind
{
    vector<ll> parent;
    vector<ll> size;

public:
    UnionFind(ll n)
    {
        parent = vector<ll>(n);

        for (ll i = 0; i < n; i++)
            parent[i] = i;
    }

    void unite(ll par, ll child)
    {
        par = find(par);
        child = find(child);

        if (par == child)
            return;

        parent[child] = par;
    }

    ll find(ll a)
    {
        ll root;

        if (parent[a] == a)
            root = a;
        else
            root = find(parent[a]);

        parent[a] = root;
        return root;
    }
};

void dfs(
    ll node,
    ll prev,
    vector<vector<ll>> &adj_list,
    UnionFind &uf,
    vector<vector<ll>> &must_query,
    vector<bool> &visited,
    vector<ll> &distance,
    vector<unordered_map<ll, ll>> &lca)
{
    visited[node] = true;

    for (auto adj : adj_list[node])
    {
        if (adj == prev)
            continue;

        distance[adj] = distance[node] + 1;
        dfs(adj, node, adj_list, uf, must_query, visited, distance, lca);
        uf.unite(node, adj);
    }

    for (auto q : must_query[node])
    {
        if (!visited[q])
            continue;

        ll lc_ancestor = uf.find(q);
        lca[node][q] = lc_ancestor;
        lca[q][node] = lc_ancestor;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

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

    vector<pair<ll, ll>> queries;
    vector<vector<ll>> must_query(n, vector<ll>());
    UnionFind uf(n);

    vector<ll> distance(n);
    distance[0] = 0;

    vector<unordered_map<ll, ll>> lca(n, unordered_map<ll, ll>());
    vector<bool> visited(n, false);

    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        queries.push_back({a, b});
        must_query[a].push_back(b);
        must_query[b].push_back(a);
    }

    dfs(0, -1, adj_list, uf, must_query, visited, distance, lca);

    for (auto query : queries)
    {
        ll a = query.first, b = query.second;
        cout << distance[a] + distance[b] - 2 * distance[lca[a][b]] << "\n";
    }
}