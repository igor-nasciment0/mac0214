// https://cses.fi/problemset/task/1642

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

    unordered_multimap<ll, pair<ll, ll>> sums;
    vector<ll> response = {-1, -1, -1, -1};

    bool gotit = false;

    for (ll i = 0; i < n; i++)
    {
        if (gotit)
            break;

        for (ll j = i + 1; j < n; j++)
        {
            ll sum = vec[i] + vec[j];
            auto range = sums.equal_range(x - sum);
            auto diff = range.first;

            while (diff != range.second)
            {
                set<ll> s = {diff->second.second, diff->second.first, i, j};

                if (s.size() != 4)
                {
                    diff++;
                    continue;
                }

                response.assign({i, j, diff->second.first, diff->second.second});
                gotit = true;
                break;
            }

            if (gotit)
                break;

            sums.insert({vec[i] + vec[j], {i, j}});
        }
    }

    if (gotit)
        cout << response[0] + 1 << " " << response[1] + 1 << " " << response[2] + 1 << " " << response[3] + 1 << "\n";
    else
        cout << "IMPOSSIBLE";

    return 0;
}