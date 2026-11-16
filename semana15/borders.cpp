// https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string s;
    cin >> s;

    ll n = s.length();

    vector<ll> pi(n + 1, 0);
    pi[0] = -1;

    for (ll i = 1; i <= n; i++)
    {
        ll size = pi[i - 1];

        while (size != -1 && s[i - 1] != s[size])
            size = pi[size];

        size++;
        pi[i] = size;
    }

    ll border_length = pi[n];
    vector<ll> borders;

    while (border_length > 0)
    {
        borders.push_back(border_length);
        border_length = pi[border_length];
    }

    for (ll i = borders.size() - 1; i >= 0; i--)
        cout << borders[i] << ' ';

    cout << "\n";
}