// https://cses.fi/problemset/task/1628

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void get_subset_sums(vector<ll> &vec, vector<ll> &result);

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> vec1;
    vector<ll> vec2;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;

        if (i < n / 2)
            vec1.push_back(a);
        else
            vec2.push_back(a);
    }

    vector<ll> sums1;
    get_subset_sums(vec1, sums1);
    vector<ll> sums2;
    get_subset_sums(vec2, sums2);

    sort(sums1.begin(), sums1.end());
    sort(sums2.begin(), sums2.end());

    ll counting = 0;

    for (ll i = 0; i < sums1.size(); i++)
    {
        ll op = sums1[i];
        auto range = equal_range(sums2.begin(), sums2.end(), x - op);
        counting += (range.second - range.first);
    }

    cout << counting << "\n";
}

void get_subset_sums(vector<ll> &vec, vector<ll> &result)
{
    for (ll i = 0; i < (1 << vec.size()); i++)
    {
        ll sum = 0;

        for (ll b = 0; b < vec.size(); b++)
        {
            if (i & (1 << b))
            {
                sum += vec[b];
            }
        }

        result.push_back(sum);
    }
}