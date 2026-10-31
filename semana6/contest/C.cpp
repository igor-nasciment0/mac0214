// https://codeforces.com/contest/2275/problem/C

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // {valor da tríade, índice inicial}
    vector<pair<long long, int>> triads;

    for (int i = 0; i <= n - 5; i++) {
        long long val = a[i] + a[i + 2] - a[i + 4]; // fórmula correta
        triads.push_back({val, i});
    }

    sort(triads.begin(), triads.end());

    long long ans = 0;
    int m = (int)triads.size();

    for (int i = 0; i < m; ) {
        int j = i;

        while (j < m && triads[j].first == triads[i].first) {
            j++;
        }

        long long cnt = j - i;

        // Todos os pares com mesmo valor
        ans += cnt * (cnt - 1) / 2;

        // Subtrai os pares que compartilham chaves
        for (int k = i; k < j; k++) {
            int x = triads[k].second;
            long long val = triads[i].first;

            if (binary_search(triads.begin() + i, triads.begin() + j,
                              make_pair(val, x + 2))) {
                ans--;
            }

            if (binary_search(triads.begin() + i, triads.begin() + j,
                              make_pair(val, x + 4))) {
                ans--;
            }
        }

        i = j;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}