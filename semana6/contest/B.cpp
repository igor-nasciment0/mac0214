// https://codeforces.com/contest/2275/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    stack<ll> pilha;

    for (ll i = 0; i < n; i++) {
        char c = s[i];

        if (c == '1') {
            pilha.push(i + 1);
        }
        else if (c == '2') {
            if (!pilha.empty()) {
                pilha.pop();
            }
        }
    }

    vector<ll> res;

    while (!pilha.empty()) {
        ll current = pilha.top();
        pilha.pop();
        res.push_back(current);
    }

    reverse(res.begin(), res.end());

    cout << res.size() << "\n";

    for (ll x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}