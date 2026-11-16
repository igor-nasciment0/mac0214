// https://cses.fi/problemset/task/2417

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    cin >> n;

    ll max_x = 1;
    vector<ll> freq(1e6 + 1, 0);

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        freq[a]++;

        max_x = max(max_x, a);
    }

    vector<ll> exact_gcd(max_x + 1, 0);

    for (ll d = max_x; d >= 1; d--)
    {
        ll multiples = 0;
        for (ll i = d; i <= max_x; i += d)
            multiples += freq[i];

        exact_gcd[d] = multiples * (multiples - 1) / 2;

        for (ll m = 2 * d; m <= max_x; m += d)
            exact_gcd[d] -= exact_gcd[m];
    }

    cout << exact_gcd[1] << "\n";
}