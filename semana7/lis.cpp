#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<ll> input(n);

    for (int i = 0; i < n; i++)
        cin >> input[i];

    vector<stack<ll>> stacks;

    for (size_t i = 0; i < n; i++)
    {
        ll elem = input[i];
        ll index = 0;

        for (ll k = stacks.size(); k >= 1; k /= 2)
        {
            while(index + k < stacks.size() && stacks[index + k].top() >= elem)
                index += k;
        }

        if (index == stacks.size() && stacks[index].top() < elem)
        {
            stacks.push_back(stack<ll>());
            stacks[stacks.size() - 1].push(elem);
        }
        else
            stacks[index].push(elem);
    }

    cout << stacks.size();
}