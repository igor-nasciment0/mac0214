// https://cses.fi/problemset/task/0000

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

void run()
{
    ll n;
    cin >> n;

    vector<ll> A_odd_ones;
    vector<ll> A_even_ones;

    vector<ll> B_odd_ones;
    vector<ll> B_even_ones;

    for (ll i = 0; i < n; i++)
    {
        char in;
        cin >> in;

        if (in == '1')
        {
            if (i % 2 == 0)
                A_even_ones.push_back(i);
            else
                A_odd_ones.push_back(i);
        }
    }

    for (ll i = 0; i < n; i++)
    {
        char in;
        cin >> in;

        if (in == '1')
        {
            if (i % 2 == 0)
                B_even_ones.push_back(i);
            else
                B_odd_ones.push_back(i);
        }
    }

    if (A_odd_ones.size() != B_odd_ones.size() || A_even_ones.size() != B_even_ones.size())
    {
        cout << "-1\n";
        return;
    }

    ll count = 0;

    for (ll i = 0; i < B_even_ones.size(); i++)
        count += abs(A_even_ones[i] - B_even_ones[i])/2;

    for (ll i = 0; i < B_odd_ones.size(); i++)
        count += abs(A_odd_ones[i] - B_odd_ones[i])/2;

    cout << count << "\n";
}

int main()
{
    ll n;
    cin >> n;

    while (n--)
        run();
}