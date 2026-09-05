// https://cses.fi/problemset/task/2428

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ll n, k;

    cin >> n >> k;

    vector<ll> vec;

    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        vec.push_back(a);
    }

    ll i = 0, j = 0;
    unordered_map<ll, ll> count; // current subarray elements counting
    ll subarray_num = 0;

    while (j < n)
    {
        ll new_element = vec[j];
        
        if (count.size() < k || count.find(new_element) != count.end())
        {
            j++;
            subarray_num += j - i;

            if (count.find(new_element) != count.end())
                count[new_element]++;
            else
                count.insert({new_element, 1});
        }
        else
        {
            while (count.size() == k)
            {
                ll remove_element = vec[i++];

                if (count[remove_element] > 1)
                    count[remove_element]--;
                else
                    count.erase(remove_element);
            }
        }
    }

    cout << subarray_num << "\n";

    return 0;
}