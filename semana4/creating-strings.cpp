// https://vjudge.net/problem/CSES-1622

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;

unordered_map<char, ll> counting;
vector<char> current_permutation;
vector<string> permutations;
ll n_permuts = 0;

void generate()
{
    if (current_permutation.size() == N)
    {
        n_permuts++;
        string s = "";

        for (auto &c : current_permutation)
            s += c;

        permutations.push_back(s);
    }
    else
    {
        for (auto &c : counting)
        {
            if (c.second <= 0)
                continue;

            current_permutation.push_back(c.first);
            c.second--;
            generate();

            current_permutation.pop_back();
            c.second++;
        }
    }
}

int main()
{
    string s;
    cin >> s;

    N = s.size();

    for (ll i = 0; i < N; i++)
    {
        char a = s[i];

        if (counting.count(a))
            counting[a]++;
        else
            counting.insert({a, 1});
    }

    generate();

    cout << n_permuts << "\n";

    sort(permutations.begin(), permutations.end());

    for (auto s : permutations)
        cout << s << "\n";

    return 0;
}