// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;

    for (ll row = 0; row < n; row++)
    {
    }

    return 0;
}

// ◣ ◢ ◤ ◥ U A C 3 ■ I
ll num_ways(ll row_idx, ll n, pair<char, char> prev)
{
    ll num = 0;

    if ((prev.first == '◣' && prev.second == '◢') || (prev.first == 'I' && prev.second == 'I'))
    {
        num += 2;

        if (row_idx < n)
            num += num_ways(row_idx + 1, n, {'I', 'I'});

        num += num_ways(row_idx + 1, n, {'◤', '◥'});
    }

    if (condition)
    {
        /* code */
    }
    
}