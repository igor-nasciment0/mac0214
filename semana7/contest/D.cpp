// https://codeforces.com/contest/2254/problem/D

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll BIG = 1e9 + 7;

void run()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> shadow(n);

    for (ll i = 0; i < n; i++)
    {
        pair<ll, ll> a = {0, i};
        cin >> a.first;
        shadow[i] = a;
    }

    sort(shadow.begin(), shadow.end());

    if (shadow[0].first != 0)
    {
        cout << "-1\n";
        return;
    }

    vector<pair<ll, ll>> array(n);

    ll last_sum = 0;
    ll lower_index = 0;
    ll upper_index = 0;

    for (ll i = 0; i < n; i++)
    {
        if (shadow[upper_index].first == shadow[lower_index].first)
        {
            upper_index++;
            continue;
        }

        if ((shadow[i].first - last_sum) % (upper_index - lower_index) != 0)
        {
            cout << "-1\n";
            return;
        }

        ll value = (shadow[i].first - last_sum) / (upper_index - lower_index);

        if (lower_index > 0 && value <= array[lower_index - 1].first)
        {
            cout << "-1\n";
            return;
        }

        while (lower_index < upper_index)
        {
            array[lower_index] = {value, shadow[lower_index].second};
            lower_index++;
        }

        upper_index = lower_index + 1;
        last_sum = shadow[i].first;
    }

    ll value = (lower_index == 0 ? 1 : array[lower_index - 1].first + 1);

    while (lower_index < upper_index)
    {
        array[lower_index] = {value, shadow[lower_index].second};
        lower_index++;
    }

    sort(array.begin(), array.end(), [](auto &a, auto &b)
         { return a.second < b.second; });

    for (auto elem : array)
        cout << elem.first << " ";

    cout << "\n";
}

int main()
{
    ll n;
    cin >> n;

    while (n--)
        run();
}