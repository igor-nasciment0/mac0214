// https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string s, p;
    cin >> s >> p;

    ll n = s.length(), m = p.length();

    vector<ll> pi(m + 1, 0);

    pi[0] = -1;

    for (ll i = 1; i <= m; i++)
    {
        ll size = pi[i - 1];

        while (size != -1 && p[i - 1] != p[size])
            size = pi[size];

        size++;
        pi[i] = size;
    }

    ll occurs = 0;
    ll concord = 0;
    
    for (ll i = 0; i < n; i++)
    {
        while (concord != -1 && s[i] != p[concord])
            concord = pi[concord];

        concord++;

        if(concord == m)
        {
            occurs++;
            concord = pi[concord];
        }
    }

    cout << occurs << "\n";
}