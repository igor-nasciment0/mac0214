// https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/*
    This version does not work, as most times we don't want the guy with most available time to pick up the current movie -- instead, we often want the one with least available time.
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

    sort(movies.begin(), movies.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    cout << "==========\n";
    for (auto m : movies)
        cout << m.first << ": " << m.second << "\n";


    auto comp = [](const pair<ll,ll> &a, const pair<ll,ll> &b) {
        return a.second > b.second;
    };

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, decltype(comp)> club(comp);
    
    for (ll i = 0; i < k; i++)
        club.push({0, 0});    

    ll count = 0;

    for (ll i = 0; i < n; i++)
    {
        auto movie = movies[i];
        auto guy = club.top();
    
        if (guy.second <= movie.first)
        {
            count++;
            guy.first = movie.first;
            guy.second = movie.second;
            club.pop();
            club.push(guy);
        }
    }
    
    cout << count << "\n";
}