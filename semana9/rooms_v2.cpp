// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

ll m, n;

void dfs(vector<vector<optional<bool>>> &visited, ll i, ll j)
{
    visited[i][j] = true;

    if (i + 1 < m && visited[i + 1][j].has_value() && !(*visited[i + 1][j]))
        dfs(visited, i + 1, j);
    if (j + 1 < n && visited[i][j + 1].has_value() && !(*visited[i][j + 1]))
        dfs(visited, i, j + 1);
    if (i - 1 >= 0 && visited[i - 1][j].has_value() && !(*visited[i - 1][j]))
        dfs(visited, i - 1, j);
    if (j - 1 >= 0 && visited[i][j - 1].has_value() && !(*visited[i][j - 1]))
        dfs(visited, i, j - 1);
}

int main()
{
    cin >> m >> n;

    vector<vector<optional<bool>>> visited(m, vector<optional<bool>>(n, nullopt));

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c == '.')
                visited[i][j] = false;
        }
    }

    ll count = 0;

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (visited[i][j].has_value() && !(*visited[i][j]))
            {
                count++;
                dfs(visited, i, j);
            }
        }
    }

    cout << count << "\n";
}