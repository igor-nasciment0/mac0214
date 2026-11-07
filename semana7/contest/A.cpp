// https://codeforces.com/contest/2254/problem/A

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

void run()
{
    vector<ll> tokens(3);

    for (ll i = 0; i < 3; i++)
        cin >> tokens[i];

    ll count = 0;

    while (true)
    {
        if (tokens[0] == tokens[1] || tokens[1] == tokens[2] || tokens[0] == tokens[2])
        {
            cout << count << "\n";
            break;
        }

        sort(tokens.begin(), tokens.end());

        tokens[0]++;
        tokens[2]--;
        count++;
    }
}

int main()
{
    ll n;
    cin >> n;

    while (n--)
        run();
}