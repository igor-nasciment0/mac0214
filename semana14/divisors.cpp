// https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

ll max_x = 1e6;

void count_factors(vector<ll> &num_factors)
{
    for (ll i = 1; i <= max_x; i++)
    {
        for (ll j = i; j <= max_x; j += i)
        {
            num_factors[j]++;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> num_factors(max_x + 1, 0);
    count_factors(num_factors);

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        cout << num_factors[x] << "\n";
    }
}