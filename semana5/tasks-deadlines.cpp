// https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
    Sejam X e Y tasks com tempos Tx e Ty, com Tx >= Ty.

    Seja P a quantidade de pontos feita ao realizar X, e depois Y.

    Se trocarmos a ordem para Y -> X, acabaremos Y Tx mais cedo, e X Ty mais tarde.
        
    Portanto, nossa pontuação na nova ordem será P + Tx - Ty >= P (dado Tx >= Ty).

    Então as tasks devem ser feitas em ordem crescente das durações.
*/

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>> vec;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end());

    ll score = 0;
    ll current_time = 0;

    for (auto &task : vec)
    {
        current_time += task.first;
        score += (task.second - current_time);
    }
    
    cout << score << "\n";
}