// https://codeforces.com/contest/2167/problem/c

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(vector<ll> &input) {
    bool there_is_odd = false;
    bool there_is_even = false;

    for (ll i = 0; i < input.size(); i++)
    {
        if(input[i] % 2 == 0)
            there_is_even = true;
        else
            there_is_odd = true;

        if(there_is_even && there_is_odd)
        {
            sort(input.begin(), input.end());
            return;
        }
    }
}

int main() {
    ll q;
    cin >> q;    

    while(q--) {
        ll n;
        cin >> n;
        vector<ll> input(n);

        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            input[i] = a;
        }

        solve(input);

        for (ll i = 0; i < n; i++)
        {
            cout << input[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}