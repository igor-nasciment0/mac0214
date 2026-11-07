// https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll m, n;
    cin >> m >> n;

    pair<ll, ll> entrance, exit;

    vector<vector<optional<bool>>> visited(m, vector<optional<bool>>(n, nullopt));
    vector<vector<char>> direction(m, vector<char>(n, '\0'));

    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c != '#')
                visited[i][j] = false;

            if (c == 'A')
                entrance = {i, j};
            if (c == 'B')
                exit = {i, j};
        }
    }

    queue<pair<ll, ll>> bfs_queue;
    bfs_queue.push(entrance);

    string path_exit = "";

    while (!bfs_queue.empty())
    {
        auto top = bfs_queue.front();
        bfs_queue.pop();

        ll i = top.first;
        ll j = top.second;

        if (i == exit.first && j == exit.second)
        {
            break;
        }

        if (i + 1 < m && visited[i + 1][j].has_value() && !(*visited[i + 1][j]))
        {
            bfs_queue.push({i + 1, j});
            visited[i + 1][j] = true;
            direction[i + 1][j] = 'D';
        }
        if (j + 1 < n && visited[i][j + 1].has_value() && !(*visited[i][j + 1]))
        {
            bfs_queue.push({i, j + 1});
            visited[i][j + 1] = true;
            direction[i][j + 1] = 'R';
        }
        if (i - 1 >= 0 && visited[i - 1][j].has_value() && !(*visited[i - 1][j]))
        {
            bfs_queue.push({i - 1, j});
            visited[i - 1][j] = true;
            direction[i - 1][j] = 'U';
        }
        if (j - 1 >= 0 && visited[i][j - 1].has_value() && !(*visited[i][j - 1]))
        {
            bfs_queue.push({i, j - 1});
            visited[i][j - 1] = true;
            direction[i][j - 1] = 'L';
        }
    }

    if (*visited[exit.first][exit.second])
    {
        cout << "YES" << "\n";

        string path = "";
        ll i = exit.first, j = exit.second;

        while (i != entrance.first || j != entrance.second)
        {
            path += direction[i][j];

            if (direction[i][j] == 'D')
            {
                i--;
            }

            else if (direction[i][j] == 'U')
            {
                i++;
            }

            else if (direction[i][j] == 'L')
            {
                j++;
            }

            else if (direction[i][j] == 'R')
            {
                j--;
            }
        }

        cout << path.size() << "\n";
        reverse(path.begin(), path.end());
        cout << path << "\n";
    }
    else
        cout << "NO" << "\n";
}