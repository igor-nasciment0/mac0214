// https://codeforces.com/contest/2275/problem/D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> A, B, C;

bool check(ll S) {
    ll total_ops = 0;
    for (ll i = 0; i < n; i++) {
        ll a = A[i], b = B[i], c = C[i];
        ll S0 = a + b + c;
        
        if (S <= S0) continue;
        
        if (a == b && b == c) return false;
        
        ll custo;
        if (a <= b && b <= c) {
            ll C1 = b - a + 1;
            ll C2 = c - b + 1;
            ll minC = min(C1, C2);
            
            custo = (S - S0) + 2 * minC;
        } else {
            custo = S - S0;
        }
        
        total_ops += custo;
        if (total_ops > k) return false; 
    }
    return total_ops <= k;
}

void solve() {
    cin >> n >> k;
    A.resize(n);
    B.resize(n);
    C.resize(n);
    
    ll min_sum = 4000000000000000000LL;
    
    for (ll i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i];
        min_sum = min(min_sum, A[i] + B[i] + C[i]);
    }
    
    ll L = min_sum;
    ll R = 3000000000LL + k; 
    
    ll ans = min_sum;
    
    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (check(mid)) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    
    cout << ans << "\n";
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