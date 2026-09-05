// https://cses.fi/problemset/task/1642

// This ideia would not break the time limit, but the case of "sum == x, but indices overlap" (line 58) 
// could not be properly solved using only two pointers.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, x;

    cin >> n >> x;
    vector<ll> vec;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        vec.push_back(a);
    }

    vector<tuple<ll, ll, ll>> combinations;

    for (ll i = 0; i < n; i++)
        for (ll j = i + 1; j < n; j++)
            combinations.push_back({vec[i] + vec[j], i, j});

    sort(combinations.begin(), combinations.end());

    ll i = 0, j = combinations.size() - 1;
    bool gotit = false;

    while (i < j)
    {
        ll sum = get<0>(combinations[i]) + get<0>(combinations[j]);

        while (sum < x && ++i < j)
            sum = get<0>(combinations[i]) + get<0>(combinations[j]);

        while (sum > x && i < --j)
            sum = get<0>(combinations[i]) + get<0>(combinations[j]);

        ll a = get<1>(combinations[i]);
        ll b = get<2>(combinations[i]);
        ll c = get<1>(combinations[j]);
        ll d = get<2>(combinations[j]);

        set<ll> s = {a, b, c, d};

        if (sum == x && s.size() == 4)
        {
            gotit = true;
            break;
        }
        else if (sum == x)
        {
            if (get<0>(combinations[i]) == get<0>(combinations[i - 1]))
                i++;
            else
                j--;
        }
    }

    if (gotit)
        cout << get<1>(combinations[i]) + 1 << " " << get<2>(combinations[i]) + 1 << " " << get<1>(combinations[j]) + 1 << " " << get<2>(combinations[j]) + 1 << "\n";
    else
        cout << "IMPOSSIBLE";

    return 0;
}