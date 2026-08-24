// https://codeforces.com/contest/2167/problem/D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    vector<ll> a;
    for (ll i = 0; i < n; i++) {
        ll current;
        cin >> current;
        a.push_back(current);
    }

    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

    for (auto primo : primes) {
        for (auto ai : a) {
            if (gcd(ai, primo) == 1) {
                cout << primo << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
    return;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}