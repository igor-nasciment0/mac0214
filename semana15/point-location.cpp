// https://cses.fi/problemset/task/2189

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        vector<ll> p1(2);
        vector<ll> p2(2);
        vector<ll> p3(2);

        cin >> p1[0] >> p1[1];
        cin >> p2[0] >> p2[1];
        cin >> p3[0] >> p3[1];

        vector<ll> p1p2 = {p2[0] - p1[0], p2[1] - p1[1]};
        vector<ll> p2p3 = {p3[0] - p2[0], p3[1] - p2[1]};

        ll cross = p1p2[0] * p2p3[1] - p1p2[1] * p2p3[0];

        if(cross < 0)
            cout << "RIGHT\n";
        else if(cross > 0)
            cout << "LEFT\n";
        else
            cout << "TOUCH\n";
    }
}