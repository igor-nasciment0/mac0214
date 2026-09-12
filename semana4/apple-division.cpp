// https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll total_sum = 0;
ll minimum;
vector<ll> vec;

void search_subset(ll curr_n, ll curr_sum)
{
    if (curr_n == n)
    {
        ll diff = abs(curr_sum - (total_sum - curr_sum));

        if (diff < minimum)
            minimum = diff;
    }
    else
    {
        // sem o elemento curr_n
        search_subset(curr_n + 1, curr_sum);

        // com o elemento curr_n
        search_subset(curr_n + 1, curr_sum + vec[curr_n]);
    }
}

int main()
{
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        total_sum += a;
        vec.push_back(a);
    }

    minimum = total_sum;
    search_subset(0, 0);

    cout << minimum << "\n";

    return 0;
}