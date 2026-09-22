// https://codeforces.com/contest/1985/problem/D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> matriz(n);
 
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char current;
            cin >> current;
            matriz[i].push_back(current);
        }
    }
 
    ll topo_x = -1;
    ll topo_y = -1;
    bool achou_topo = false;
 
    for (ll j = 0; j < m; j++) {
        for (ll i = 0; i < n; i++) {
            if (!achou_topo) {
                if (matriz[i][j] == '#') {
                    topo_x = i;
                    topo_y = j;
                    achou_topo == true;
                }
            }
            if (achou_topo) {
                break;
            }
        }
        if (achou_topo) {
            break;
        }
    }
 
    ll topo_y_aux = topo_y - 1;
    while (matriz[topo_x][topo_y_aux--] == '#') {
        continue;
    }
    ll diametro = topo_y - topo_y_aux + 1;
    ll raio = diametro/2;
 
    ll pos_x = topo_x;
    ll pos_y = topo_y - raio + 1;
 
    cout << pos_x + 1 << " " << pos_y + 1 << "\n";
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