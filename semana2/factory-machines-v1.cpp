// https://cses.fi/problemset/task/1620

// Although correct, this version is excessively slow for very big t.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, t;

    cin >> n >> t;

    struct ComparePQ
    {
        bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b)
        {
            return a.first * a.second > b.first * b.second;
        }
    };

    priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, ComparePQ> pq;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        pq.push({a, 1});
    }

    ll num_products = 0;
    ll total_time = 0;
    
    while(num_products < t)
    {
        auto next = pq.top();
        next.second++;
        pq.pop();
        pq.push(next);
        
        total_time = next.first * next.second;
        num_products++;
    }

    cout << total_time << "\n";
}