// https://cses.fi/problemset/task/1661/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll find_rank(vector<ll> &vec, ll x)
{
    if(vec.empty())
        return 0;

    ll rank = 0;

    for (ll b = vec.size() / 2; b >= 1; b /= 2)
    {
        while (rank + b < (ll)vec.size() && vec[rank + b] < x)
            rank += b;
    }

    if(vec[rank] < x)
        rank++;

    return rank;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, x;
    cin >> n >> x;

    vector<ll> array;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        array.push_back(a);
    }

    map<ll, vector<ll>> totals;

    ll count_arrays = 0;

    for (ll i = 0, sum = 0; i < n; i++)
    {
        sum += array[i];

        if (totals.count(sum) == 0)
        {
            vector<ll> v;
            v.push_back(i);
            totals.insert({sum, v});
        }
        else
            totals.find(sum)->second.push_back(i);
    }

    for (ll i = 0, sum = 0; i < n; i++)
    {
        sum += array[i];
        ll diff = -x + sum;

        if(sum == x)
            count_arrays++;

        if (totals.find(diff) != totals.end())
            count_arrays += find_rank(totals[diff], i);
    }

    cout << count_arrays << "\n";
}