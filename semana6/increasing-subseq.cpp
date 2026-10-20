// https://cses.fi/alon/task/1145

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ll n;
    cin >> n;
    vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        vec[i] = a;
    }

    vector<ll> best_value(n);

    for (ll i = 0; i < n; i++)
    {
        ll longest = 1;

        ll a = best_value

        for (ll k = 0; k < i; k++)
            if (vec[k] < vec[i])
                longest = max(longest, best_sequence[k] + 1);

        best_sequence[i] = longest;
    }

    cout << best_sequence[n - 1] << "\n";
}