// https://codeforces.com/contest/1985/problem/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    char fs1 = s1[0];
    s1[0] = s2[0];
    s2[0] = fs1;
    cout << s1 << " " << s2 << "\n";
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