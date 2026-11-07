// https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

enum Color
{
    WHITE,
    GRAY,
    BLACK
};

vector<ll> result;

bool dfs(ll node, vector<Color> &color, vector<vector<ll>> &successors)
{
    color[node] = GRAY;

    for (auto succ : successors[node])
    {
        if(color[succ] == BLACK)
            continue;

        if (color[succ] == GRAY)
            return false;

        bool subcall = dfs(succ, color, successors);

        if (!subcall)
            return false;
    }

    color[node] = BLACK;
    result.push_back(node);
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<Color> color(n, WHITE);
    vector<vector<ll>> successors(n, vector<ll>());

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        successors[a].push_back(b);
    }

    for (ll i = 0; i < n; i++)
    {
        if (color[i] != WHITE)
            continue;

        bool subcall = dfs(i, color, successors);

        if (!subcall)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    reverse(result.begin(), result.end());

    for (auto elem : result)
    {
        cout << elem + 1 << " ";
    }

    cout << "\n";
}