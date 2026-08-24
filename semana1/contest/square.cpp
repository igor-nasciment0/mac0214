// https://codeforces.com/contest/2167/problem/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == b && b == c && c == d) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}

int main() {
    ll n;
    cin >> n;
    while(n--) {
        solve();
    }
    return 0;
}