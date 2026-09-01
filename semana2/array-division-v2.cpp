// https://cses.fi/problemset/task/1085

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool is_max_possible(ull target, vector<ull> &vec, ull k)
{
    ull current_sum = 0;
    ull divs = 1;

    bool is_possible = true;

    for (ull i = 0; i < vec.size(); i++)
    {
        if (current_sum + vec[i] <= target)
            current_sum += vec[i];
        else
        {
            divs++;
            current_sum = vec[i];
        }

        if (divs > k || vec[i] > target)
        {
            is_possible = false;
            break;
        }
    }

    return is_possible;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ull n, k;

    cin >> n >> k;

    vector<ull> vec(n);
    ull sum = 0;

    for (ull i = 0; i < n; i++)
    {
        ull a;
        cin >> a;
        vec[i] = a;
        sum += a;
    }

    ull max_sum = 0;

    for (ull b = sum / 2; b >= 1; b /= 2)
    {
        while (!is_max_possible(max_sum, vec, k) && !is_max_possible(max_sum + b, vec, k))
            max_sum += b;
    }

    std::cout << max_sum + 1;

    return 0;
}