// https://atcoder.jp/contests/dp/tasks/dp_f?lang=en

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll BIG = 1e9 + 7;

/*
    let dp[i][j] = lcs of s[0..i] and t[0..j].

    then

    dp[0][0] = 1 if s[0] == t[0] else 0

    dp[i][j] = dp[i - 1][j - 1] + 1,            if s[i] == t[j]
    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]), if s[i] != t[j]
*/

ll get_vec_value(vector<vector<ll>> &vec, ll i, ll j)
{
    if (i < 0 || j < 0)
        return 0;
    else
        return vec[i][j];
}

enum class Direction
{
    UP,
    LEFT,
    DIAGONAL
};

int main()
{
    string s, t;
    cin >> s >> t;

    vector<vector<ll>> dp(s.length() + 1, vector<ll>(t.length() + 1));
    vector<vector<Direction>> recall(s.length() + 1, vector<Direction>(t.length() + 1));

    dp[0][0] = s[0] == t[0] ? 1 : 0;

    for (ll i = 0; i < s.length(); i++)
    {
        for (ll j = 0; j < t.length(); j++)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = get_vec_value(dp, i - 1, j - 1) + 1;
                recall[i][j] = Direction::DIAGONAL;
            }
            else
            {
                if(get_vec_value(dp, i - 1, j) > get_vec_value(dp, i, j - 1))
                {
                    dp[i][j] = get_vec_value(dp, i - 1, j);
                    recall[i][j] = Direction::LEFT;
                }
                else
                {
                    dp[i][j] = get_vec_value(dp, i, j - 1);
                    recall[i][j] = Direction::UP;
                }
            }
        }
    }

    ll i = s.length() - 1, j = t.length() - 1;
    string result = "";
    
    while(i >= 0 && j >= 0)
    {
        if (recall[i][j] == Direction::DIAGONAL)
        {
            result += s[i];
            i--;
            j--;
        }
        else if (recall[i][j] == Direction::LEFT)
            i--;
        else
            j--;
    }

    reverse(result.begin(), result.end());
    cout << result << "\n";
}