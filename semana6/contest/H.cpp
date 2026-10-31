// https://codeforces.com/contest/2275/problem/A

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

void transforma(vector<ll>& v, int inicio, int passo, int tamanho) {
    if (tamanho % 2 == 1) {
        ll soma = 0;

        for (int k = 0; k < tamanho; k += 2) {
            soma = (soma + v[inicio + k * passo]) % MOD;
        }

        for (int k = 0; k < tamanho; ++k) {
            v[inicio + k * passo] = (k % 2 == 0 ? soma : 0);
        }

        return;
    }

    ll paresDireita = 0;

    for (int k = 1; k < tamanho; k += 2) {
        paresDireita = (paresDireita + v[inicio + k * passo]) % MOD;
    }

    ll imparesEsquerda = 0;

    for (int k = 0; k < tamanho; ++k) {
        int pos = inicio + k * passo;
        ll x = v[pos];

        if (k % 2 == 0) {
            imparesEsquerda = (imparesEsquerda + x) % MOD;
            v[pos] = (MOD - paresDireita) % MOD;
        } else {
            paresDireita = (paresDireita - x + MOD) % MOD;
            v[pos] = (MOD - imparesEsquerda) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n * m);

        for (ll& x : a) {
            cin >> x;
            x = (x % MOD + MOD) % MOD;
        }

        vector<ll> b = a;

        for (int i = 0; i < n; ++i) {
            transforma(b, i * m, 1, m);
        }

        for (int j = 0; j < m; ++j) {
            transforma(b, j, m, n);
        }

        ll resposta = 0;

        for (int k = 0; k < n * m; ++k) {
            resposta = (resposta + a[k] * b[k]) % MOD;
        }

        cout << resposta << '\n';
    }

    return 0;
}