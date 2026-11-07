// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

ll find(vector<ll> &representant, ll a)
{
    if (representant[a] != representant[representant[a]])
        representant[a] = find(representant, representant[a]);

    return representant[a];
}

void onion(vector<ll> &representant, ll a, ll b)
{
    a = find(representant, a);
    b = find(representant, b);

    representant[b] = a;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    unordered_set<ll> components;
    vector<ll> representant(n);

    for (ll i = 0; i < n; i++)
    {
        components.insert(i);
        representant[i] = i;
    }

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        if (find(representant, a) != find(representant, b))
        {
            components.erase(find(representant, b));
            onion(representant, a, b);
        }
    }

    vector<pair<ll, ll>> additional;

    cout << components.size() - 1 << "\n";

    while (components.size() > 1)
    {
        ll a = *components.begin();
        ll b = *(++components.begin());

        additional.push_back({a + 1, b + 1});

        components.erase(find(representant, b));
        onion(representant, a, b);
    }

    for (auto elem : additional)
        cout << elem.first << " " << elem.second << "\n";
}