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

    sort(vec.begin(), vec.end());

    ll median = vec[n/2];

    ll cost = 0;

    for (ll i = 0; i < n; i++)
        cost += abs(vec[i] - median);

    cout << cost << "\n";
}