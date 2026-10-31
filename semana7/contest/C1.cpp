// https://cses.fi/problemset/task/0000

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

void run()
{
    ll n;
    cin >> n;

    vector<ll> A_ones;
    vector<ll> B_ones;

    for (ll i = 0; i < n; i++)
    {
        char in;
        cin >> in;

        if (in == '1')
            A_ones.push_back(i);
    }

    for (ll i = 0; i < n; i++)
    {
        char in;
        cin >> in;

        if (in == '1')
            B_ones.push_back(i);
    }

    if (A_ones.size() != B_ones.size())
    {
        cout << "NO\n";
        return;
    }

    ll num_odd_A = 0, num_odd_B = 0;

    for (ll i = 0; i < B_ones.size(); i++)
    {
        if (A_ones[i] % 2 == 1)
            num_odd_A++;

        if (B_ones[i] % 2 == 1)
            num_odd_B++;
    }

    if (num_odd_A == num_odd_B)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ll n;
    cin >> n;

    while (n--)
        run();
}