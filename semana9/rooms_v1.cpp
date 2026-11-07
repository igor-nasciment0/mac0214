// https://cses.fi/problemset/task/1192

// versão excessivamente lenta, usar UnionFind não foi uma ideia tão boa :(

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

struct pair_hash
{
    size_t operator()(const pair<ll, ll> &p) const
    {
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};

class UnionFind
{
public:
    unordered_set<pair<ll, ll>, pair_hash> universe;
    unordered_map<pair<ll, ll>, pair<ll, ll>, pair_hash> parents;
    unordered_map<pair<ll, ll>, ll, pair_hash> rank;

    ll count;

    UnionFind(unordered_set<pair<ll, ll>, pair_hash> s)
    {
        for (auto p : s)
        {
            parents[p] = p;
            rank[p] = 1;
        }

        universe = s;
        count = s.size();
    }

    void onion(pair<ll, ll> a, pair<ll, ll> b)
    {
        if (!universe.count(a) || !universe.count(b))
            return;

        a = find(a);
        b = find(b);

        if (a == b)
            return;

        pair<ll, ll> greater, lesser;

        if (rank[a] > rank[b])
        {
            greater = a;
            lesser = b;
        }
        else
        {
            greater = b;
            lesser = a;
        }

        parents[lesser] = greater;
        rank[greater] += rank[lesser];
        count--;
    }

    pair<ll, ll> find(pair<ll, ll> a)
    {
        if (parents[a] != parents[parents[a]])
            parents[a] = find(parents[a]);

        return parents[a];
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    unordered_set<pair<ll, ll>, pair_hash> floors = {};

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            if (c == '.')
            {
                floors.insert({i, j});
            }
        }
    }

    UnionFind uf(floors);

    for (auto floor : floors)
    {
        uf.onion(floor, {floor.first + 1, floor.second});
        uf.onion(floor, {floor.first, floor.second + 1});
        uf.onion(floor, {floor.first - 1, floor.second});
        uf.onion(floor, {floor.first, floor.second - 1});
    }

    cout << uf.count << "\n";
}