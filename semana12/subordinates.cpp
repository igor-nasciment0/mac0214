// https://cses.fi/problemset/task/0000

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

void dfs(ll node, vector<ll> &size, vector<vector<ll>> &adj_list)
{
    ll sub_number = 0;

    for (auto sub : adj_list[node])
    {
        dfs(sub, size, adj_list);
        sub_number += size[sub] + 1;
    }

    size[node] = sub_number;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    cin >> n;

    vector<vector<ll>> adj_list(n, vector<ll>());

    for (ll i = 1; i <= n - 1; i++)
    {
        ll a;
        cin >> a;
        a--;
        adj_list[a].push_back(i);
    }

    vector<ll> size(n);
    dfs(0, size, adj_list);

    for (auto node : size)
        cout << node << " ";

    cout << "\n";
}