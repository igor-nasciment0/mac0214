// https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    For this one, it was necessary to adjust the "scarcity" criteria the greedy approach manages.

    Here, we need to ensure the club members pass the least possible time without watching. To that end, for each new movie, this version of the code always pick up the club member whose free time starts the most closely possible of the movie's beginning time. This ensures the minium ociosity.
*/

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> movies;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        movies.push_back({a, b});
    }

    sort(movies.begin(), movies.end(), [](auto &a, auto &b)
         { return a.second < b.second; });

    multiset<ll> club_endings;

    for (ll i = 0; i < k; i++)
        club_endings.insert(0);

    ll count = 0;

    for (ll i = 0; i < n; i++)
    {
        auto movie = movies[i];
        auto guy = club_endings.upper_bound(movie.first);

        if (guy == club_endings.begin())
            continue;

        guy = prev(guy);

        count++;
        club_endings.erase(guy);
        club_endings.insert(movie.second);
    }

    cout << count << "\n";
}