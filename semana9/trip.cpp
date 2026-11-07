// https://cses.fi/problemset/task/1669

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

vector<ll> result;

bool dfs(vector<ll> &color, vector<vector<ll>> &neighboors, ll node, ll prev)
{
    color[node] = 1;

    for (ll neighboor : neighboors[node])
    {
        if (neighboor != prev && color[neighboor] == 1)
        {
            result.push_back(neighboor);
            result.push_back(node);
            return true;
        }

        if (neighboor != prev)
        {
            bool found = dfs(color, neighboors, neighboor, node);

            if (found)
            {
                if (result[0] != result[result.size() - 1])
                    result.push_back(node);
                    
                return true;
            }
        }
    }

    color[node] = 2;
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> neighboors(n, vector<ll>());

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        neighboors[a].push_back(b);
        neighboors[b].push_back(a);
    }

    vector<ll> color(n, 0);

    for (ll node = 0; node < n; node++)
    {
        if (color[node] != 0)
            continue;

        bool found = dfs(color, neighboors, node, -1);

        if (found)
        {
            if (result[0] != result[result.size() - 1])
                result.push_back(node);

            break;
        }
    }

    if (result.size() == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << result.size() << "\n";

    for (auto node : result)
    {
        cout << node + 1 << " ";
    }

    cout << "\n";
}