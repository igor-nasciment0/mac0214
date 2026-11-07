// https://atcoder.jp/contests/dp/tasks/dp_o?lang=en

#include <bits/stdc++.h>

typedef unsigned long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

ll n;
vector<ll> compatible;
vector<ll> dp;

ll count_ways(ll women_mask)
{
    if(dp[women_mask] != -1)
        return dp[women_mask];

    if (women_mask == (1 << n) - 1)
        return 1;

    ll count = 0;

    ll man_index = __popcount(women_mask);
    ll available = compatible[man_index] & (~women_mask);

    while (available != 0)
    {
        ll option = 1 << countr_zero(available);
        count += count_ways(women_mask | option);
        count = count % BIG;
        available -= option;
    }

    dp[women_mask] = count;
    return count;
}

int main()
{
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        string bitstring = "";

        for (ll j = 0; j < n; j++)
        {
            char in;
            cin >> in;
            bitstring += in;
        }

        compatible.push_back(bitset<32>(bitstring).to_ullong());
    }

    dp = vector<ll>(1 << n, -1);

    ll women_mask = 0;
    ll result = count_ways(women_mask);

    cout << result;
}