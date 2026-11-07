// https://cses.fi/problemset/task/1678

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
    vector<ll> color_first(n, 0); // 0 = unvisited, 1 = active, 2 = finished

    for (ll i = 0; i < n; i++)
    {
        if (color_first[i] == 2)
            continue;

        stack<ll> dfs;
        dfs.push(i);

        while (!dfs.empty())
        {
            ll top = dfs.top();

            if (color_first[top] == 2)
            {
                dfs.pop(); // discard duplicate stack pushes
                continue;
            }

            if (color_first[top] == 1)
            {
                dfs.pop();
                color_first[top] = 2;
                end_order.push_back(top);
                continue;
            }

            color_first[top] = 1;

            for (auto neigh : graph[top])
            {
                if (color_first[neigh] == 0)
                    dfs.push(neigh);
            }
        }
    }

    vector<ll> result;
    bool got_it = false;
    ll node_traverse = -1;

    vector<ll> color(n, 0);
    vector<ll> parent(n, -1);

    reverse(end_order.begin(), end_order.end());

    for (ll node : end_order)
    {
        if (color[node] == 2)
            continue;

        stack<ll> dfs;
        dfs.push(node);

        while (!dfs.empty())
        {
            if (got_it) 
                break; // stop unwinding immediately to protect cycle variables

            ll top = dfs.top();

            if (color[top] == 2)
            {
                dfs.pop(); // discard duplicate stack pushes
                continue;
            }

            if (color[top] == 1)
            {
                color[top] = 2;
                dfs.pop();
                continue;
            }

            color[top] = 1;

            for (auto neigh : reverse_graph[top])
            {
                if (color[neigh] == 0 && !got_it)
                {
                    parent[neigh] = top;
                    dfs.push(neigh);
                }

                if (color[neigh] == 1)
                {
                    got_it = true;
                    result.push_back(neigh);
                    node_traverse = top;
                    break;
                }
            }
        }
        
        if (got_it) break;
    }

    if (got_it)
    {
        while (node_traverse != result[0])
        {
            result.push_back(node_traverse);
            node_traverse = parent[node_traverse];
        }

        result.push_back(node_traverse);

        cout << result.size() << "\n";

        for (auto elem : result)
            cout << elem + 1 << " ";

        cout << "\n";
        return 0;
    }

    cout << "IMPOSSIBLE\n";
}