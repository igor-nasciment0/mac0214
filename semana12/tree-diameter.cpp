// https://cses.fi/problemset/task/0000

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

/*
    IDEIA:

    1. o diâmetro tem que envolver a maior distância para qualquer nó específico
    2. pego ele e calculo a maior distância para outro nó
*/

pair<ll, ll> find_deepest(ll node, ll parent, vector<vector<ll>> &adj_list)
{
    // retorna <nó, depth>

    pair<ll, ll> deepest = {node, 0};

    for (auto adj : adj_list[node])
    {
        if(adj == parent)
            continue;

        pair<ll, ll> deep = find_deepest(adj, node, adj_list);

        if (deep.second + 1 > deepest.second)
            deepest = {deep.first, deep.second + 1};
    };

    return deepest;
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

    cout << b.second << '\n';
}