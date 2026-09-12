// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void search(int row);

set<pair<ll, ll>> reserv;
vector<bool> column(8);
vector<bool> diag1(15);
vector<bool> diag2(15);

ll N = 8;
ll counting = 0;

int main()
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            char c;
            cin >> c;

            if (c == '*')
                reserv.insert({i, j});
        }
    }

    search(0);

    cout << counting << "\n";
}

void search(int row)
{
    if (row == N)
    {
        counting++;
        return;
    }

    for (ll c = 0; c < N; c++)
    {
        if (reserv.find({row, c}) != reserv.end())
            continue;
        if (column[c] || diag1[c - row + (N - 1)] || diag2[c + row])
            continue;

        column[c] = diag1[c - row + (N - 1)] = diag2[c + row] = true;

        search(row + 1);

        column[c] = diag1[c - row + (N - 1)] = diag2[c + row] = false;
    }
}