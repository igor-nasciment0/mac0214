// https://codeforces.com/contest/2278/problem/D

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    ll mediana = a[n / 2];
    ll custo = 0;

    for (ll x : a) {
        custo += abs(x - mediana);
    }

    ll operacoes = a.back() - a.front();

    cout << custo << ' ' << operacoes << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}