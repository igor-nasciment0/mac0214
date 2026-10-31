// https://cses.fi/problemset/task/1140

/*
suponhamos que p_1...p_n estão ordenados pelo dia de começo

seja t[i] = max_valor{p_i, ..., p_n}. vale que:

t[n] = valor(p_n)
t[i] = max( t[i + 1], valor(p_i) + t[k] )

onde k é o menor índice tal que comeco(p_k) > final(p_i)
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<tuple<ll, ll, ll>> projects;

    for (ll i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        projects.push_back({a, b, c});
    }

    sort(projects.begin(), projects.end());

    vector<ll> t(n);
    t[n - 1] = get<2>(projects[n - 1]);

    for (ll i = n - 2; i >= 0; i--)
    {
        ll k = i;

        for (ll j = (n - i)/2; j >= 1; j /= 2)
        {
            while (k + j < n && get<0>(projects[k + j]) <= get<1>(projects[i]))
                k = k + j;
        }

        k++;
        t[i] = max(t[i + 1], get<2>(projects[i]) + t[k]);
    }

    cout << t[0] << "\n";
}