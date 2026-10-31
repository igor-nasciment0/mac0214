// https://cses.fi/problemset/task/0000 
// askdjlaaad

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

void run()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll index = 1;

    for (ll i = 1; i < n - 1; i++)
    {
        if (
            (s[i - 1] == s[i + 1] && s[i - 1] != s[i]) 
            || s[index] == s[index - 1] 
            || s[index] == s[index + 1]
        )
            index = i;
    }

    s.erase(index, 1);

    ll compress_length = 0;
    char current_char = '#';

    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] != current_char)
        {
            compress_length++;
            current_char = s[i];
        }
    }

    cout << compress_length << "\n";
}

int main()
{
    ll n;
    cin >> n;

    while (n--)
        run();
}