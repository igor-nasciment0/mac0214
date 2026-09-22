// https://codeforces.com/contest/1985/problem/F

#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 
void solve()
{
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll,ll,ll>>> attacks;
 
    vector<ll> a;
    vector<ll> c;
 
    ll h,n;
 
    cin >> h >> n;
 
    for (ll i = 0; i < n; i++)
    {
        ll input;
        cin >> input;
        a.push_back(input);
    }
 
    for (ll i = 0; i < n; i++)
    {
        ll input;
        cin >> input;
        c.push_back(input);
    }
 
 
    for (ll i = 0; i < n; i++)
        attacks.push({0, a[i], c[i]});
 
    ll time = 0;
 
    while(true)
    {
        auto attack = attacks.top();
        attacks.pop();
 
        h = h - get<1>(attack);
 
        if(h <= 0)
        {
            time = get<0>(attack);
            break;
        }
        else
        {
            attacks.push({get<0>(attack) + get<2>(attack), get<1>(attack), get<2>(attack)});
        }
    }
 
    cout << time + 1 << "\n";
}
 
 
int main()
{
    ll t;
    cin >> t;
 
    while(t--)
        solve();
}