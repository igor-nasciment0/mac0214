// https://cses.fi/problemset/task/1749

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void build_tree(ll index, ll orig_n, ll n, vector<ll> &tree)
{
    if (index >= n - 1)
    {
        ll pos = index - n + 1;
        tree[index] = (pos < orig_n) ? 1 : 0;
        return;
    }

    ll left = 2 * index + 1;
    ll right = 2 * index + 2;

    build_tree(left, orig_n, n, tree);
    build_tree(right, orig_n, n, tree);

    tree[index] = tree[left] + tree[right];
}

ll query_and_remove(ll node, ll node_l, ll node_r, ll k, vector<ll> &tree)
{
    if (node_l == node_r)
    {
        tree[node] = 0;
        return node_l;
    }

    ll left = 2 * node + 1;
    ll right = 2 * node + 2;
    ll mid = (node_l + node_r) / 2;

    ll original_idx;
    if (tree[left] >= k)
        original_idx = query_and_remove(left, node_l, mid, k, tree);
    else
        original_idx = query_and_remove(right, mid + 1, node_r, k - tree[left], tree);

    tree[node] = tree[left] + tree[right];
    return original_idx;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll orig_n;
    cin >> orig_n;

    vector<ll> vec(orig_n);
    for (ll i = 0; i < orig_n; i++)
        cin >> vec[i];

    ll n = (orig_n == 1) ? 1 : (1LL << __bit_width(orig_n - 1));

    vector<ll> tree(2 * n - 1, 0);
    build_tree(0, orig_n, n, tree);

    for (ll i = 0; i < orig_n; i++)
    {
        ll p;
        cin >> p;

        ll idx = query_and_remove(0, 0, n - 1, p, tree);
        cout << vec[idx] << (i + 1 == orig_n ? "" : " ");
    }
    cout << "\n";
}