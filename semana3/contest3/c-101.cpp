// https://codeforces.com/contest/2259/problem/C

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> vec;

    bool between_ones = false;

    for (ll i = 0; i < n; i++)
    {
        ll in;
        cin >> in;
        vec.push_back(in);
    }

    ll last_m1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (vec[i] == -1 || vec[i] == 1)
        {
            last_m1 = i;        
            break;
        }
    }    

    vector<ll> result;

    for (ll i = 0; i < n; i++)
    {
        ll in = vec[i];

        switch (in)
        {
        case 0:
            result.push_back(0);
            break;
        case 1:
            result.push_back(1);
            if(!between_ones) between_ones = true;
            break;
        case -1:
            if (between_ones && i != last_m1)
                result.push_back(0);
            else
            {
                result.push_back(1);
                between_ones = true;
            }

        default:
            break;
        }
    }

    for (auto m : result)
        cout << m << " ";
    cout << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}