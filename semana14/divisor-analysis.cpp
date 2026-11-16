// https://cses.fi/problemset/task/2182

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;
const ll PHI = BIG - 1;

ll exponential(ll a, ll b)
{
    a %= BIG;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % BIG;
        a = (a * a) % BIG;
        b >>= 1;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    cin >> n;

    ll num = 1;
    ll sqrt_num = 1;
    ll num_factors = 1;
    ll sum_factors = 1;

    ll exp_tau = 1;
    bool halved = false;

    for (ll i = 0; i < n; i++)
    {
        ll p, e;
        cin >> p >> e;

        num_factors = (num_factors * ((e + 1) % BIG)) % BIG;

        ll p_pow_e_plus_1 = exponential(p, e + 1);
        ll numerator = (p_pow_e_plus_1 - 1 + BIG) % BIG;
        ll inv_denominator = exponential(p - 1, BIG - 2);
        ll geo_sum = (numerator * inv_denominator) % BIG;
        sum_factors = (sum_factors * geo_sum) % BIG;

        num = (num * exponential(p, e)) % BIG;
        sqrt_num = (sqrt_num * exponential(p, e / 2)) % BIG;

        if (!halved && (e + 1) % 2 == 0)
        {
            exp_tau = (exp_tau * (((e + 1) / 2) % PHI)) % PHI;
            halved = true;
        }
        else
        {
            exp_tau = (exp_tau * ((e + 1) % PHI)) % PHI;
        }
    }

    ll product_factors;
    if (halved)
        product_factors = exponential(num, exp_tau);
    else
        product_factors = exponential(sqrt_num, exp_tau);

    cout << num_factors << " " << sum_factors << " " << product_factors << "\n";
}