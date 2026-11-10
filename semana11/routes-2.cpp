// https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

// here we use the Floyd–Warshall algorithm

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> distance(n, vector<ll>(n, LLONG_MAX));

    for (ll i = 0; i < n; i++)
        distance[i][i] = 0;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        if (distance[a][b] > c)
        {
            distance[a][b] = c;
            distance[b][a] = c;
        }
    }

    for (ll k = 0; k < n; k++)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < i; j++)
            {
                if (distance[i][k] == LLONG_MAX || distance[k][j] == LLONG_MAX)
                    continue;

                ll new_d = min(distance[i][j], distance[i][k] + distance[k][j]);
                
                distance[i][j] = new_d;
                distance[j][i] = new_d;
            }
        }
    }

    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << (distance[a][b] == LLONG_MAX ? -1 : distance[a][b]) << "\n";
    }
}