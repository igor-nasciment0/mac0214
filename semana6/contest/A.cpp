// https://codeforces.com/contest/2275/problem/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll x0, y0, R;
    cin >> x0 >> y0 >> R;
    ll x = x0 + R;
    cout << x << " " << y0 << "\n";
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