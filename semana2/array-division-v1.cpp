// https://cses.fi/problemset/task/1085

// The greedy approach here was a bad idea: making a local optimal cut once is not a guarantee that the next local optimal cut will be the best one.
// In other words, sometimes the optimal result of two cuts is not the same as the optimal result of one cut, followed by the optimal result of the other one.  

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

tuple<ull, ull, ull> find_partition(vector<ull> &vec, ull a, ull b)
{
    // returns <i, s1, s2> such that max(sum(vec[a..i)) = s1, sum(vec[i..b)) = s2) is minimal

    ull n = b - a;

    vector<ull> acc_sum_front(n);
    vector<ull> acc_sum_back(n);

    acc_sum_front[0] = vec[a];
    acc_sum_back[n - 1] = vec[b - 1];

    for (ull i = 1; i < n; i++)
    {
        acc_sum_front[i] = acc_sum_front[i - 1] + vec[a + i];
        acc_sum_back[n - i - 1] = acc_sum_back[n - i] + vec[b - i - 1];
    }

    ull opt = 0;

    for (ull c = n / 2; c >= 1; c /= 2)
    {
        while (opt + c + 1 < n && max(acc_sum_back[opt + c], acc_sum_front[opt + c - 1]) > max(acc_sum_back[opt + c + 1], acc_sum_front[opt + c]))
            opt += c;
    }

    opt++;

    return {a + opt, acc_sum_front[opt - 1], acc_sum_back[opt]};
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

    struct ComparePQ
    {
        bool operator()(const tuple<ull, ull, ull> &a, const tuple<ull, ull, ull> &b)
        {
            return get<2>(a) < get<2>(b);
        }
    };

    priority_queue<tuple<ull, ull, ull>, vector<tuple<ull, ull, ull>>, ComparePQ> pq;

    pq.push({0, n, sum});

    for (ull i = 0; i < k - 1; i++)
    {
        auto [a, b, size] = pq.top();
        pq.pop();

        auto [opt, sum_left, sum_right] = find_partition(vec, a, b);

        pq.push({a, opt, sum_left});
        pq.push({opt, b, sum_right});
    }

    cout << get<2>(pq.top()) << "\n";

    return 0;
}