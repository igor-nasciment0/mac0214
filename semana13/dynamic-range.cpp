// https://cses.fi/problemset/task/1651

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

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

    tree[index] = 0;
}

void update(ll node, ll node_l, ll node_r, ll a, ll b, ll update_value, vector<ll> &tree)
{
    if (node_l > b || node_r < a)
        return;

    if (node_l >= a && node_r <= b)
    {
        tree[node] += update_value;
        return;
    }

    // partial overlap

    ll mid = (node_l + node_r) / 2;

    update(2 * node + 1, node_l, mid, a, b, update_value, tree);
    update(2 * node + 2, mid + 1, node_r, a, b, update_value, tree);
}

ll query(ll node, ll node_l, ll node_r, ll index, ll n, vector<ll> &tree)
{
    if (node_l >= node_r)
        return tree[n - 1 + node_l];

    ll mid = (node_l + node_r) / 2;

    if (index <= mid)
        return tree[node] + query(2 * node + 1, node_l, mid, index, n, tree);
    else
        return tree[node] + query(2 * node + 2, mid + 1, node_r, index, n, tree);
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
        vec.push_back(0);

    vector<ll> tree(2 * n - 1);
    build_tree(0, n, tree, vec);

    for (ll i = 0; i < q; i++)
    {
        ll op;
        cin >> op;

        if (op == 1)
        {
            ll a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;

            update(0, 0, n - 1, a, b, u, tree);
        }
        else
        {
            ll k;
            cin >> k;
            k--;
            cout << query(0, 0, n - 1, k, n, tree) << "\n";
        }
    }
}