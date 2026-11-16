// https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

ll exponential(ll a, ll b)
{
    a = a % BIG;

    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    ll mid = exponential(a, b / 2) % BIG;

    if (b % 2 == 0)
        return (mid * mid) % BIG;
    else
        return (((mid * mid) % BIG) * a) % BIG;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll num_fact = 1e6 + 1;

    vector<ll> factorial(num_fact);
    factorial[0] = 1;

    for (ll i = 1; i <= num_fact; i++)
        factorial[i] = (factorial[i - 1] * i) % BIG;

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

        ll denom = (factorial[b] * factorial[a - b]) % BIG;
        ll inv = exponential(denom, BIG - 2); // fermat's little theorem

        cout << (factorial[a] * inv) % BIG << "\n";
    }
}