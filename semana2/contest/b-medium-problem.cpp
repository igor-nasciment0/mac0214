// https://codeforces.com/contest/2044/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    string s;
    cin >> s;
    string copy;
 
    for (ll i = 0; i < s.size(); i++) {
        char current = s[i];
        if (current == 'p') {
            current = 'q';
        }
        else if (current == 'q') {
            current = 'p';
        }
        copy.push_back(current);
    }
 
    reverse(copy.begin(), copy.end());
 
    for (ll i = 0; i < copy.size(); i++) {
        cout << copy[i];
    }
 
    cout << "\n";
}
 
int main() {
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}