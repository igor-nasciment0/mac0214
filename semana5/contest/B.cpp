// https://codeforces.com/contest/1985/problem/B

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    ll largest = 0;
    ll largest_sum = 0;

    for (ll x = 2; x <= n; x++)
    {
        ll k = n/x;

        ll sum = (k *(k + 1) * x)/2;

        if (sum > largest_sum)
        {
            largest = x;
            largest_sum = sum;
        }
    }

    cout << largest << "\n";
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
        solve();
}