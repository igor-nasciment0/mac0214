// https://codeforces.com/contest/1985/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll max_val = 0;
    ll sum = 0;
    max_val = a[0];
    sum = a[0];
    ll count = 0;
    if (a[0] == 0) {
        count++;
    }
    for (ll i = 1; i < n; i++) {
        sum += a[i];
        max_val = max(max_val, a[i]);
        if ((sum - max_val) == max_val) {
            count++;
        }
    }
 
    cout << count << "\n";
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