// https://codeforces.com/contest/2044/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll m, a, b, c;
    cin >> m >> a >> b >> c;
    ll macacos_A = min(m, a);
    ll macacos_B = min(m, b);
    ll macacos_livre_A = min(m - macacos_A, c);
    ll macacos_livre_B = min(m - macacos_B, c - macacos_livre_A);
 
    ll total = macacos_A + macacos_B + macacos_livre_A + macacos_livre_B;
    cout << total << "\n";
}
 
int main() {
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}