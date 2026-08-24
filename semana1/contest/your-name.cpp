// https://codeforces.com/contest/2167/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    unordered_map<char, ll> mapa;
    for (auto c : s) {
        if (mapa.count(c) == 0) {
            mapa.insert({c, 1});
        }
        else {
            mapa.at(c) = mapa.at(c) + 1;
        }
    }

    bool res = 1;

    for (auto c : t) {
        if (mapa.count(c) == 0 || mapa.at(c) == 0) {
            res = 0;
            break;
        }
        else {
            mapa.at(c) = mapa.at(c) - 1;
        }
    }

    if (res == 1) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}

int main() {
    ll q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}