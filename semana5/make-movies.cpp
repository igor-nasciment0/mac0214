// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
    Here, it is enough to make a greedy algorithm that choices the next movie acording to the crescent order of end times. The proof that it works is simple: to select the first movie to watch, it is optimal to leave as much time as possible after the movie, in order to watch the maximum possible number. So, you must choose the first-ending movie. The logic repeats for the second, third, and any k-ith one.
*/

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vec(n);

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        vec[i] = {a, b};
    }
    
    sort(vec.begin(), vec.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    pair<ll, ll> last_movie = {0, 0}; 
    ll count = 0;

    for (ll i = 0; i < n; i++)
    {
        if (vec[i].first >= last_movie.second)
        {
            last_movie = vec[i];
            count++;
        }
    }
    
    cout << count << "\n";
}