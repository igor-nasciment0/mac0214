// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ll n, x;

    cin >> n >> x;
    
    map<ll, ll> pos;
    
    pair<ll, ll> result = {-1, -1};

    for(ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
    
        if (pos.count(x - a) == 1)
        {
            result = {i + 1, pos[x - a] + 1};
            break;
        }

        pos.insert({a, i});
    }

    if (result.first == -1 && result.second == -1)
        cout << "IMPOSSIBLE";
    else
        cout << result.first << " " << result.second;    

    return 0;
}