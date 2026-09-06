// https://codeforces.com/contest/2259/problem/D

// This one is incomplete: couldn't have an ideia of solution quickly enough.
// Below is a "best-effort" attempt: a greedy algorithm that just fills the sets
// hoping that that gives the right answer.

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> vec;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end());

    multiset<ll> A, B, C;

    ll mex_a = 0, mex_b = 0, mex_c = 0;

    vector<char> div;

    for (ll i = 0; i < n; i++)
    {
        ll elem = vec[i];
        bool give_up_c = false;

        if (i % 3 == 2 && !give_up_c)
        {
            if (elem == mex_c)
            {
                mex_c++;
                div.push_back('C');
            }
            else
                give_up_c = true;
        }

        if (i % 3 == 0 || (i % 2 == 0 && give_up_c))
        {
            if (elem == mex_a)
                mex_a++;
            div.push_back('A');
        }

        if (i % 3 == 1 || (i % 2 == 1 && give_up_c))
        {
            if (elem == mex_b)
                mex_b++;
            div.push_back('B');
        }
    }

    if (mex_a + mex_b + mex_c >= max(max(mex_a, mex_b), mex_c) * 2)
    {
        cout << "YES" << "\n";
        for (auto c : div)
            cout << c;
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}