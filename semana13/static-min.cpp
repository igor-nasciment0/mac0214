// https://cses.fi/problemset/task/1647

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

ll ceil_div(ll a, ll b)
{
    ll q = a / b;
    ll r = a % b;
    if (r != 0 && ((r < 0) == (b < 0)))
    {
        q++;
    }
    return q;
}

void build_tree(ll index, ll n, vector<ll> &tree, vector<ll> &vec)
{
    if (index > 2 * n)
        return;

    if (index >= n - 1)
    {
        tree[index] = vec[index - n + 1];
        return;
    }

    ll left = 2 * index + 1;
    ll right = 2 * index + 2;

    build_tree(left, n, tree, vec);
    build_tree(right, n, tree, vec);

    tree[index] = min(tree[left], tree[right]);
}

ll query(ll node, ll node_l, ll node_r, ll a, ll b, vector<ll> &tree)
{
    if (node_l > b || node_r < a)
        return LLONG_MAX;

    if (node_l >= a && node_r <= b)
        return tree[node];

    // partial overlap

    ll min_l = query(2 * node + 1, node_l, (node_l + node_r) / 2, a, b, tree);
    ll min_r = query(2 * node + 2, ceil_div(node_l + node_r, 2), node_r, a, b, tree);

    return min(min_l, min_r);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        vec[i] = a;
    }

    ll i = n;
    n = (1 << (__bit_width(n)));

    for (; i < n; i++)
        vec.push_back(LLONG_MAX);

    vector<ll> tree(2 * n - 1);
    build_tree(0, n, tree, vec);

    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(0, 0, n - 1, a, b, tree) << "\n";
    }
}