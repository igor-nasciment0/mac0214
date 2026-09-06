// https://codeforces.com/contest/2259/problem/A

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll count = 0;

    for (ll i = 0; i < n / k; i++)
    {
        bool has_zero = false;

        for (ll j = 0; j < k; j++)
        {
            char a;
            cin >> a;
            if (a == '0')
                has_zero = true;
        }

        if (!has_zero)
            count++;        
    }

    cout << count << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}