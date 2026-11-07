// https://codeforces.com/contest/2278/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x, y, z;
    cin >> x >> y >> z;

    char maior;
    if (x >= y && x >= z) {
        maior = 'P';
    } else if (y >= x && y >= z) {
        maior = 'R';
    } else {
        maior = 'S';
    }

    for (ll i = 0; i < x + y + z; ++i) {
        cout << maior;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}