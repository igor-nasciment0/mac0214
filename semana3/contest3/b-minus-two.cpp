// https://codeforces.com/contest/2259/problem/B

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> vec;

    ll odd = 0, single_even = 0, double_even = 0;

    for (ll i = 0; i < n; i++)
    {
        ll in;
        cin >> in;

        if (in % 2 != 0)
        {
            odd++;
            continue;
        }
        
        in = in / 2;

        if(in % 2 != 0)
            single_even++;
        else
            double_even++;
    }

    cout << max(max(odd, single_even), double_even) << "\n";    
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}