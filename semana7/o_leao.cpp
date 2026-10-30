#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void test()
{
    ll n;
    cin >> n;

    vector<ll> love(n);

    for (ll i = 0; i < n; i++)
        cin >> love[i];

    vector<pair<ll, ll>> choir_love(n - 4);

    for (ll i = 0; i < n - 4; i++)
        choir_love[i] = {love[i] + love[i + 2] + love[i + 4], i};
    
    sort(choir_love.begin(), choir_love.end());

    ll count = 0;
    ll i = 0;

    while(i < n - 4)
    {
        vector<ll> same;

        while (choir_love[i] == choir_love[i + 1])
        {
            same.push_back(i);
            i++;        
        }
        
        ll possibilidades = (same.size())*(same.size() + 1)/2;
        // possibilidades = count_initial escolhe 2
        // k <-> l : possibilidades - 1

        for(ll k = 0; k < same.size(); k++)
        {
            for (ll l = k; l < k + 4; i++)
            {
                if(same[l] == same[k] + 2 || same[l] == same[k] + 4)
                    possibilidades--;
            }
        }

        count += possibilidades;
        i += 1;
    }

    cout << count << "\n";   
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        test();
    }
}