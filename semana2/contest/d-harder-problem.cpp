// https://codeforces.com/contest/2044/problem/D

    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    void solve() {
        ll INF = 1e9;
     
        ll n;
        cin >> n;
     
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            ll current;
            cin >> current;
            a[i] = current;
        }
     
        unordered_set<ll> naofoi;
        for (ll i = 1; i <= n; i++) {
            naofoi.insert(i);
        }
     
        unordered_set<ll> jafoi;
     
        vector<ll> b;
     
        for (ll i = 0; i < n; i++) {
            ll current = a[i];
            if (jafoi.count(current)) {
                b.push_back(0);
            }
            else {
                b.push_back(current);
                naofoi.erase(current);
                jafoi.insert(current);
            }
        }
     
        for (ll i = 0; i < n; i++) {
            if (b[i] == 0) {
                b[i] = *naofoi.begin();
                naofoi.erase(*naofoi.begin());
            }
        }
     
        for (ll i = 0; i < n; i++) {
            cout << b[i] << " ";
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

