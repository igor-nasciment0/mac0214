// https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(true);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> graph(n, vector<ll>());
    vector<vector<ll>> reverse_graph(n, vector<ll>());

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }

    vector<ll> end_order;
    vector<bool> visited(n, false);

    vector<ll> first_components;

    for (ll i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        first_components.push_back(i);

        stack<ll> dfs;
        dfs.push(i);

        while (!dfs.empty())
        {
            ll top = dfs.top();

            if (visited[top])
            {
                dfs.pop();
                end_order.push_back(top);
                continue;
            }

            visited[top] = true;

            for (auto neigh : graph[top])
            {
                if (!visited[neigh])
                    dfs.push(neigh);
            }
        }
    }

    if (first_components.size() > 1)
    {
        cout << "NO\n";
        cout << first_components[0] + 1 << " " << first_components[1] + 1 << "\n";
        return 0;
    }

    vector<ll> second_components;

    for(ll i = 0; i < n; i++)
        visited[i] = false;

    reverse(end_order.begin(), end_order.end());

    for (ll node : end_order)
    {
        if (visited[node])
            continue;

        second_components.push_back(node);

        stack<ll> dfs;
        dfs.push(node);

        while (!dfs.empty())
        {
            ll top = dfs.top();

            if (visited[top])
            {
                dfs.pop();
                continue;
            }

            visited[top] = true;

            for (auto neigh : reverse_graph[top])
            {
                if (!visited[neigh])
                    dfs.push(neigh);
            }
        }
    }

    if (second_components.size() > 1)
    {
        cout << "NO\n";
        cout << second_components[1] + 1 << " " << second_components[0] + 1 << "\n";
        return 0;
    }

    cout << "YES\n";
}