// https://codeforces.com/contest/2278/problem/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m;
    cin >> n >> m;

    string p, q;
    cin >> p >> q;

    bool tem_s, tem_i, tem_x;
    tem_s = tem_i = tem_x = false;

    for (ll i = 0; i < p.size(); i++) {
        if (p[i] == 's' && tem_s == false) {
            tem_s = true;
            p.erase(i, 1);
            --i;
        }
        else if (p[i] == 'i' && tem_i == false) {
            tem_i = true;
            p.erase(i, 1);
            --i;
        }
        else if (p[i] == 'x' && tem_x == false) {
            tem_x = true;
            p.erase(i, 1);
            --i;
        }

        if (tem_s && tem_i && tem_x) {
            break;
        }
    }

    if (!tem_s || !tem_i || !tem_x) {
        cout << "NO" << "\n";
        return;
    }

    if (p.size() != q.size()) {
        cout << "NO" << "\n";
        return;
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    for (ll i = 0; i < p.size(); ++i) {
        if (p[i] != q[i]) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
