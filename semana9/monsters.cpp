// https://cses.fi/problemset/task/1194

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
const ll BIG = 1e9 + 7;

ll n, m;
pair<ll, ll> exiting = {-1, -1};

void monster_bfs(vector<pair<ll, ll>> monsters, vector<bool> &is_floor, vector<ll> &monster_dist)
{
    queue<pair<ll, ll>> bfs_queue;

    for (auto monster : monsters)
        bfs_queue.push({monster.first, monster.second});

    while (!bfs_queue.empty())
    {
        pair<ll, ll> front = bfs_queue.front();
        bfs_queue.pop();
        ll i = front.first, j = front.second;

        for (ll k = -1; k <= 1; k += 2)
        {
            ll coord = (i + k) * m + j;

            if (i + k >= 0 && i + k < n && is_floor[coord] && monster_dist[coord] > monster_dist[i * m + j] + 1)
            {
                monster_dist[coord] = monster_dist[i * m + j] + 1;
                bfs_queue.push({i + k, j});
            }

            coord = i * m + (j + k);

            if (j + k >= 0 && j + k < m && is_floor[coord] && monster_dist[coord] > monster_dist[i * m + j] + 1)
            {
                monster_dist[coord] = monster_dist[i * m + j] + 1;
                bfs_queue.push({i, j + k});
            }
        }
    }
}

void adventurer_bfs(ll i, ll j, vector<ll> &monster_dist, vector<bool> &visited, vector<bool> &is_floor, vector<pair<char, ll>> &path)
{
    queue<pair<ll, ll>> bfs_queue;
    bfs_queue.push({i, j});

    while (!bfs_queue.empty())
    {
        pair<ll, ll> front = bfs_queue.front();
        bfs_queue.pop();
        i = front.first, j = front.second;

        ll current = i * m + j;
        ll coord = (i + 1) * m + j;

        if (i + 1 < n && is_floor[coord] && monster_dist[coord] > path[current].second + 1 && !visited[coord])
        {
            path[coord] = {'D', path[current].second + 1};
            visited[coord] = true;
            bfs_queue.push({i + 1, j});

            if (i + 1 == n - 1)
            {
                exiting = {i + 1, j};
                break;
            }
        }

        coord = (i - 1) * m + j;

        if (i - 1 >= 0 && is_floor[coord] && monster_dist[coord] > path[current].second + 1 && !visited[coord])
        {
            path[coord] = {'U', path[current].second + 1};
            visited[coord] = true;
            bfs_queue.push({i - 1, j});

            if (i - 1 == 0)
            {
                exiting = {i - 1, j};
                break;
            }
        }

        coord = i * m + (j + 1);

        if (j + 1 < m && is_floor[coord] && monster_dist[coord] > path[current].second + 1 && !visited[coord])
        {
            path[coord] = {'R', path[current].second + 1};
            visited[coord] = true;
            bfs_queue.push({i, j + 1});

            if (j + 1 == m - 1)
            {
                exiting = {i, j + 1};
                break;
            }
        }

        coord = i * m + (j - 1);

        if (j - 1 >= 0 && is_floor[coord] && monster_dist[coord] > path[current].second + 1 && !visited[coord])
        {
            path[coord] = {'L', path[current].second + 1};
            visited[coord] = true;
            bfs_queue.push({i, j - 1});

            if (j - 1 == 0)
            {
                exiting = {i, j - 1};
                break;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n >> m;

    vector<bool> is_floor(n * m);

    vector<pair<ll, ll>> monsters;
    vector<ll> monster_dist(n * m, LLONG_MAX);

    pair<ll, ll> adventurer;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if (c != '#')
                is_floor[i * m + j] = true;

            if (c == 'M')
            {
                monsters.push_back({i, j});
                monster_dist[i * m + j] = 0;
            }

            if (c == 'A')
                adventurer = {i, j};
        }
    }

    if (set<ll>({0, n - 1}).count(adventurer.first) || set<ll>({0, m - 1}).count(adventurer.second))
    {
        cout << "YES\n0\n";
        return 0;
    }

    monster_bfs(monsters, is_floor, monster_dist);

    vector<pair<char, ll>> path(n * m);
    path[adventurer.first * m + adventurer.second] = {'\0', 0};

    vector<bool> visited(n * m, false);
    adventurer_bfs(adventurer.first, adventurer.second, monster_dist, visited, is_floor, path);

    if (exiting.first == -1 && exiting.second == -1)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "YES" << "\n";

        string path_str = "";
        ll i = exiting.first, j = exiting.second;

        while (i != adventurer.first || j != adventurer.second)
        {
            ll coord = i * m + j;
            path_str += path[coord].first;

            if (path[coord].first == 'D')
            {
                i--;
            }

            else if (path[coord].first == 'U')
            {
                i++;
            }

            else if (path[coord].first == 'L')
            {
                j++;
            }

            else if (path[coord].first == 'R')
            {
                j--;
            }
        }

        std::cout << path_str.size() << "\n";
        std::reverse(path_str.begin(), path_str.end());
        std::cout << path_str << "\n";
    }
}