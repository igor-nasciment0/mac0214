// https://cses.fi/problemset/task/2136

#include <bit>
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll minimum_hamming(vector<ll> &vec)
{
    ll minim = numeric_limits<ll>::max();

    for (ll i = 0; i < vec.size(); i++)
    {
        for (ll j = i + 1; j < vec.size(); j++)
        {
            ll x = __popcount(vec[i] ^ vec[j]);
            if (x < minim)
                minim = x;
        }
    }

    return minim;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> bit_strings;

    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ll bits = stoi(s, nullptr, 2);
        bit_strings.push_back(bits);
    }

    cout << minimum_hamming(bit_strings) << "\n";

    return 0;
}