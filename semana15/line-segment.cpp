// https://cses.fi/problemset/task/2190

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

ll cross_product(vector<ll> s1, vector<ll> s2, vector<ll> p1, vector<ll> p2)
{
    // returns cross product between vectors defined by s2 -s1 and p2 - p1

    vector<ll> s1s2 = {s2[0] - s1[0], s2[1] - s1[1]};
    vector<ll> p1p2 = {p2[0] - p1[0], p2[1] - p1[1]};

    return s1s2[0] * p1p2[1] - s1s2[1] * p1p2[0];
}

bool on_segment(vector<ll> s1, vector<ll> s2, vector<ll> p)
{
    return cross_product(s1, s2, s1, p) == 0 &&
           min(s1[0], s2[0]) <= p[0] && p[0] <= max(s1[0], s2[0]) &&
           min(s1[1], s2[1]) <= p[1] && p[1] <= max(s1[1], s2[1]);
}

int sgn(ll x) { return (x > 0) - (x < 0); }

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        vector<ll> s1(2), s2(2), p1(2), p2(2);

        cin >> s1[0] >> s1[1];
        cin >> s2[0] >> s2[1];
        cin >> p1[0] >> p1[1];
        cin >> p2[0] >> p2[1];

        int d1 = sgn(cross_product(s1, s2, s1, p1));
        int d2 = sgn(cross_product(s1, s2, s1, p2));
        int d3 = sgn(cross_product(p1, p2, p1, s1));
        int d4 = sgn(cross_product(p1, p2, p1, s2));

        if ((d1 * d2 < 0 && d3 * d4 < 0) ||
            on_segment(s1, s2, p1) || on_segment(s1, s2, p2) ||
            on_segment(p1, p2, s1) || on_segment(p1, p2, s2))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}