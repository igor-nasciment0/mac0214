// https://cses.fi/problemset/task/1076

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> rb_tree;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        vec[i] = a;
    }

    vector<ll> results(n - k + 1);

    rb_tree tree;

    ll counter = 0;

    for (ll i = 0; i < k; i++)
        tree.insert({vec[i], counter++});

    ll index = k % 2 == 0 ? (k / 2 - 1) : (k / 2);

    results[0] = tree.find_by_order(index)->first;

    for (ll i = 1, j = k; j < n; i++, j++)
    {
        ll exiting = vec[i - 1], entering = vec[j];
        tree.insert({entering, counter++});
        tree.erase({exiting, i - 1});

        results[i] = tree.find_by_order(index)->first;
    }

    for (auto r : results)
        cout << r << " ";

    cout << "\n";
}