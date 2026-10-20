// https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = pow(10, 9) + 7;

int main()
{
    ll n;
    cin >> n;

    vector<vector<bool>> has_trap(n, vector<bool>(n));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            has_trap[i][j] = c == '*';
        }
    }

    vector<vector<ll>> num_paths(n, vector<ll>(n));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll num = 0;

            if (i == 0 && j == 0)
                num = 1;

            if (i != 0)
                num += num_paths[i - 1][j];

            if (j != 0)
                num += num_paths[i][j - 1];

            if (has_trap[i][j])
                num = 0;

            num_paths[i][j] = num % BIG;
        }
    }

    cout << num_paths[n - 1][n - 1] << "\n";
}