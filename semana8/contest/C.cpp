// https://codeforces.com/contest/2278/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n; 
    ll soma = 0; 
    bool maiorq2 = false; 
    vector<ll> v(n);
    for (ll i =0; i<n; i++) {
        cin >> v[i];
        soma+=v[i];
    }

    if (n == 2) {
        if (v[0]>= 2 || v[1]>= 2)
            cout << soma - 1 <<"\n"; 
        else 
            cout << -1 << "\n";
        return; 
    } 


    for (ll i=1; i< n-1; i++){
        if (v[i]>=2){
            maiorq2 = true; 
            break; }
    }
    if (maiorq2) {
        cout << soma - 1 << "\n"; 
    } 

    else { 
        if (v[0]>= 2 || v[n-1]>= 2) {
            cout << soma - (n - 1) << "\n";
        }
        else 
            {cout << "-1" << "\n";}
    }

    
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}